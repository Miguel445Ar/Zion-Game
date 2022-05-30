#pragma once
#include <Windows.h>
#include <MMSystem.h>
#include <iostream>
#include <vector>
#include  "CEscenario.h"
#define RECTANGULO System::Drawing::Rectangle

using namespace std;
using namespace System;
using namespace System::Drawing;
using namespace System::Collections::Generic; 
using namespace System::Windows::Forms;

class Ente{
protected:

	short x, y;
	short dx, dy;
	short ancho, alto;

	int IDx;
public:
	Ente() {
		x = y = 0;
		dx = dy = 0;
		ancho = alto = 0;
		IDx = 0;
	}

	int getX() { return x; }
	int getY() { return y; }
	int getDX() { return dx; }
	int getDY() { return dy; }
	int getAncho() { return ancho; }
	int getAlto() { return alto; }

	void setDX(int novo) { this->dx = novo; }
	void setDY(int novo) { this->dy = novo; }

	~Ente() {}
	virtual void dibujar(Graphics^ g, Bitmap^ img) {
		g->DrawImage(img, AreaActual());
	}
	virtual void Movimiento(CEscenario^ escenario) {//creo que falta un Mundo^ mundo
		x += dx;
		y += dy;
	}
	RECTANGULO AreaActual() {
		return RECTANGULO(x, y, ancho * 0.4, alto * 0.4);
	}
	RECTANGULO NextArea() {
		return RECTANGULO(x + dx, y + dy, ancho, alto);
	}
	RECTANGULO HitBox()
	{
		double escala = 0.20;
		int ancho = this->ancho * escala;
		int alto = this->alto * escala;

		return RECTANGULO(x + ancho - 5, y + alto - 5, ancho, alto + 3);
	}
};

