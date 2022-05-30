#pragma once
#include "MyPantallaPrincipal.h"
#include "Ente.h"

using namespace System;
using namespace System::Drawing;

ref class MenuCreditos{
	Bitmap^ img;
public:
	MenuCreditos() {
		img = gcnew Bitmap("imagenes\\imagen_creditos.png"); 
	}
	~MenuCreditos() {
		delete this->img;
	}
	void mostrar(Graphics^ g, RECTANGULO area_dibujo) {
		g->DrawImage(this->img, area_dibujo);
	}
};

ref class MenuHistoria {
	Bitmap^ img;
public:
	MenuHistoria() {
		img = gcnew Bitmap("imagenes\\PantallaHistoria1.png"); 
	}
	~MenuHistoria() {
		delete this->img;
	}
	void mostrar(Graphics^ g, RECTANGULO area_dibujo) {
		g->DrawImage(this->img, area_dibujo);
	}
};

