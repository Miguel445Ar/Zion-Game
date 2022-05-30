#pragma once
#include "MenuCreditos.h"
#include "MyJuego.h"

namespace MenuPrincipal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyPantallaPrincipal : public System::Windows::Forms::Form
	{
		   MenuCreditos^ credits;
		   MenuHistoria^ history;
		   int ALIADOS, VIDAS, TIEMPO;
	private: System::Windows::Forms::Button^ btn_volver;
	private: System::Windows::Forms::PictureBox^ img_cantalia;
	private: System::Windows::Forms::NumericUpDown^ num_aliados;
	private: System::Windows::Forms::Button^ btn_start;
	private: System::Windows::Forms::PictureBox^ pB_tiempoJuego;
	private: System::Windows::Forms::PictureBox^ pB_cantidadVidas;



	private: System::Windows::Forms::NumericUpDown^ num_tiempoJuego;
	private: System::Windows::Forms::NumericUpDown^ num_cantVidas;
	private: System::Windows::Forms::Button^ btn_inicarJuego;
		   Graphics^ g;
	public:
		MyPantallaPrincipal(void)
		{
			
			InitializeComponent();
			PlaySound(TEXT("musica\\musica_pantallaprincipal.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
			g = this->CreateGraphics();
			credits = gcnew MenuCreditos();
			history = gcnew MenuHistoria();

			btn_volver->Hide();
		}

	protected:
		~MyPantallaPrincipal()
		{
			if (components)
			{
				delete components;
			}
			delete credits;
			delete history;
		}
	private: System::Windows::Forms::PictureBox^ img_MenuPrincipal;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ iniciar_juego;
	private: System::ComponentModel::IContainer^ components;



	protected:

	protected:

	protected:

	private:


#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyPantallaPrincipal::typeid));
			this->img_MenuPrincipal = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->iniciar_juego = (gcnew System::Windows::Forms::Button());
			this->btn_volver = (gcnew System::Windows::Forms::Button());
			this->img_cantalia = (gcnew System::Windows::Forms::PictureBox());
			this->num_aliados = (gcnew System::Windows::Forms::NumericUpDown());
			this->btn_start = (gcnew System::Windows::Forms::Button());
			this->pB_tiempoJuego = (gcnew System::Windows::Forms::PictureBox());
			this->pB_cantidadVidas = (gcnew System::Windows::Forms::PictureBox());
			this->num_tiempoJuego = (gcnew System::Windows::Forms::NumericUpDown());
			this->num_cantVidas = (gcnew System::Windows::Forms::NumericUpDown());
			this->btn_inicarJuego = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->img_MenuPrincipal))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->img_cantalia))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->num_aliados))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pB_tiempoJuego))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pB_cantidadVidas))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->num_tiempoJuego))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->num_cantVidas))->BeginInit();
			this->SuspendLayout();
			// 
			// img_MenuPrincipal
			// 
			this->img_MenuPrincipal->BackColor = System::Drawing::Color::Transparent;
			this->img_MenuPrincipal->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->img_MenuPrincipal->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->img_MenuPrincipal->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"img_MenuPrincipal.Image")));
			this->img_MenuPrincipal->Location = System::Drawing::Point(0, 0);
			this->img_MenuPrincipal->Name = L"img_MenuPrincipal";
			this->img_MenuPrincipal->Size = System::Drawing::Size(1024, 751);
			this->img_MenuPrincipal->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->img_MenuPrincipal->TabIndex = 0;
			this->img_MenuPrincipal->TabStop = false;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Transparent;
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->button1->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Location = System::Drawing::Point(333, 512);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(330, 65);
			this->button1->TabIndex = 1;
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyPantallaPrincipal::button1_Click);
			// 
			// iniciar_juego
			// 
			this->iniciar_juego->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"iniciar_juego.BackgroundImage")));
			this->iniciar_juego->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->iniciar_juego->Cursor = System::Windows::Forms::Cursors::Hand;
			this->iniciar_juego->FlatAppearance->BorderSize = 0;
			this->iniciar_juego->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->iniciar_juego->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->iniciar_juego->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->iniciar_juego->Location = System::Drawing::Point(307, 418);
			this->iniciar_juego->Name = L"iniciar_juego";
			this->iniciar_juego->Size = System::Drawing::Size(381, 67);
			this->iniciar_juego->TabIndex = 2;
			this->iniciar_juego->UseVisualStyleBackColor = true;
			this->iniciar_juego->Click += gcnew System::EventHandler(this, &MyPantallaPrincipal::iniciar_juego_Click);
			// 
			// btn_volver
			// 
			this->btn_volver->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_volver.BackgroundImage")));
			this->btn_volver->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_volver->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_volver->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_volver->Location = System::Drawing::Point(22, 24);
			this->btn_volver->Name = L"btn_volver";
			this->btn_volver->Size = System::Drawing::Size(164, 82);
			this->btn_volver->TabIndex = 3;
			this->btn_volver->UseVisualStyleBackColor = true;
			this->btn_volver->Click += gcnew System::EventHandler(this, &MyPantallaPrincipal::btn_volver_Click);
			// 
			// img_cantalia
			// 
			this->img_cantalia->BackColor = System::Drawing::Color::Black;
			this->img_cantalia->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->img_cantalia->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"img_cantalia.Image")));
			this->img_cantalia->Location = System::Drawing::Point(57, 409);
			this->img_cantalia->Name = L"img_cantalia";
			this->img_cantalia->Size = System::Drawing::Size(285, 76);
			this->img_cantalia->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->img_cantalia->TabIndex = 5;
			this->img_cantalia->TabStop = false;
			this->img_cantalia->Visible = false;
			// 
			// num_aliados
			// 
			this->num_aliados->Font = (gcnew System::Drawing::Font(L"Silver", 18.27692F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(254)));
			this->num_aliados->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->num_aliados->Location = System::Drawing::Point(137, 512);
			this->num_aliados->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->num_aliados->Name = L"num_aliados";
			this->num_aliados->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->num_aliados->Size = System::Drawing::Size(120, 44);
			this->num_aliados->TabIndex = 6;
			this->num_aliados->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->num_aliados->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->num_aliados->Visible = false;
			this->num_aliados->ValueChanged += gcnew System::EventHandler(this, &MyPantallaPrincipal::num_aliados_ValueChanged);
			// 
			// btn_start
			// 
			this->btn_start->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->btn_start->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_start.BackgroundImage")));
			this->btn_start->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_start->FlatAppearance->BorderSize = 0;
			this->btn_start->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_start->Location = System::Drawing::Point(422, 598);
			this->btn_start->Name = L"btn_start";
			this->btn_start->Size = System::Drawing::Size(162, 67);
			this->btn_start->TabIndex = 7;
			this->btn_start->UseVisualStyleBackColor = false;
			this->btn_start->Visible = false;
			this->btn_start->Click += gcnew System::EventHandler(this, &MyPantallaPrincipal::btn_start_Click);
			// 
			// pB_tiempoJuego
			// 
			this->pB_tiempoJuego->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pB_tiempoJuego.Image")));
			this->pB_tiempoJuego->Location = System::Drawing::Point(369, 409);
			this->pB_tiempoJuego->Name = L"pB_tiempoJuego";
			this->pB_tiempoJuego->Size = System::Drawing::Size(285, 76);
			this->pB_tiempoJuego->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pB_tiempoJuego->TabIndex = 8;
			this->pB_tiempoJuego->TabStop = false;
			this->pB_tiempoJuego->Visible = false;
			// 
			// pB_cantidadVidas
			// 
			this->pB_cantidadVidas->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pB_cantidadVidas.Image")));
			this->pB_cantidadVidas->Location = System::Drawing::Point(677, 409);
			this->pB_cantidadVidas->Name = L"pB_cantidadVidas";
			this->pB_cantidadVidas->Size = System::Drawing::Size(285, 76);
			this->pB_cantidadVidas->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pB_cantidadVidas->TabIndex = 9;
			this->pB_cantidadVidas->TabStop = false;
			this->pB_cantidadVidas->Visible = false;
			// 
			// num_tiempoJuego
			// 
			this->num_tiempoJuego->Font = (gcnew System::Drawing::Font(L"Silver", 18.27692F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(254)));
			this->num_tiempoJuego->Location = System::Drawing::Point(448, 512);
			this->num_tiempoJuego->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->num_tiempoJuego->Name = L"num_tiempoJuego";
			this->num_tiempoJuego->Size = System::Drawing::Size(120, 44);
			this->num_tiempoJuego->TabIndex = 10;
			this->num_tiempoJuego->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->num_tiempoJuego->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->num_tiempoJuego->Visible = false;
			this->num_tiempoJuego->ValueChanged += gcnew System::EventHandler(this, &MyPantallaPrincipal::num_tiempoJuego_ValueChanged);
			// 
			// num_cantVidas
			// 
			this->num_cantVidas->Font = (gcnew System::Drawing::Font(L"Silver", 18.27692F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(254)));
			this->num_cantVidas->Location = System::Drawing::Point(760, 512);
			this->num_cantVidas->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->num_cantVidas->Name = L"num_cantVidas";
			this->num_cantVidas->Size = System::Drawing::Size(120, 44);
			this->num_cantVidas->TabIndex = 11;
			this->num_cantVidas->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->num_cantVidas->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->num_cantVidas->Visible = false;
			this->num_cantVidas->ValueChanged += gcnew System::EventHandler(this, &MyPantallaPrincipal::num_cantVidas_ValueChanged);
			// 
			// btn_inicarJuego
			// 
			this->btn_inicarJuego->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_inicarJuego.BackgroundImage")));
			this->btn_inicarJuego->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_inicarJuego->FlatAppearance->BorderSize = 0;
			this->btn_inicarJuego->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_inicarJuego->Location = System::Drawing::Point(773, 652);
			this->btn_inicarJuego->Name = L"btn_inicarJuego";
			this->btn_inicarJuego->Size = System::Drawing::Size(204, 75);
			this->btn_inicarJuego->TabIndex = 12;
			this->btn_inicarJuego->UseVisualStyleBackColor = true;
			this->btn_inicarJuego->Visible = false;
			this->btn_inicarJuego->Click += gcnew System::EventHandler(this, &MyPantallaPrincipal::btn_inicarJuego_Click);
			// 
			// MyPantallaPrincipal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1024, 750);
			this->Controls->Add(this->btn_inicarJuego);
			this->Controls->Add(this->num_cantVidas);
			this->Controls->Add(this->num_tiempoJuego);
			this->Controls->Add(this->pB_cantidadVidas);
			this->Controls->Add(this->pB_tiempoJuego);
			this->Controls->Add(this->btn_start);
			this->Controls->Add(this->num_aliados);
			this->Controls->Add(this->img_cantalia);
			this->Controls->Add(this->btn_volver);
			this->Controls->Add(this->iniciar_juego);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->img_MenuPrincipal);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyPantallaPrincipal";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"TheTrickyMaze";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->img_MenuPrincipal))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->img_cantalia))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->num_aliados))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pB_tiempoJuego))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pB_cantidadVidas))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->num_tiempoJuego))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->num_cantVidas))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		img_MenuPrincipal->Hide();
		button1->Hide();
		iniciar_juego->Hide();

		credits->mostrar(g, this->ClientRectangle);
		btn_volver->Show();
	}
	private: System::Void btn_volver_Click(System::Object^ sender, System::EventArgs^ e) {
		btn_volver->Hide();
		delete credits;

		img_MenuPrincipal->Show();
		button1->Show();
		iniciar_juego->Show();
	}
	private: System::Void num_aliados_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
		ALIADOS = (int)num_aliados->Value;
	}
	private: System::Void num_cantVidas_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
		VIDAS = (int)num_cantVidas->Value;
	}
	private: System::Void num_tiempoJuego_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
		TIEMPO = (int)num_tiempoJuego->Value;
	}
	private: System::Void iniciar_juego_Click(System::Object^ sender, System::EventArgs^ e) {
		button1->Hide();
		iniciar_juego->Hide();

		img_cantalia->Show();
		num_aliados->Show();
		btn_start->Show();

		pB_cantidadVidas->Show();
		num_cantVidas->Show();
		pB_tiempoJuego->Show();
		num_tiempoJuego->Show();

	}
	private: System::Void btn_start_Click(System::Object^ sender, System::EventArgs^ e) {

		img_cantalia->Hide();
		num_aliados->Hide();
		btn_start->Hide();

		pB_cantidadVidas->Hide();
		num_cantVidas->Hide();
		pB_tiempoJuego->Hide();
		num_tiempoJuego->Hide();

		img_MenuPrincipal->Hide();
		history->mostrar(g, this->ClientRectangle);
		btn_inicarJuego->Show();
	}
private: System::Void btn_inicarJuego_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		PlaySound(NULL, NULL, 0);

		TIEMPO = (int)num_tiempoJuego->Value;
		VIDAS = (int)num_cantVidas->Value;
		ALIADOS = (int)num_aliados->Value;

		MyJuego^ Juego = gcnew MyJuego(ALIADOS, VIDAS, TIEMPO);
		Juego->ShowDialog();
		this->Close();
}
};
}
