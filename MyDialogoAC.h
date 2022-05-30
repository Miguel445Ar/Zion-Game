#pragma once
#include "PantallaDialogo.h"
#include "MyJuego2.h"

namespace MenuPrincipal { ////////////////FORM DE DIALOGO/////////////////////////

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyDialogoAC : public System::Windows::Forms::Form
	{
		Fondo^ fondo;
		AssasinDialogo^ assasin;
		Nube^ nube;
		Nube1^ nube1;
		CorruptDialogo^ corrupt;

		int tiempo_juego, vidas_personaje;
		bool cambiar_form;

	private: System::Windows::Forms::Timer^ timer_dialogo;

		Graphics^ g;
	public:
		MyDialogoAC(int vidas, int tiempo)
		{
			InitializeComponent();
			this->tiempo_juego = tiempo;
			this->vidas_personaje = vidas;
			this->fondo = gcnew Fondo("imagenes\\fondo_DAC.png");
			this->assasin = gcnew AssasinDialogo("imagenes\\assasin_DAC.png");
			this->nube = gcnew Nube("imagenes\\nube_DAC.png");
			this->nube1 = gcnew Nube1("imagenes\\nube_DAC.png");
			this->corrupt = gcnew CorruptDialogo("imagenes\\corrupt_DAC.png");
			this->cambiar_form = false;
			g = CreateGraphics();
		}

	protected:
		~MyDialogoAC()
		{
			if (components)
			{
				delete components;
			}
			delete this->fondo;
			delete this->assasin;
			delete this->corrupt;
			delete this->nube;
			delete this->nube1;
		}
	private: System::ComponentModel::IContainer^ components;
	protected:


	private:


#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyDialogoAC::typeid));
			this->timer_dialogo = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer_dialogo
			// 
			this->timer_dialogo->Enabled = true;
			this->timer_dialogo->Tick += gcnew System::EventHandler(this, &MyDialogoAC::animacion_dialogo);
			// 
			// MyDialogoAC
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(981, 849);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyDialogoAC";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"TheTrickyMaze";
			this->ResumeLayout(false);

		}
#pragma endregion
		int cont = 0;
	private: System::Void animacion_dialogo(System::Object^ sender, System::EventArgs^ e) {
		BufferedGraphicsContext^ buffer = BufferedGraphicsManager::Current;
		BufferedGraphics^ bf = buffer->Allocate(g, this->ClientRectangle);

		fondo->Mostrar(bf->Graphics);
		assasin->Mostrar(bf->Graphics);
		nube->Mostrar(bf->Graphics);
		corrupt->Mostrar(bf->Graphics);


		bf->Graphics->DrawString("¡Esa heroína", gcnew System::Drawing::Font("Arial", 18), Brushes::Black, 85, 140);
		bf->Graphics->DrawString("es muy astuta! Ni", gcnew System::Drawing::Font("Arial", 18), Brushes::Black, 60, 170);
		bf->Graphics->DrawString("con un laberinto logramos", gcnew System::Drawing::Font("Arial", 17), Brushes::Black, 30, 200);
		bf->Graphics->DrawString("desacernos de ella...", gcnew System::Drawing::Font("Arial", 18), Brushes::Black, 50, 230);
		cont++;
		if (cont >= 50 && cont <= 100) {
			fondo->Mostrar(bf->Graphics);
			assasin->Mostrar(bf->Graphics);
			nube1->Mostrar(bf->Graphics);
			corrupt->Mostrar(bf->Graphics);

			bf->Graphics->DrawString("Te dije que", gcnew System::Drawing::Font("Arial", 18), Brushes::Black, 530, 150);
			bf->Graphics->DrawString("no caería tan", gcnew System::Drawing::Font("Arial", 18), Brushes::Black, 530, 190);
			bf->Graphics->DrawString("fácil...", gcnew System::Drawing::Font("Arial", 17), Brushes::Black, 530, 230);

		}
		else if (cont > 100 && cont <= 150) {
			fondo->Mostrar(bf->Graphics);
			assasin->Mostrar(bf->Graphics);
			nube->Mostrar(bf->Graphics);
			corrupt->Mostrar(bf->Graphics);

			bf->Graphics->DrawString("Déjate de", gcnew System::Drawing::Font("Arial", 18), Brushes::Black, 95, 140);
			bf->Graphics->DrawString("presumir un rato.", gcnew System::Drawing::Font("Arial", 18), Brushes::Black, 70, 170);
			bf->Graphics->DrawString("Ahora sí necesitamos", gcnew System::Drawing::Font("Arial", 17), Brushes::Black, 60, 200);
			bf->Graphics->DrawString("de tu ayuda", gcnew System::Drawing::Font("Arial", 18), Brushes::Black, 60, 230);

		}
		else if (cont > 150 && cont <= 200) {
			fondo->Mostrar(bf->Graphics);
			assasin->Mostrar(bf->Graphics);
			nube1->Mostrar(bf->Graphics);
			corrupt->Mostrar(bf->Graphics);

			bf->Graphics->DrawString("¿Estás seguro?", gcnew System::Drawing::Font("Arial", 18), Brushes::Black, 500, 150);
			bf->Graphics->DrawString("¿Acaso matar a la", gcnew System::Drawing::Font("Arial", 18), Brushes::Black, 500, 180);
			bf->Graphics->DrawString("heroína no es una", gcnew System::Drawing::Font("Arial", 17), Brushes::Black, 500, 210);
			bf->Graphics->DrawString("medida muy extrema?", gcnew System::Drawing::Font("Arial", 17), Brushes::Black, 490, 240);

		}
		else if (cont > 200 && cont <= 250) {
			fondo->Mostrar(bf->Graphics);
			assasin->Mostrar(bf->Graphics);
			nube->Mostrar(bf->Graphics);
			corrupt->Mostrar(bf->Graphics);

			bf->Graphics->DrawString("Haremos lo", gcnew System::Drawing::Font("Arial", 18), Brushes::Black, 95, 140);
			bf->Graphics->DrawString("que sea con tal", gcnew System::Drawing::Font("Arial", 18), Brushes::Black, 70, 170);
			bf->Graphics->DrawString("de obtener el poder", gcnew System::Drawing::Font("Arial", 17), Brushes::Black, 60, 200);
			bf->Graphics->DrawString("del reino Zion...", gcnew System::Drawing::Font("Arial", 18), Brushes::Black, 60, 230);
		}
		else if (cont > 250 && cont <= 300) {
			fondo->Mostrar(bf->Graphics);
			assasin->Mostrar(bf->Graphics);
			nube1->Mostrar(bf->Graphics);
			corrupt->Mostrar(bf->Graphics);

			bf->Graphics->DrawString("Entiendo,", gcnew System::Drawing::Font("Arial", 18), Brushes::Black, 520, 150);
			bf->Graphics->DrawString("ahora déjame el", gcnew System::Drawing::Font("Arial", 18), Brushes::Black, 520, 180);
			bf->Graphics->DrawString("trabajo a mí...", gcnew System::Drawing::Font("Arial", 17), Brushes::Black, 520, 210);

		}
		else if (cont > 300 && cont <= 350) {
			fondo->Mostrar(bf->Graphics);
			assasin->Mostrar(bf->Graphics);
			nube->Mostrar(bf->Graphics);
			corrupt->Mostrar(bf->Graphics);

			bf->Graphics->DrawString("Si fallas,", gcnew System::Drawing::Font("Arial", 18), Brushes::Black, 95, 170);
			bf->Graphics->DrawString("estamos perdidos", gcnew System::Drawing::Font("Arial", 18), Brushes::Black, 70, 200);

		}
		else if (cont > 350 && cont <= 400) {
			fondo->Mostrar(bf->Graphics);
			assasin->Mostrar(bf->Graphics);
			corrupt->Mostrar(bf->Graphics);
		}
		else if (cont > 400) {
			this->cambiar_form = true;
			this->Hide();
			this->timer_dialogo->Stop();
			cout << "DEBERIA INICAR LA FASE 2";
		}
		if (this->cambiar_form == true) {
			MyJuego2^ Juego2 = gcnew MyJuego2(vidas_personaje, tiempo_juego);//
			Juego2->ShowDialog();//
			this->Close();//
		}

		bf->Render(g);
	}
	};
}
