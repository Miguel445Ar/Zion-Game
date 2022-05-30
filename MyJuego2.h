#pragma once
#include "MC.h"
#include "Controladora.h"
#include "CEscenario.h"
#include "Movil.h"
#include "MyPantallaPerdiste.h"
#include "MyPantallaGanaste.h"
namespace MenuPrincipal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyJuego2 : public System::Windows::Forms::Form
	{
		Controladora^ NovoJogo2;
		Graphics^ graficador;

	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ lbl_vidas2;
	private: System::Windows::Forms::Label^ lbl_tiempo2;
	private: System::Windows::Forms::Label^ lbl_asesinos;

	public:
		MyJuego2(int cant_vidas, int tiempo)
		{
			srand(time(NULL));
			InitializeComponent();
			graficador = CreateGraphics();
			this->NovoJogo2 = gcnew Controladora(graficador, 12, cant_vidas, tiempo);
		}

	protected:

		~MyJuego2()
		{
			delete this->NovoJogo2;
			delete this->graficador;
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:


#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyJuego2::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->lbl_vidas2 = (gcnew System::Windows::Forms::Label());
			this->lbl_tiempo2 = (gcnew System::Windows::Forms::Label());
			this->lbl_asesinos = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyJuego2::animación_fase2);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(731, -1);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(303, 689);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// lbl_vidas2
			// 
			this->lbl_vidas2->AutoSize = true;
			this->lbl_vidas2->BackColor = System::Drawing::Color::White;
			this->lbl_vidas2->Font = (gcnew System::Drawing::Font(L"Britannic Bold", 26.03077F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_vidas2->Location = System::Drawing::Point(853, 184);
			this->lbl_vidas2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lbl_vidas2->Name = L"lbl_vidas2";
			this->lbl_vidas2->Size = System::Drawing::Size(108, 38);
			this->lbl_vidas2->TabIndex = 1;
			this->lbl_vidas2->Text = L"VIDAS";
			// 
			// lbl_tiempo2
			// 
			this->lbl_tiempo2->AutoSize = true;
			this->lbl_tiempo2->Font = (gcnew System::Drawing::Font(L"Britannic Bold", 26.03077F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_tiempo2->Location = System::Drawing::Point(853, 550);
			this->lbl_tiempo2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lbl_tiempo2->Name = L"lbl_tiempo2";
			this->lbl_tiempo2->Size = System::Drawing::Size(122, 38);
			this->lbl_tiempo2->TabIndex = 2;
			this->lbl_tiempo2->Text = L"tiempo";
			// 
			// lbl_asesinos
			// 
			this->lbl_asesinos->AutoSize = true;
			this->lbl_asesinos->BackColor = System::Drawing::Color::White;
			this->lbl_asesinos->Font = (gcnew System::Drawing::Font(L"Britannic Bold", 26.03077F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_asesinos->Location = System::Drawing::Point(853, 358);
			this->lbl_asesinos->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lbl_asesinos->Name = L"lbl_asesinos";
			this->lbl_asesinos->Size = System::Drawing::Size(93, 38);
			this->lbl_asesinos->TabIndex = 3;
			this->lbl_asesinos->Text = L"ASES";
			// 
			// MyJuego2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1028, 681);
			this->Controls->Add(this->lbl_asesinos);
			this->Controls->Add(this->lbl_tiempo2);
			this->Controls->Add(this->lbl_vidas2);
			this->Controls->Add(this->pictureBox1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"MyJuego2";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"TheTrickyMaze";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyJuego2::MyJuego2_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyJuego2::MyJuego2_KeyUp);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void animación_fase2(System::Object^ sender, System::EventArgs^ e) {

		BufferedGraphics^ buffer = BufferedGraphicsManager::Current->Allocate(graficador, this->ClientRectangle);
		BufferedGraphics ^ buffer_escenario = BufferedGraphicsManager::Current->Allocate(buffer->Graphics, this->ClientRectangle);

		buffer->Graphics->Clear(Color::White);
		buffer_escenario->Graphics->Clear(Color::White);


		NovoJogo2->Animar_escenario(buffer_escenario->Graphics);
		buffer_escenario->Render();

		if (!(NovoJogo2->Animar_fase_2(buffer->Graphics) == true)) {
			if (NovoJogo2->get_ganaste() == true) {
				timer1->Stop();
				_sleep(3000);
				this->Hide();

				PlaySound(NULL, NULL, 0);
				MyPantallaGanaste^ ganaste = gcnew MyPantallaGanaste();
				ganaste->ShowDialog();
				this->Close();

			}
			else if (NovoJogo2->get_perdiste() == true) {
				timer1->Stop();
				_sleep(3000);
				this->Hide();
				PlaySound(NULL, NULL, 0);

				MyPantallaPerdiste^ perdiste = gcnew MyPantallaPerdiste();
				perdiste->ShowDialog();
				this->Close();

			}
		}

		int vidas2 = NovoJogo2->getVIDAS_JUGADOR();
		lbl_vidas2->Text = vidas2.ToString();
		int tiempo2 = NovoJogo2->getTIME();
		lbl_tiempo2->Text = tiempo2.ToString();
		int c_asesinos = NovoJogo2->getCANT_ASSASINS();
		lbl_asesinos->Text = c_asesinos.ToString();

		buffer->Render();
	}
	private: System::Void MyJuego2_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		NovoJogo2->MoverJugador(false, e->KeyCode);
	}
	private: System::Void MyJuego2_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		NovoJogo2->MoverJugador(true, e->KeyCode);
	}
};
}
