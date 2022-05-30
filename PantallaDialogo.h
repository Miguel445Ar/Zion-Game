#pragma once
using namespace System;
using namespace System::Drawing;

ref class Fondo{
protected:
	int x, y;
	int alto, ancho;
	Bitmap^ imagen;
public:
	Fondo(String^ ruta) {
		imagen = gcnew Bitmap(ruta);
		x = y = 0;
		alto = imagen->Height;
		ancho = imagen->Width;
	}

	System::Drawing::Rectangle Area() {
		return System::Drawing::Rectangle(x, y, ancho, alto);
	}

	virtual void Mostrar(Graphics^ g) {
		g->DrawImage(imagen, Area());
	}
};

ref class CorruptDialogo : public Fondo{
public:
	CorruptDialogo(String^ ruta) :Fondo(ruta) {
		x = 20;
		y = 340;
		alto = 350;
		ancho = 350;
	}
};
ref class AssasinDialogo :public Fondo {
public:
	AssasinDialogo(String^ ruta) : Fondo(ruta) {
		x = 430;
		y = 320;
		alto = 350;
		ancho = 350;
	}
};

ref class Nube :public Fondo
{
public:
	Nube(String^ ruta) :Fondo(ruta) {
		x = 0;
		y = 100;
		alto = 280;
		ancho = 330;
	}
};

ref class Nube1 :public Nube
{
public:
	Nube1(String^ ruta) :Nube(ruta) {
		x = 430;
		y = 100;
		alto = 280;
		ancho = 330;
	}
};
