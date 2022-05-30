#pragma once
//#include "CEscenario.h"
//#include "MC.h"

class CCorazon{
protected:
	RECTANGULO area_dibujo_Corazon;
	RECTANGULO area_recorte_Corazon;
	int x, y;
	int IDx;
	int n_sub_img;

public:
	CCorazon(CCaminos* caminos, int n_sub_img) {
		
		this->n_sub_img = n_sub_img;
		IDx = 0;
		caminos->get_pos(x, y);
		this->x *= celda_width;
		this->y *= celda_height;
		area_dibujo_Corazon.X = this->x;
		area_dibujo_Corazon.Y = this->y;
		area_dibujo_Corazon.Width = celda_width;
		area_dibujo_Corazon.Height = celda_height;
	}

	RECTANGULO get_area_dibujo() {
		return this->area_dibujo_Corazon;
	}
	void dibujar(Graphics^ g, Bitmap^ img) {
		setear_area_recorte(img);
		g->DrawImage(img, this->area_dibujo_Corazon, this->area_recorte_Corazon, GraphicsUnit::Pixel);
		IDx = (IDx + 1) % n_sub_img;
	}

	bool colision(MC* mc) {
		return(this->area_dibujo_Corazon.IntersectsWith(mc->HitBox()) == true);
	}

private:
	void setear_area_recorte(Bitmap^ img) {
		this->area_recorte_Corazon.Width = img->Width / n_sub_img;
		this->area_recorte_Corazon.Height = img->Height;
		this->area_recorte_Corazon.X = IDx * this->area_recorte_Corazon.Width;
		this->area_recorte_Corazon.Y = 0;
	}
};

class ArregloCorazones {
	vector<CCorazon*> corazones;
public:

	ArregloCorazones(int size, CCaminos* caminos, int n_sub_img) {
		agregar_corazones(size, caminos, n_sub_img);
	}
	~ArregloCorazones() {
		if (corazones.empty() == false) {
			for (int i = 0; i < corazones.size(); i++) {
				delete corazones[i];
				corazones.erase(corazones.begin() + i);
			}
			corazones.clear();
		}
	}
	void MostrarMCorazones(Graphics^ g, Bitmap^ img) {
		for (int i = 0; i < corazones.size(); ++i) {
			corazones[i]->dibujar(g, img);
		}
	}
	void agregar_corazones(int size, CCaminos* caminos, int n_sub_img) {
		for (int i = 0; i < size; ++i) {
			corazones.push_back(new CCorazon(caminos, n_sub_img));
		}
	}
	void eliminar_corazones(MC* mc) {
		for (int i = (corazones.size() - 1); i >= 0; --i) {
			if (corazones[i]->colision(mc) == true) {
				mc->set_vidas(1);
				delete corazones[i];
				corazones.erase(corazones.begin() + i);
			}
		}
	}
};

