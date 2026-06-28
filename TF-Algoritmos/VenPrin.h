#pragma once
#include <fstream>
#include <cstdint>
#include "Juego.h"

namespace TFAlgoritmos {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de VenPrin
	/// </summary>
	public ref class VenPrin : public System::Windows::Forms::Form
	{
	public:
		VenPrin(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			gr = CreateGraphics();
			buffer = BufferedGraphicsManager::Current->Allocate(gr, ClientRectangle);
			juego = gcnew Juego();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~VenPrin()
		{
			if (components)
			{
				delete components;
			}
			delete gr;
			delete buffer;
			delete juego;
		}

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		
		Graphics^ gr;
		BufferedGraphics^ buffer;
		Juego^ juego;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;



#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 75;
			this->timer1->Tick += gcnew System::EventHandler(this, &VenPrin::timer1_Tick);
			// 
			// VenPrin
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1200, 514);
			this->Name = L"VenPrin";
			this->Text = L"VenPrin";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &VenPrin::VenPrin_FormClosing);
			this->Load += gcnew System::EventHandler(this, &VenPrin::VenPrin_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &VenPrin::VenPrin_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &VenPrin::VenPrin_KeyUp);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void VenPrin_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		juego->manejarBuclePrincipal(buffer->Graphics);

		buffer->Render();
	}
	private: System::Void VenPrin_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode) {
		case Keys::Right:
			juego->getJugador()->setTDerecha(true);
			break;
		case Keys::Left:
			juego->getJugador()->setTIzquierda(true);
			break;
		case Keys::Up:
			juego->getJugador()->setTArriba(true);
			break;
		case Keys::Down:
			juego->getJugador()->setTAbajo(true);
			break;
		case Keys::E:
			juego->setTeclaE(true);
			break;
		case Keys::Q:
			juego->setTeclaQ(true);
			break;
		case Keys::D1:
			juego->setTeclaOpciones(true, 1);
			break;
		case Keys::D2:
			juego->setTeclaOpciones(true, 2);
			break;
		case Keys::D3:
			juego->setTeclaOpciones(true, 3);
			break;
		case Keys::D4:
			juego->setTeclaOpciones(true, 4);
			break;
		case Keys::Escape:
			juego->getJugador()->setTeclaEscape(true);
			break;
		}

	}
	private: System::Void VenPrin_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode) {
		case Keys::Right:
			juego->getJugador()->setTDerecha(false);
			break;
		case Keys::Left:
			juego->getJugador()->setTIzquierda(false);
			break;
		case Keys::Up:
			juego->getJugador()->setTArriba(false);
			break;
		case Keys::Down:
			juego->getJugador()->setTAbajo(false);
			break;
		case Keys::E:
			juego->setTeclaE(false);
			break;
		case Keys::Q:
			juego->setTeclaQ(false);
			break;
		case Keys::D1:
			juego->setTeclaOpciones(false, 1);
			break;
		case Keys::D2:
			juego->setTeclaOpciones(false, 2);
			break;
		case Keys::D3:
			juego->setTeclaOpciones(false, 3);
			break;
		case Keys::D4:
			juego->setTeclaOpciones(false, 4);
			break;
		case Keys::Escape:
			juego->getJugador()->setTeclaEscape(false);
			break;
		}
	}
	private: System::Void VenPrin_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		System::IO::Directory::CreateDirectory("archivos");
		// Valores a escribir
		int32_t confianza = static_cast<int32_t>(juego->getJugador()->getConfianza());
		int32_t conLengua = static_cast<int32_t>(juego->getJugador()->getConocimiento());
		int32_t evidencia = static_cast<int32_t>(juego->getJugador()->getEvidencia());
		int32_t contador = static_cast<int32_t>(juego->getContador());

		// Intentar abrir para lectura/escritura
		std::fstream fs("archivos\\Puntajes.bin", std::ios::binary | std::ios::in | std::ios::out);
		if (!fs.is_open()) {
			// si no existe, crear y escribir al final
			std::ofstream ofs("archivos\\Puntajes.bin", std::ios::binary | std::ios::app);
			if (ofs.is_open()) {
				ofs.write(reinterpret_cast<const char*>(&confianza), sizeof(confianza));
				ofs.write(reinterpret_cast<const char*>(&conLengua), sizeof(conLengua));
				ofs.write(reinterpret_cast<const char*>(&evidencia), sizeof(evidencia));
				ofs.write(reinterpret_cast<const char*>(&contador), sizeof(contador));
				ofs.close();
			}
			return;
		}

		// obtener tamaño
		fs.seekg(0, std::ios::end);
		std::streamoff size = fs.tellg();
		const std::streamoff placeholderBytes = 4 * static_cast<std::streamoff>(sizeof(int32_t));

		bool overwritten = false;
		if (size >= placeholderBytes) {
			// leer los últimos 16 bytes
			fs.seekg(size - placeholderBytes, std::ios::beg);
			int32_t tail[4] = {0,0,0,0};
			fs.read(reinterpret_cast<char*>(tail), placeholderBytes);
			if (fs) {
				bool allZero = true;
				for (int i = 0; i < 4; i++) if (tail[i] != 0) { allZero = false; break; }
				if (allZero) {
					// sobrescribir los placeholders
					fs.seekp(size - placeholderBytes, std::ios::beg);
					fs.write(reinterpret_cast<const char*>(&confianza), sizeof(confianza));
					fs.write(reinterpret_cast<const char*>(&conLengua), sizeof(conLengua));
					fs.write(reinterpret_cast<const char*>(&evidencia), sizeof(evidencia));
					fs.write(reinterpret_cast<const char*>(&contador), sizeof(contador));
					overwritten = true;
				}
			}
		}

		if (!overwritten) {
			// añadir al final
			fs.clear(); // limpiar flags
			fs.seekp(0, std::ios::end);
			fs.write(reinterpret_cast<const char*>(&confianza), sizeof(confianza));
			fs.write(reinterpret_cast<const char*>(&conLengua), sizeof(conLengua));
			fs.write(reinterpret_cast<const char*>(&evidencia), sizeof(evidencia));
			fs.write(reinterpret_cast<const char*>(&contador), sizeof(contador));
		}

		fs.close();
	}
};
}
