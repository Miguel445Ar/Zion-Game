#pragma once
#include "Ente.h"
#include "Aliado.h"
#include "Movil.h"
#include "MC.h"
class Assasin : public CEnemigo {
	bool explota;
public:
	Assasin(CCaminos* escenario, int x, int y, int ancho, int alto, int n_fil, int n_col, int value_dir, int fin_c, int fin_f):
		CEnemigo(escenario, x, y, ancho, alto, n_fil, n_col, value_dir) {
		explota = false;
	}
	bool get_explota() {
		return explota;
	}
	bool colision(MC* mc) {
		if (this->hitbox_mov.IntersectsWith(mc->HitBox())) {
			explota = true;
			return true;
		}
		else {
			return false;
		}
	}

};
class Arreglo_Assasins {
	vector<Assasin*> los_assasins;
public:
	Arreglo_Assasins(int size, CCaminos* escenario, int x, int y, int ancho, int alto, int n_fil, int n_col, int value_dir, int fin_c, int fin_f) {
		agregar_assasins(size, escenario, x, y, ancho, alto, n_fil, n_col, value_dir, fin_c, fin_f);
	}
	~Arreglo_Assasins() {
		eliminar_assasins();
	}
	void mover_assasins(MC* jugador, CEscenario^ escenario, CCaminos* caminos, Graphics^ g, Bitmap^ img) {
		for (int i = 0; i < los_assasins.size(); ++i) {
			los_assasins[i]->cambiar_objetivo(jugador, escenario, caminos);
			los_assasins[i]->animar_estado_2(g, img);
		}
	}
	void explotar_assasins(MC* mc) {
		for (int i = (los_assasins.size()-1); i >=0; --i) {
			if (los_assasins[i]->colision(mc) == true) {
				mc->set_vidas(-3);
				delete los_assasins[i];
				los_assasins.erase(los_assasins.begin() + i);
			}
		}
	}
	int get_size() {
		return this->los_assasins.size();
	}
private:
	void agregar_assasins(int size, CCaminos* escenario, int x, int y, int ancho, int alto, int n_fil, int n_col, int value_dir, int fin_c, int fin_f) {
		for (int i = 0; i < size; ++i) {
			los_assasins.push_back(new Assasin(escenario, x, y, ancho, alto, n_fil, n_col, value_dir, fin_c, fin_f));
		}
	}
	void eliminar_assasins() {
		if (los_assasins.empty() == false) {
			for (int i = 0; i < los_assasins.size(); ++i) {
				delete los_assasins[i];
				los_assasins.erase(los_assasins.begin() + i);
			}
			los_assasins.clear();
		}
	}
};
