#include <fstream>
#include <cstdint>
#include <msclr/marshal_cppstd.h>
#include "Fuente.h"

namespace TFAlgoritmos {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Opciones
	/// </summary>
	public ref class Opciones : public System::Windows::Forms::Form
	{
	public:
		Opciones(void)
		{
			//
			// Instanciar la fuente antes de inicializar los controles
			//
			fuente = gcnew Fuente();

			InitializeComponent();
			//
			//TODO: agregar c?digo de constructor aqu?
			//
		}

	protected:
		/// <summary>
			/// Limpiar los recursos que se est?n usando.
			/// </summary>
		~Opciones()
		{
			if (components)
			{
				delete components;
			}
			delete fuente;
		}
	private: System::Windows::Forms::Label^ titulo;
	private: System::Windows::Forms::Label^ i_nombre;
	private: System::Windows::Forms::TextBox^ txbx_nombre;
	private: System::Windows::Forms::Label^ lbl_dificultades;
	private: System::Windows::Forms::Button^ btn_facil;
	private: System::Windows::Forms::Button^ btn_normal;
	private: System::Windows::Forms::Button^ btn_dificl;
	protected:

	protected:

	private:
		/// <summary>
		/// Variable del dise?ador necesaria.
		/// </summary>
		Fuente^ fuente;
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// M?todo necesario para admitir el Dise?ador. No se puede modificar
		/// el contenido de este m?todo con el editor de c?digo.
		/// </summary>
		void InitializeComponent(void)
		{
			this->titulo = (gcnew System::Windows::Forms::Label());
			this->i_nombre = (gcnew System::Windows::Forms::Label());
			this->txbx_nombre = (gcnew System::Windows::Forms::TextBox());
			this->lbl_dificultades = (gcnew System::Windows::Forms::Label());
			this->btn_facil = (gcnew System::Windows::Forms::Button());
			this->btn_normal = (gcnew System::Windows::Forms::Button());
			this->btn_dificl = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// Opciones (form)
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(520, 360);
			this->Name = L"Opciones";
			this->Text = L"Opciones";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->BackColor = System::Drawing::Color::FromArgb(30, 30, 30); // fondo oscuro tipo game
			this->Font = fuente->getFuenteFinal();
			// 
			// titulo
			// 
			this->titulo->AutoSize = false;
			this->titulo->Location = System::Drawing::Point(0, 12);
			this->titulo->Name = L"titulo";
			this->titulo->Size = System::Drawing::Size(520, 40);
			this->titulo->TabIndex = 0;
			this->titulo->Text = L"OPCIONES:";
			this->titulo->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->titulo->Font = fuente->getFuenteFinal();
			this->titulo->ForeColor = System::Drawing::Color::FromArgb(240, 240, 240);
			// 
			// i_nombre
			// 
			this->i_nombre->AutoSize = true;
			this->i_nombre->Location = System::Drawing::Point(80, 70);
			this->i_nombre->Name = L"i_nombre";
			this->i_nombre->Size = System::Drawing::Size(120, 18);
			this->i_nombre->TabIndex = 1;
			this->i_nombre->Text = L"Ingrese su nombre:";
			this->i_nombre->Font = fuente->getFuenteFinal();
			this->i_nombre->ForeColor = System::Drawing::Color::FromArgb(220, 220, 220);
			// 
			// txbx_nombre
			// 
			this->txbx_nombre->Location = System::Drawing::Point(80, 95);
			this->txbx_nombre->Name = L"txbx_nombre";
			this->txbx_nombre->Size = System::Drawing::Size(360, 28);
			this->txbx_nombre->TabIndex = 2;
			this->txbx_nombre->Font = fuente->getFuenteFinal();
			this->txbx_nombre->BackColor = System::Drawing::Color::FromArgb(45, 45, 45);
			this->txbx_nombre->ForeColor = System::Drawing::Color::FromArgb(235, 235, 235);
			// 
			// lbl_dificultades
			// 
			this->lbl_dificultades->AutoSize = true;
			this->lbl_dificultades->Location = System::Drawing::Point(80, 135);
			this->lbl_dificultades->Name = L"lbl_dificultades";
			this->lbl_dificultades->Size = System::Drawing::Size(130, 18);
			this->lbl_dificultades->TabIndex = 3;
			this->lbl_dificultades->Text = L"Elija la dificultad:";
			this->lbl_dificultades->Font = fuente->getFuenteFinal();
			this->lbl_dificultades->ForeColor = System::Drawing::Color::FromArgb(220, 220, 220);
			// 
			// btn_facil
			// 
			this->btn_facil->Location = System::Drawing::Point(80, 165);
			this->btn_facil->Name = L"btn_facil";
			this->btn_facil->Size = System::Drawing::Size(360, 48);
			this->btn_facil->TabIndex = 4;
			this->btn_facil->Text = L"FÁCIL";
			this->btn_facil->UseVisualStyleBackColor = false;
			this->btn_facil->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_facil->FlatAppearance->BorderSize = 3;
			this->btn_facil->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(70, 70, 70);
			this->btn_facil->BackColor = System::Drawing::Color::FromArgb(120, 110, 95); // color tipo piedra
			this->btn_facil->ForeColor = System::Drawing::Color::FromArgb(240, 240, 240);
			this->btn_facil->Font = fuente->getFuenteFinal();
			this->btn_facil->Click += gcnew System::EventHandler(this, &Opciones::btn_facil_Click);
			// 
			// btn_normal
			// 
			this->btn_normal->Location = System::Drawing::Point(80, 225);
			this->btn_normal->Name = L"btn_normal";
			this->btn_normal->Size = System::Drawing::Size(360, 48);
			this->btn_normal->TabIndex = 5;
			this->btn_normal->Text = L"NORMAL";
			this->btn_normal->UseVisualStyleBackColor = false;
			this->btn_normal->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_normal->FlatAppearance->BorderSize = 3;
			this->btn_normal->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(70, 70, 70);
			this->btn_normal->BackColor = System::Drawing::Color::FromArgb(115, 105, 90);
			this->btn_normal->ForeColor = System::Drawing::Color::FromArgb(240, 240, 240);
			this->btn_normal->Font = fuente->getFuenteFinal();
			this->btn_normal->Click += gcnew System::EventHandler(this, &Opciones::btn_normal_Click);
			// 
			// btn_dificl
			// 
			this->btn_dificl->Location = System::Drawing::Point(80, 285);
		 this->btn_dificl->Name = L"btn_dificl";
			this->btn_dificl->Size = System::Drawing::Size(360, 48);
			this->btn_dificl->TabIndex = 6;
			this->btn_dificl->Text = L"DIFÍCIL";
			this->btn_dificl->UseVisualStyleBackColor = false;
			this->btn_dificl->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_dificl->FlatAppearance->BorderSize = 3;
			this->btn_dificl->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(70, 70, 70);
			this->btn_dificl->BackColor = System::Drawing::Color::FromArgb(110, 100, 85);
			this->btn_dificl->ForeColor = System::Drawing::Color::FromArgb(240, 240, 240);
			this->btn_dificl->Font = fuente->getFuenteFinal();
			this->btn_dificl->Click += gcnew System::EventHandler(this, &Opciones::btn_dificl_Click);
			// 
			// A?adir controles al form
			// 
			this->Controls->Add(this->btn_dificl);
			this->Controls->Add(this->btn_normal);
			this->Controls->Add(this->btn_facil);
			this->Controls->Add(this->lbl_dificultades);
			this->Controls->Add(this->txbx_nombre);
			this->Controls->Add(this->i_nombre);
			this->Controls->Add(this->titulo);
			this->Load += gcnew System::EventHandler(this, &Opciones::Opciones_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Opciones_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btn_facil_Click(System::Object^ sender, System::EventArgs^ e) {
		System::IO::Directory::CreateDirectory("archivos");
		std::ofstream ofs("archivos\\Parametros.txt");
		if (ofs.is_open()) {
			ofs << 100 << std::endl;
			ofs << 12 << std::endl;
			ofs << 10 << std::endl;
			ofs << 8 << std::endl;
			ofs << 10 << std::endl;

			ofs.close();
		}

		// A?adir el nombre al final de archivos\Puntajes.bin (longitud + bytes)
		std::string name = msclr::interop::marshal_as<std::string>(this->txbx_nombre->Text);
		std::ofstream ofsbin("archivos\\Puntajes.bin", std::ios::binary | std::ios::app);
		if (ofsbin.is_open()) {
			uint32_t len = static_cast<uint32_t>(name.size());
			ofsbin.write(reinterpret_cast<const char*>(&len), sizeof(len));
			if (len > 0) ofsbin.write(name.data(), len);
			// reservar espacio para 4 ints (placeholders)
			int32_t zero = 0;
			for (int i = 0; i < 4; i++) ofsbin.write(reinterpret_cast<const char*>(&zero), sizeof(zero));
			ofsbin.close();
		}

		this->Close();
	}

	private: System::Void btn_normal_Click(System::Object^ sender, System::EventArgs^ e) {
		System::IO::Directory::CreateDirectory("archivos");
		std::ofstream ofs("archivos\\Parametros.txt");
		if (ofs.is_open()) {
			ofs << 100 << std::endl;
			ofs << 10 << std::endl;
			ofs << 10 << std::endl;
			ofs << 6 << std::endl;
			ofs << 10 << std::endl;

			ofs.close();
		}

		// A?adir el nombre al final de archivos\Puntajes.bin (longitud + bytes)
		std::string name = msclr::interop::marshal_as<std::string>(this->txbx_nombre->Text);
		std::ofstream ofsbin("archivos\\Puntajes.bin", std::ios::binary | std::ios::app);
		if (ofsbin.is_open()) {
			uint32_t len = static_cast<uint32_t>(name.size());
			ofsbin.write(reinterpret_cast<const char*>(&len), sizeof(len));
			if (len > 0) ofsbin.write(name.data(), len);
			int32_t zero = 0;
			for (int i = 0; i < 4; i++) ofsbin.write(reinterpret_cast<const char*>(&zero), sizeof(zero));
			ofsbin.close();
		}

		this->Close();
	}

	private: System::Void btn_dificl_Click(System::Object^ sender, System::EventArgs^ e) {
		System::IO::Directory::CreateDirectory("archivos");
		std::ofstream ofs("archivos\\Parametros.txt");
		if (ofs.is_open()) {
			ofs << 75 << std::endl;
			ofs << 7 << std::endl;
			ofs << 15 << std::endl;
			ofs << 4 << std::endl;
			ofs << 10 << std::endl;

			ofs.close();
		}

		// A?adir el nombre al final de archivos\Puntajes.bin (longitud + bytes)
		std::string name = msclr::interop::marshal_as<std::string>(this->txbx_nombre->Text);
		std::ofstream ofsbin("archivos\\Puntajes.bin", std::ios::binary | std::ios::app);
		if (ofsbin.is_open()) {
			uint32_t len = static_cast<uint32_t>(name.size());
			ofsbin.write(reinterpret_cast<const char*>(&len), sizeof(len));
			if (len > 0) ofsbin.write(name.data(), len);
			int32_t zero = 0;
			for (int i = 0; i < 4; i++) ofsbin.write(reinterpret_cast<const char*>(&zero), sizeof(zero));
			ofsbin.close();
		}

		this->Close();
	}
	};

}

/*
Parametros:

Vida inicial
Velocidad del jugador
Da?o recibido
N?mero de semillas
Velocidad de enemigos

*/