#pragma once
#include "CEscenario.h"
class CMeta {
	RECTANGULO area_dibujo;
	int x, y;
public:
	CMeta(CCaminos* caminos) {
		caminos->get_pos_meta(x, y);
		x *= celda_width;
		y *= celda_height;
		area_dibujo.X = x;
		area_dibujo.Y = y;
		area_dibujo.Width = celda_width;
		area_dibujo.Height = celda_height;
	}
	RECTANGULO get_area_dibujo() {
		return this->area_dibujo;
	}
	void dibujar(Graphics^ g, Bitmap^ img) {
		g->DrawImage(img, area_dibujo);
	}
};

