#pragma once
#include "Ente.h"
#include "CEscenario.h"
#include "MC.h"
class CPortales {
	RECTANGULO area_dibujo;
	RECTANGULO area_recorte;
	int x, y;
	int IDx;
	int n_sub_img;
public:
	CPortales(CCaminos* caminos, int n_sub_img) : n_sub_img(n_sub_img) {
		IDx = 0;
		caminos->get_pos_muro(x, y);
		this->x *= celda_width;
		this->y *= celda_height;
		area_dibujo.X = this->x;
		area_dibujo.Y = this->y;
		area_dibujo.Width = celda_width;
		area_dibujo.Height = celda_height;
	}
	void dibujar(Graphics^ g, Bitmap^ img) {
		setear_area_recorte(img);
		g->DrawImage(img, this->area_dibujo, this->area_recorte, GraphicsUnit::Pixel);
		IDx = (IDx + 1) % n_sub_img;
	}
	RECTANGULO get_area_dibujo() {
		return this->area_dibujo;
	}
	bool colision(MC* mc) {
		return (area_dibujo.IntersectsWith(mc->AreaActual()) == true);
	}
private:
	void setear_area_recorte(Bitmap^ img) {
		this->area_recorte.Width = img->Width / n_sub_img;
		this->area_recorte.Height = img->Height;
		this->area_recorte.X = IDx * this->area_recorte.Width;
		this->area_recorte.Y = 0;
	}
};
class Arreglo_Portales {
	vector<CPortales*> los_portales;
public:
	Arreglo_Portales(int size, CCaminos* caminos, int n_sub_img) {
		agregar_portales(size, caminos, n_sub_img);
	}
	~Arreglo_Portales() {
		eliminar_portales();
	}
	void mostrar_portales(Graphics^ g, Bitmap^ img) {
		for (int i = 0; i < los_portales.size(); ++i) {
			los_portales[i]->dibujar(g, img);
		}
	}
	bool colision_jugador(MC* mc) {
		for (int i = 0; i < los_portales.size(); ++i) {
			if (los_portales[i]->colision(mc) == true) {
				return true;
			}
		}
		return false;
	}
private:
	void agregar_portales(int size, CCaminos* caminos, int n_sub_img) {
		for (int i = 0; i < size; ++i) {
			los_portales.push_back(new CPortales(caminos, n_sub_img));
		}
	}
	void eliminar_portales() {
		for (int i = 0; i < los_portales.size(); ++i) {
			delete los_portales[i];
			los_portales.erase(los_portales.begin() + i);
		}
		los_portales.clear();
	}
};

