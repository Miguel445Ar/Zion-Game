#pragma once
#include "Ente.h"
#include "CEscenario.h"
#include "Movil.h"
#include "Aliado.h"
enum DireccionesC
{
	DispararArribaC,
	DispararIzquierdaC,
	DispararAbajoC,
	DispararDerechaC,

	PalaArribaC,
	PalaIzquierdaC,
	PalaAbajoC,
	PalaDerechaC,

	CaminarArribaC,
	CaminarIzquierdaC,
	CaminarAbajoC,
	CaminarDerechaC,

	AtacarArribaC,
	AtacarAbajoC,
	AtacarIzqC,
	AtacarDerechaC,

	FlechaArribaC,
	FlechaAbajoC,
	FlechaIzqC,
	FlechaDerechaC,

	MorirC
};

class Corrupt : public CEnemigo {
	DireccionesC accionC;
	int indice_perseguido;
	int cont_perseguido_1;
	bool perseguir_aliado;
	bool atrapado;
	bool dibujable;
	//clock_t start;
public:
	Corrupt(CCaminos* escenario, int x, int y, int ancho, int alto, int n_fil, int n_col, int value_dir, CEscenario^ world):
		CEnemigo(escenario,x,y,ancho,alto,n_fil,n_col,value_dir) {
		dibujable = true;
		perseguir_aliado = true;
		atrapado = false;
		indice_perseguido = 0;
		finish = true;
		cont_perseguido_1 = 0;
	}
	bool colision_aliado(Aliado* aliado) {
		return (this->hitbox_mov.IntersectsWith(aliado->get_hitbox_mov()));
	}
	bool colision_MC(MC* mc) {
		return (this->hitbox_mov.IntersectsWith(mc->HitBox()));
	}
	bool get_atrapado() {
		return this->atrapado;
	}
	bool get_dibujable() {
		return this->dibujable;
	}
	int get_dx() {
		return dx;
	}
	int get_y() {
		return dy;
	}
	void animar_corrupt(Graphics^ g, Bitmap^ img, CEscenario^ escenario, Aliado* aliado, CCaminos* caminos) {
		if (perseguir_aliado == true) {
				cambiar_objetivo_aliado(aliado, escenario, caminos);
				animar_estado_2(g, img);
				if (aliado->get_con_el_MC() == true) {
					finish = true;
					perseguir_aliado = false;
					this->dx = this->dy = 0;
					cout << "\nNo lo corrompi\n";
					atrapado = true;
				}
				if (colision_aliado(aliado) == true) {
					aliado->set_esta_corrompido(true);
					finish = true;
					perseguir_aliado = false;
					this->dx = this->dy = 0;
					cout << "\ncorrompido\n";
					dibujable = false;
					atrapado = true;
				}
		}
		else {
			dibujar(g, img);
		}
	}
private:
	void cambiar_objetivo_aliado(Aliado* aliado, CEscenario^ escenario, CCaminos* caminos) {
		aliado->determinar_posicion_matriz(escenario);
		if (fin_f_matriz != aliado->get_y_matriz() || fin_c_matriz != aliado->get_x_matriz()) {
			fin_f_matriz = aliado->get_y_matriz();
			fin_c_matriz = aliado->get_x_matriz();
			determinar_posicion_matriz(escenario);
			eliminar_posiciones();
			fin_f = fin_f_matriz;
			fin_c = fin_c_matriz;
			camino(caminos, this->x, this->y, fin_f, fin_c);
			this->fin_c *= celda_width;
			this->fin_f *= celda_height;
			normalizar_dimensiones();
			this->x *= celda_width;
			this->y *= celda_height;
			this->area_dibujo.X = this->x;
			this->area_dibujo.Y = this->y;
			this->dx = dy = 0;
			cont_mov = 0;
		}
	}
};
class Arreglo_Corrupts {
	vector<Corrupt*> los_corruptos;
public:
	Arreglo_Corrupts(int size, CCaminos* caminos, int x, int y, int ancho, int alto, int  n_fil, int n_col, int value_dir, CEscenario^ world) {
		agregar_corruptos(size, caminos, x, y, ancho, alto, n_fil, n_col, value_dir, world);
	}
	~Arreglo_Corrupts() {
		eliminar_corrupts();
	}
	void corromper(Arreglo_Aliados* aliados, Graphics^ g, Bitmap^ img, CEscenario^ escenario, CCaminos* caminos) {
		for (int i = 0; i < los_corruptos.size(); ++i) {
			if (los_corruptos[i]->get_dibujable() == true) {
				los_corruptos[i]->animar_corrupt(g, img, escenario, aliados->get_aliado_pos(i), caminos);
			}
		}
	}
	int get_size() {
		return this->los_corruptos.size();
	}
private:
	void agregar_corruptos(int size, CCaminos* caminos,int x, int y, int ancho, int alto,int  n_fil,int n_col,int value_dir, CEscenario^ world) {
		for (int i = 0; i < size; ++i) {
			los_corruptos.push_back(new Corrupt(caminos, x, y, ancho, alto, n_fil, n_col, value_dir, world));
		}
	}
	void eliminar_corrupts() {
		for (int i = 0; i < los_corruptos.size(); ++i) {
			delete los_corruptos[i];
			los_corruptos.erase(los_corruptos.begin() + i);
		}
		los_corruptos.clear();
	}
};



