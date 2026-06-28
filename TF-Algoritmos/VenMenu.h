#pragma once

#include "VenPrin.h"
#include "VenCreditos.h"
#include "VenPuntajes.h"
#include "MenuC.h"
#include "Opciones.h"

namespace TFAlgoritmos {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de VenMenu
	/// </summary>
	public ref class VenMenu : public System::Windows::Forms::Form
	{
	public:
		VenMenu(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			gr = CreateGraphics();
			buffer = BufferedGraphicsManager::Current->Allocate(gr, ClientRectangle);
			menuPrin = gcnew MenuC(gcnew Bitmap("sprites\\menu\\principal.png"));

			//Principal
			btnJugar = System::Drawing::Rectangle(370, 265, 286, 43);
			btnPuntajes = System::Drawing::Rectangle(390, 330, 247, 43);
			btnSalir = System::Drawing::Rectangle(390, 430, 247, 43);
			btnCreditos = System::Drawing::Rectangle(389, 378, 247, 43);
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~VenMenu()
		{
			if (components)
			{
				delete components;
			}
			delete gr;
			delete buffer;
			delete menuPrin;
		}

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		Graphics^ gr;
		BufferedGraphics^ buffer;
		MenuC^ menuPrin;

		System::Drawing::Rectangle btnJugar;
		System::Drawing::Rectangle btnPuntajes;
		System::Drawing::Rectangle btnSalir;
		System::Drawing::Rectangle btnCreditos;

		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->SuspendLayout();
			// 
			// VenMenu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1024, 576);
			this->Name = L"VenMenu";
			this->Text = L"VenMenu";
			this->Load += gcnew System::EventHandler(this, &VenMenu::VenMenu_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &VenMenu::VenMenu_Paint);
			this->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &VenMenu::VenMenu_MouseClick);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void VenMenu_Load(System::Object^ sender, System::EventArgs^ e) {
		Invalidate();
	}

	private: System::Void VenMenu_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		menuPrin->mostrarFondo(buffer->Graphics);
		buffer->Render();
	}
	private: System::Void VenMenu_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		Point p(e->X, e->Y);

		if (btnJugar.Contains(p)) {
			Opciones^ opc = gcnew Opciones();

			this->Hide();

			opc->ShowDialog();

			VenPrin^ venPrin = gcnew VenPrin();
			
			venPrin->ShowDialog();
			
			this->Close();
		}
		else if (btnPuntajes.Contains(p)) {
			this->Hide();

			VenPuntajes^ ven = gcnew VenPuntajes();
			ven->ShowDialog();

			this->Show();
		}
		else if (btnCreditos.Contains(p)) {
			this->Hide();

			VenCreditos^ ven = gcnew VenCreditos();
			ven->ShowDialog();

			this->Show();
		}
		else if (btnSalir.Contains(p)) {
			this->Close();
		}
	}
	};
}