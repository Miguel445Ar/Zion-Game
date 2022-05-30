#pragma once
#include "MC.h"
#include "Controladora.h"
#include "CEscenario.h"
#include "Movil.h"
#include "MyDialogoAC.h"

namespace MenuPrincipal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	public ref class MyJuego : public System::Windows::Forms::Form
	{
		Controladora^ NovoJogo;

		Graphics^ graficador;
		       
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ lbl_tiempo;
	private: System::Windows::Forms::Label^ lbl_vidas;
	private: System::Windows::Forms::Label^ lbl_nAliados;
	private: System::Windows::Forms::Label^ lbl_nCorrupts;
	private: System::Windows::Forms::Label^ lbl_nAliadosCorrompidos;

	private: System::Windows::Forms::Timer^ timer_animacion;
	public:
		MyJuego(int cant_Aliados, int cant_Vidas, int cant_Tiempo)
		{
			srand(time(NULL));
			InitializeComponent();											   														
			graficador = CreateGraphics();	
			PlaySound(TEXT("musica\\musica_juego.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
			this->NovoJogo = gcnew Controladora(graficador, cant_Aliados, cant_Vidas, cant_Tiempo);
		}

	protected:

		~MyJuego()
		{
			delete this->NovoJogo;
			delete this->graficador;
			PlaySound(NULL, NULL, 0);
			if (components)
			{
				delete components;
			}

		}
	private: System::ComponentModel::IContainer^ components;
	
	protected:

	private:

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyJuego::typeid));
			this->timer_animacion = (gcnew System::Windows::Forms::Timer(this->components));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->lbl_tiempo = (gcnew System::Windows::Forms::Label());
			this->lbl_vidas = (gcnew System::Windows::Forms::Label());
			this->lbl_nAliados = (gcnew System::Windows::Forms::Label());
			this->lbl_nCorrupts = (gcnew System::Windows::Forms::Label());
			this->lbl_nAliadosCorrompidos = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// timer_animacion
			// 
			this->timer_animacion->Enabled = true;
			this->timer_animacion->Tick += gcnew System::EventHandler(this, &MyJuego::Animacion);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(736, -1);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(294, 691);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// lbl_tiempo
			// 
			this->lbl_tiempo->AutoSize = true;
			this->lbl_tiempo->BackColor = System::Drawing::Color::White;
			this->lbl_tiempo->Font = (gcnew System::Drawing::Font(L"Britannic Bold", 26.03077F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_tiempo->Location = System::Drawing::Point(860, 609);
			this->lbl_tiempo->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lbl_tiempo->Name = L"lbl_tiempo";
			this->lbl_tiempo->Size = System::Drawing::Size(91, 38);
			this->lbl_tiempo->TabIndex = 1;
			this->lbl_tiempo->Text = L"TIEM";
			// 
			// lbl_vidas
			// 
			this->lbl_vidas->AutoSize = true;
			this->lbl_vidas->BackColor = System::Drawing::Color::White;
			this->lbl_vidas->Font = (gcnew System::Drawing::Font(L"Britannic Bold", 26.03077F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_vidas->Location = System::Drawing::Point(855, 94);
			this->lbl_vidas->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lbl_vidas->Name = L"lbl_vidas";
			this->lbl_vidas->Size = System::Drawing::Size(108, 38);
			this->lbl_vidas->TabIndex = 2;
			this->lbl_vidas->Text = L"VIDAS";
			// 
			// lbl_nAliados
			// 
			this->lbl_nAliados->AutoSize = true;
			this->lbl_nAliados->BackColor = System::Drawing::Color::White;
			this->lbl_nAliados->Font = (gcnew System::Drawing::Font(L"Britannic Bold", 26.03077F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_nAliados->Location = System::Drawing::Point(855, 226);
			this->lbl_nAliados->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lbl_nAliados->Name = L"lbl_nAliados";
			this->lbl_nAliados->Size = System::Drawing::Size(107, 38);
			this->lbl_nAliados->TabIndex = 3;
			this->lbl_nAliados->Text = L"ALIAD";
			// 
			// lbl_nCorrupts
			// 
			this->lbl_nCorrupts->AutoSize = true;
			this->lbl_nCorrupts->BackColor = System::Drawing::Color::White;
			this->lbl_nCorrupts->Font = (gcnew System::Drawing::Font(L"Britannic Bold", 26.03077F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_nCorrupts->Location = System::Drawing::Point(855, 360);
			this->lbl_nCorrupts->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lbl_nCorrupts->Name = L"lbl_nCorrupts";
			this->lbl_nCorrupts->Size = System::Drawing::Size(105, 38);
			this->lbl_nCorrupts->TabIndex = 4;
			this->lbl_nCorrupts->Text = L"CORR";
			// 
			// lbl_nAliadosCorrompidos
			// 
			this->lbl_nAliadosCorrompidos->AutoSize = true;
			this->lbl_nAliadosCorrompidos->BackColor = System::Drawing::Color::White;
			this->lbl_nAliadosCorrompidos->Font = (gcnew System::Drawing::Font(L"Britannic Bold", 26.03077F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lbl_nAliadosCorrompidos->Location = System::Drawing::Point(860, 486);
			this->lbl_nAliadosCorrompidos->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lbl_nAliadosCorrompidos->Name = L"lbl_nAliadosCorrompidos";
			this->lbl_nAliadosCorrompidos->Size = System::Drawing::Size(102, 38);
			this->lbl_nAliadosCorrompidos->TabIndex = 5;
			this->lbl_nAliadosCorrompidos->Text = L"ACOR";
			// 
			// MyJuego
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1028, 681);
			this->Controls->Add(this->lbl_nAliadosCorrompidos);
			this->Controls->Add(this->lbl_nCorrupts);
			this->Controls->Add(this->lbl_nAliados);
			this->Controls->Add(this->lbl_vidas);
			this->Controls->Add(this->lbl_tiempo);
			this->Controls->Add(this->pictureBox1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"MyJuego";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"TheTrickyMaze";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyJuego::MyJuego_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyJuego::MyJuego_KeyUp);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Animacion(System::Object^ sender, System::EventArgs^ e) {

		BufferedGraphics^ buffer = BufferedGraphicsManager::Current->Allocate(graficador, this->ClientRectangle);
		BufferedGraphics^ buffer_escenario = BufferedGraphicsManager::Current->Allocate(buffer->Graphics, this->ClientRectangle);;

		buffer->Graphics->Clear(Color::White);
		buffer_escenario->Graphics->Clear(Color::White);

		
		NovoJogo->Animar_escenario(buffer_escenario->Graphics);
		buffer_escenario->Render();
		
		if (!(NovoJogo->Animar_personajes(buffer->Graphics) == true)) {
			if (NovoJogo->get_ganaste() == true) {

				timer_animacion->Stop();
				_sleep(3000);
				int v = NovoJogo->getVIDAS_JUGADOR();
				NovoJogo->reset_tiempo();
				int t = NovoJogo->getTIME();
				this->Hide();
				MyDialogoAC^ PantalladeDialogo = gcnew MyDialogoAC(v, t);
				PantalladeDialogo->ShowDialog();
				this->Close();
			}
			else if (NovoJogo->get_perdiste() == true) {
				timer_animacion->Stop();
				_sleep(3000);
				this->Hide();
				PlaySound(NULL, NULL, 0);

				MyPantallaPerdiste^ perdiste_f1 = gcnew MyPantallaPerdiste();
				perdiste_f1->ShowDialog();
				this->Close();
			}
		}
		
		ImprimirDatosMenuInGame();
		
		buffer->Render();

	}
	private: System::Void MyJuego_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		NovoJogo->MoverJugador(false, e->KeyCode);
	}
	private: System::Void MyJuego_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		NovoJogo->MoverJugador(true, e->KeyCode);
	}
	void ImprimirDatosMenuInGame() {
		int tiempo = NovoJogo->getTIME();
		lbl_tiempo->Text = tiempo.ToString();
		int vidas = NovoJogo->getVIDAS_JUGADOR();
		lbl_vidas->Text = vidas.ToString();
		int n_aliados = NovoJogo->getCANT_ALIADOS();
		lbl_nAliados->Text = n_aliados.ToString();
		int n_corrupts = NovoJogo->getCANT_CORRUPTS();
		lbl_nCorrupts->Text = n_corrupts.ToString();
		int n_aliadosCorrompidos = NovoJogo->getCANT_ALIADOSCORROMPIDOS();
		lbl_nAliadosCorrompidos->Text = n_aliadosCorrompidos.ToString();
	}

};
}
