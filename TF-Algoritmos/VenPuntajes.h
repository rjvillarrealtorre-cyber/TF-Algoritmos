#pragma once
#include "Fuente.h"
#include <fstream>
#include <cstdint>
#include <string>
#include <vector>
#include <msclr/marshal_cppstd.h>

namespace TFAlgoritmos {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de VenPuntajes
	/// </summary>
	public ref class VenPuntajes : public System::Windows::Forms::Form
	{
	public:
		VenPuntajes(void)
		{
			// Instanciar la fuente antes de inicializar los componentes para usarla en controles
			fuente = gcnew Fuente();
			InitializeComponent();
            // inicializar arreglo dinámico para entradas
			entriesCapacity = 16;
			entries = gcnew array<Tuple<String^, int, int, int, int>^>(entriesCapacity);
			entriesCount = 0;
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~VenPuntajes()
		{
			if (components)
			{
				delete components;
			}
			delete fuente;
		}

	private:
       // Añadir una entrada al arreglo dinámico, redimensionando si es necesario
		void AddEntry(Tuple<String^, int, int, int, int>^ t) {
			if (entriesCount >= entriesCapacity) {
				int newCap = entriesCapacity * 2;
				array<Tuple<String^, int, int, int, int>^>^ newArr = gcnew array<Tuple<String^, int, int, int, int>^>(newCap);
				for (int i = 0; i < entriesCount; i++) newArr[i] = entries[i];
				entries = newArr;
				entriesCapacity = newCap;
			}
			entries[entriesCount++] = t;
		}

		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;
		Fuente^ fuente;
        array<Tuple<String^, int, int, int, int>^>^ entries;
		int entriesCount;
		int entriesCapacity;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->SuspendLayout();
			// 
			// VenPuntajes
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1200, 514);
			this->Name = L"VenPuntajes";
			this->Text = L"Puntajes";
			this->Load += gcnew System::EventHandler(this, &VenPuntajes::VenPuntajes_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &VenPuntajes::VenPuntajes_Paint);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void VenPuntajes_Load(System::Object^ sender, System::EventArgs^ e) {
        // Leer el archivo binario y cargar los registros
		entriesCount = 0;
		try {
			std::ifstream ifs("archivos\\Puntajes.bin", std::ios::binary);
			if (!ifs.is_open()) return;

			while (ifs.good()) {
				uint32_t len = 0;
				ifs.read(reinterpret_cast<char*>(&len), sizeof(len));
				if (!ifs) break;

				std::string name;
				if (len > 0) {
					name.resize(len);
					ifs.read(&name[0], len);
					if (!ifs) break;
				} else {
					name = std::string();
				}

				int32_t c1, c2, c3, c4;
				ifs.read(reinterpret_cast<char*>(&c1), sizeof(c1));
				if (!ifs) break;
				ifs.read(reinterpret_cast<char*>(&c2), sizeof(c2));
				if (!ifs) break;
				ifs.read(reinterpret_cast<char*>(&c3), sizeof(c3));
				if (!ifs) break;
				ifs.read(reinterpret_cast<char*>(&c4), sizeof(c4));
				if (!ifs) break;

                String^ sname = msclr::interop::marshal_as<String^>(name);
				AddEntry(Tuple::Create(sname, (int)c1, (int)c2, (int)c3, (int)c4));
			}
			ifs.close();
		}
		catch (...) {
			// si hay error, no hacemos nada; entries puede estar vacía
		}
		this->Invalidate();
	}

	private: System::Void VenPuntajes_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		Graphics^ g = e->Graphics;
		g->Clear(Color::FromArgb(18, 18, 18)); // fondo oscuro

		// Preparar fuentes
		System::Drawing::Font^ headerFont = gcnew System::Drawing::Font(fuente->getFuenteFinal()->FontFamily, 22, FontStyle::Bold);
		System::Drawing::Font^ cellFont = gcnew System::Drawing::Font(fuente->getFuenteFinal()->FontFamily, 18, FontStyle::Regular);

		Brush^ headerBrush = gcnew SolidBrush(Color::FromArgb(240, 240, 240));
		Brush^ textBrush = gcnew SolidBrush(Color::FromArgb(230, 230, 230));
		Brush^ altBrush = gcnew SolidBrush(Color::FromArgb(28, 28, 28));
		Pen^ gridPen = gcnew Pen(Color::FromArgb(70, 70, 70));

		int marginLeft = 48;
		int marginTop = 34;
		int rowHeight = 40;
		int headerHeight = 56;

		// Column widths
		int nameW = 520;
		int colW = 140; // for each numeric column

		// Draw header background
		System::Drawing::Rectangle headerRect = System::Drawing::Rectangle(marginLeft - 8, marginTop - 8, nameW + colW * 4 + 24, headerHeight + 8);
		g->FillRectangle(gcnew SolidBrush(Color::FromArgb(36, 36, 36)), headerRect);
		g->DrawRectangle(gridPen, headerRect);

		// Column titles
		int x = marginLeft;
		int y = marginTop;
		StringFormat^ sfCenter = gcnew StringFormat();
		sfCenter->Alignment = StringAlignment::Center;
		sfCenter->LineAlignment = StringAlignment::Center;

		g->DrawString("NOMBRE", headerFont, headerBrush, RectangleF((float)x, (float)y, (float)nameW, (float)headerHeight), sfCenter);
		x += nameW;
		g->DrawString("CONFIANZA", headerFont, headerBrush, RectangleF((float)x, (float)y, (float)colW, (float)headerHeight), sfCenter);
		x += colW;
		g->DrawString("CON LENGUA", headerFont, headerBrush, RectangleF((float)x, (float)y, (float)colW, (float)headerHeight), sfCenter);
		x += colW;
		g->DrawString("EVIDENCIA", headerFont, headerBrush, RectangleF((float)x, (float)y, (float)colW, (float)headerHeight), sfCenter);
		x += colW;
		g->DrawString("CONTADOR", headerFont, headerBrush, RectangleF((float)x, (float)y, (float)colW, (float)headerHeight), sfCenter);

		// Draw rows
		x = marginLeft;
		y += headerHeight + 8;

        int maxVisible = (this->ClientSize.Height - y - 20) / rowHeight;
		int count = Math::Min(entriesCount, maxVisible);

		const double CONVERSOR_SEG = 75.0 / 1000.0; // cada frame = 75 ms

		for (int i = 0; i < count; i++) {
			int rowY = y + i * rowHeight;
			// alternate background
			if ((i % 2) == 1) {
				g->FillRectangle(altBrush, System::Drawing::Rectangle(marginLeft - 8, rowY - 4, nameW + colW * 4 + 16, rowHeight));
			}

			Tuple<String^, int, int, int, int>^ t = entries[i];
			int cx = marginLeft;
			// name left-aligned with small padding
			RectangleF nameRect = RectangleF((float)cx + 8, (float)rowY, (float)(nameW - 16), (float)rowHeight);
			g->DrawString(t->Item1, cellFont, textBrush, nameRect);
			cx += nameW;
			// numbers center
			g->DrawString(t->Item2.ToString(), cellFont, textBrush, RectangleF((float)cx, (float)rowY, (float)colW, (float)rowHeight), sfCenter);
			cx += colW;
			g->DrawString(t->Item3.ToString(), cellFont, textBrush, RectangleF((float)cx, (float)rowY, (float)colW, (float)rowHeight), sfCenter);
			cx += colW;
			g->DrawString(t->Item4.ToString(), cellFont, textBrush, RectangleF((float)cx, (float)rowY, (float)colW, (float)rowHeight), sfCenter);
			cx += colW;
			// Formatear contador a MM:SS
			int rawFrames = t->Item5;
			int totalSeconds = static_cast<int>(CONVERSOR_SEG * rawFrames);
			int segundos = totalSeconds % 60;
			int minutos = totalSeconds / 60;
			String^ timeStr = String::Format("{0:00}:{1:00}", minutos, segundos);
			g->DrawString(timeStr, cellFont, textBrush, RectangleF((float)cx, (float)rowY, (float)colW, (float)rowHeight), sfCenter);
			cx += colW;
			// grid lines
			g->DrawLine(gridPen, marginLeft - 8, rowY - 4, marginLeft - 8 + nameW + colW * 4 + 16, rowY - 4);
			g->DrawLine(gridPen, marginLeft - 8, rowY + rowHeight - 4, marginLeft - 8 + nameW + colW * 4 + 16, rowY + rowHeight - 4);
		}

        // Footer note if empty
		if (entriesCount == 0) {
			System::Drawing::Font^ noteFont = gcnew System::Drawing::Font(fuente->getFuenteFinal()->FontFamily, 16, FontStyle::Italic);
			g->DrawString("No hay puntajes registrados.", noteFont, textBrush, (float)marginLeft, (float)(y + 8));
		}

		// dispose created fonts/brushes
		delete headerFont;
		delete cellFont;
		delete headerBrush;
		delete textBrush;
		delete altBrush;
		delete gridPen;
		delete sfCenter;
	}
	};
}
