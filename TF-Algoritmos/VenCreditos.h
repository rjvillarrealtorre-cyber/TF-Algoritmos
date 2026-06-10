#pragma once
#include "MenuC.h"

namespace TFAlgoritmos {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de VenCreditos
	/// </summary>
	public ref class VenCreditos : public System::Windows::Forms::Form
	{
	public:
		VenCreditos(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			gr = CreateGraphics();
			buffer = BufferedGraphicsManager::Current->Allocate(gr, ClientRectangle);
			menu = gcnew MenuC(gcnew Bitmap("sprites\\menu\\creditos.png"));

			btnRegresar = Rectangle(392, 489, 248, 48);
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~VenCreditos()
		{
			if (components)
			{
				delete components;
			}
			delete gr;
			delete buffer;
			delete menu;
		}

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		Graphics^ gr;
		BufferedGraphics^ buffer;
		MenuC^ menu;

		Rectangle btnRegresar;
		
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->SuspendLayout();
			// 
			// VenCreditos
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1024, 576);
			this->Name = L"VenCreditos";
			this->Text = L"VenCreditos";
			this->Load += gcnew System::EventHandler(this, &VenCreditos::VenCreditos_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &VenCreditos::VenMenu_Paint);
			this->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &VenCreditos::VenCreditos_MouseClick);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void VenCreditos_Load(System::Object^ sender, System::EventArgs^ e) {
		Invalidate();
	}

	private: System::Void VenMenu_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		menu->mostrarFondo(buffer->Graphics);
		buffer->Render();
	}


	private: System::Void VenCreditos_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		Point p(e->X, e->Y);

		if (btnRegresar.Contains(p)) {
			this->Close();
		}
	}
	};
}
