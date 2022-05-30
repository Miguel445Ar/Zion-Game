#pragma once
#include "Ente.h"
#include "CEscenario.h"
#include "CMeta.h"
enum Direcciones
{
	DispararArriba,
	DispararIzquierda,
	DispararAbajo,
	DispararDerecha,

	PalaArriba,
	PalaIzquierda,
	PalaAbajo,
	PalaDerecha,

	CaminarArriba,
	CaminarIzquierda,
	CaminarAbajo,
	CaminarDerecha,

	AtacarArriba,
	AtacarAbajo,
	AtacarIzq,
	AtacarDerecha,

	FlechaArriba,
	FlechaAbajo,
	FlechaIzq,
	FlechaDerecha,

	Morir
};

class MC :public Ente{
	Direcciones accion;
	int x_matriz, y_matriz;
	int vidas;
public:
	MC(Bitmap^ img) {
		vidas = 0;
		x = 34 ;
		y = 32 ;
		dx = dy = 0;
		ancho = img->Width / 13;
		alto = img->Height / 21;
		accion = CaminarAbajo;

	}
	int get_vidas() {
		return vidas;
	}
	void set_vidas(int value) {
		int v = vidas; int valor = value;
		if ((v += valor) > 0) {
			vidas += value;
		}
		else if ((v += valor) <= 0) {
			vidas = 0;
		}
	}
	void SetAccion(Direcciones mov) {
		accion = mov;
	}
	Direcciones getAccion() {
		return accion;
	}
	void dibujar(Graphics^ g, Bitmap^ img) override {
		RECTANGULO corte = RECTANGULO(IDx * ancho, accion * alto, ancho, alto);
		RECTANGULO decremento = RECTANGULO(x, y, ancho * 0.4, alto * 0.4);

		g->DrawString("Vidas: " + vidas.ToString(), gcnew Font("Arial", 15), Brushes::Black, 800, 100);
		g->DrawImage(img, decremento, corte, GraphicsUnit::Pixel);
		//g->DrawRectangle(Pens::Black, decremento);
		//g->DrawRectangle(Pens::Red, HitBox());

	}
	void Movimiento(CEscenario^ escenario)override { //falta Mundo^ mundo
		if (escenario->determinar_colision_muro(HitBox().X + dx, HitBox().Y + dy, HitBox().Width, HitBox().Height) == false) {
			x += dx;
			y += dy;
		}
		this->EjecutarAccion();
	}
	void get_pos_matriz(CEscenario^ escenario) {
		x_matriz = this->HitBox().X;
		y_matriz = this->HitBox().Y;
		escenario->determinar_ubicacion_personaje(x_matriz, y_matriz);
	}
	int get_x_matriz() {
		return this->x_matriz;
	}
	int get_y_matriz() {
		return this->y_matriz;
	}
	void colision_portal(CCaminos* caminos) {
		int x1 = 0;
		int y1 = 0;
		caminos->get_pos(x1, y1);
		x1 *= celda_width;
		y1 *= celda_height;
		this->x = x1;
		this->y = y1;
	}
	bool colision_meta(CMeta* meta) {
		return (this->HitBox().IntersectsWith(meta->get_area_dibujo()) == true);
	}
private:
	void EjecutarAccion() {

		if (accion >= DispararArriba && accion <= DispararDerecha)
			IDx = (IDx + 1) % 7;
		else if (accion >= PalaArriba && accion <= PalaDerecha)
			IDx = (IDx + 1) % 8;
		else if (accion >= CaminarArriba && accion <= CaminarDerecha && (dx != 0 || dy != 0))
			IDx = (IDx + 1) % 9;
		else if (accion >= AtacarArriba && accion <= AtacarDerecha)
		{
			IDx = (IDx + 1) % 6;

			if (IDx == 0)
			{
				if (accion == AtacarArriba)
					accion = CaminarArriba;
				else if (accion == AtacarAbajo)
					accion = CaminarAbajo;
				else if (accion == AtacarIzq)
					accion = CaminarIzquierda;
				else if (accion == AtacarDerecha)
					accion = CaminarDerecha;
			}
		}
		else if (accion == Morir)
			IDx = (IDx + 1) % 6;
	}
};

