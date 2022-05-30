#pragma once
#include "Ente.h"
#include "Movil.h"
#include "MC.h"
class Aliado : public CEnemigo {
	bool esta_corrompido;
	bool con_el_MC;
	bool dibujable;
public:
	Aliado(CCaminos* escenario, int x, int y, int ancho, int alto, int n_fil, int n_col, int value_dir, int fin_c, int fin_f):
		CEnemigo(escenario,x,y,ancho,alto,n_fil,n_col,value_dir) {
		con_el_MC = false;
		esta_corrompido = false;
		this->dibujable = true;
	}
	void set_x(int x) {
		this->area_dibujo.X = x;
	}
	void set_y(int y) {
		this->area_dibujo.Y = y;
	}
	void set_dx(int dx) {
		this->dx = dx;
	}
	void set_dy(int dy) {
		this->dy = dy;
	}
	void set_esta_corrompido(bool esta_corrompido) {
		this->esta_corrompido = esta_corrompido;
	}
	void set_dibujable(bool dibujable) {
		this->dibujable = dibujable;
	}
	bool get_dibujable() {
		return this->dibujable;
	}
	bool get_esta_corrompido() {
		return this->esta_corrompido;
	}
	bool get_con_el_MC() {
		return this->con_el_MC;
	}
	bool colision(MC* mc) {
		if (this->hitbox_mov.IntersectsWith(mc->HitBox()) == true) {
			con_el_MC = true;
			return true;
		}
		return false;
	}
};
class Arreglo_Aliados {
	vector<Aliado*> los_aliados;
	bool con_el_1;
	bool con_el_2;
public:
	Arreglo_Aliados(int size, CCaminos* escenario, int x, int y, int ancho, int alto, int n_fil, int n_col, int value_dir, int fin_c, int fin_f) {
		agregar_aliados(size, escenario, x, y, ancho, alto, n_fil, n_col, value_dir, fin_c, fin_f);
		con_el_1 = false;
		con_el_2 = false;
	}
	~Arreglo_Aliados() {
		eliminar_aliados();
	}
	void mover_aliados(Graphics^ g, Bitmap^ img, MC* jugador, CEscenario^ escenario, CCaminos* caminos) {
		for (int i = 0; i < los_aliados.size(); ++i) {
			if (los_aliados[i]->get_dibujable() == true) {
				los_aliados[i]->cambiar_objetivo(jugador, escenario, caminos);
				los_aliados[i]->animar_estado_2(g, img);
				los_aliados[i]->colision(jugador);
			}
		}
	}
	int get_Corrompidos() {/////////////////////////////////
		int corrompidos = 0;
		for each (Aliado * a in los_aliados) {
			if (a->get_esta_corrompido() == true) {
				corrompidos++;
			}
		}
		return corrompidos;
	}
	void validar_aliados_con_el_jugador(MC* mc) {
		for (int i = 0; i < los_aliados.size(); ++i) {
			if (los_aliados[0]->get_con_el_MC() == true) {
				con_el_1 = true;
			}
			if (los_aliados[1]->get_con_el_MC() == true) {
				con_el_2 = true;
			}
		}
	}
	bool mover_jugador() {
		if (con_el_1 == true && con_el_2 == true) {
			return true;
		}
		else {
			return false;
		}
	}
	bool eliminar_aliado(MC* mc) {
		for (int i = (los_aliados.size() - 1); i >= 0; --i) {
			if (los_aliados[i]->get_esta_corrompido() == true && los_aliados[i]->colision(mc) == true && los_aliados[i]->get_dibujable()==true) {
				mc->set_vidas(-1);
				los_aliados[i]->set_dibujable(false);
				los_aliados[i]->set_dx(0);
				los_aliados[i]->set_dy(0);
				cout << "\nAliado Eliminado\n";
				return true;
			}
		}
		return false;
	}
	Aliado* get_aliado_pos(int indice) {
		return los_aliados[indice];
	}
	int get_size() {
		int cont = 0;
		for (int i = 0; i < los_aliados.size(); ++i) {
			if (los_aliados[i]->get_dibujable() == true) {
				++cont;
			}
		}
		return cont;
	}
private:
	void agregar_aliados(int size, CCaminos* escenario, int x, int y, int ancho, int alto, int n_fil, int n_col, int value_dir, int fin_c, int fin_f) {
		for (int i = 0; i < size; ++i) {
			los_aliados.push_back(new Aliado(escenario, x, y, ancho, alto, n_fil, n_col, value_dir, fin_c, fin_f));
		}
	}
	void eliminar_aliados() {
		if (los_aliados.empty() == false) {
			for (int i = 0; i < los_aliados.size(); ++i) {
				delete los_aliados[i];
				los_aliados.erase(los_aliados.begin() + i);
			}
			los_aliados.clear();
		}
	}
};


