#pragma once
#include "MC.h"
#include "Corrupto.h"
#include "Aliado.h"
#include "Ente.h"
#include "Asesino.h"
#include "CEscenario.h"
#include "Movil.h"
#include "CPortales.h"
#include "CMeta.h"
#include "Monedas.h"
#include <string>
#include <sstream>

ref class Controladora {
	MC* jugador;
	CEscenario^ mi_escenario;
	CCaminos* caminos;
	Arreglo_Aliados* mis_aliados;
	Arreglo_Aliados* aliados_por_defecto;
	Arreglo_Corrupts* mis_corrupts;
	Arreglo_Portales* mis_portales;
	Arreglo_Assasins* mis_assasins;
	ArregloCorazones* mis_corazones;
	CMeta* meta;
	Bitmap^ imgJugador;
	Bitmap^ img_muro;
	Bitmap^ img_camino;
	Bitmap^ img_corrupt;
	Bitmap^ img_assasin;
	Bitmap^ img_aliado;
	Bitmap^ img_portal;
	Bitmap^ img_meta;
	Bitmap^ img_Corazones;
	int cont;
	bool iniciar_corrupts_y_aliados;
	int cant_aliados, cant_corrupts, cant_assasins;
	bool ganaste;
	bool perdiste;
	int tiempo;
	int t;
public:
	Controladora(Graphics^ g, int cant_aliados, int vidas, int tiempo) {
		calcular_cantidad_personajes(cant_aliados);
		this->t = tiempo + 1;
		reset_tiempo();
		cont = 0;
		ganaste = false;
		perdiste = false;
		iniciar_corrupts_y_aliados = false;
		this->imgJugador = gcnew Bitmap("imagenes\\mc.png");
		this->jugador = new MC(imgJugador);
		this->jugador->set_vidas(vidas);
		this->caminos = new CCaminos;
		this->mi_escenario = gcnew CEscenario(caminos);
		jugador->get_pos_matriz(mi_escenario);
		mis_aliados = new Arreglo_Aliados(this->cant_aliados, caminos, 35, 35, 25, 25, 21, 13, 10, jugador->get_x_matriz(), jugador->get_y_matriz());
		aliados_por_defecto = new Arreglo_Aliados(2, caminos, 35, 35, 25, 25, 21, 13, 10, jugador->get_x_matriz(), jugador->get_y_matriz());
		mis_corrupts = new Arreglo_Corrupts(this->cant_corrupts, caminos, 31, 31, 25, 25, 21, 13, 10, mi_escenario);
		mis_portales = new Arreglo_Portales(4, caminos, 4);
		mis_assasins = new Arreglo_Assasins(this->cant_assasins, caminos, 35, 35, 25, 25, 21, 13, 10, jugador->get_x_matriz(), jugador->get_y_matriz());
		mis_corazones = new ArregloCorazones(4, caminos, 4);
		meta = new CMeta(caminos);
		this->img_corrupt = gcnew Bitmap("imagenes\\corrupt.png"); // ''        ''         '' ''     ''     ''    ''    ''/////
		this->img_assasin = gcnew Bitmap("imagenes\\assasin.png"); //hacer implementacion de las clases (crear clase padre)
		this->img_aliado = gcnew Bitmap("imagenes\\aliado.png"); /////////////////////////////////////////////////////////////
		this->img_muro = gcnew Bitmap("imagenes\\muro_juego.png");
		this->img_camino = gcnew Bitmap("imagenes\\newcamino.png");
		this->img_corrupt = gcnew Bitmap("imagenes\\corrupt.png");
		this->img_portal = gcnew Bitmap("imagenes\\portal.png");
		this->img_meta = gcnew Bitmap("imagenes\\meta.png");
		this->img_Corazones = gcnew Bitmap("imagenes\\monedas_corazon.png");
	}
	void correr_time(Graphics^ g) {
		g->DrawString("Tiempo: " + ((tiempo - clock()) / 1000), gcnew Font("Aral", 15), Brushes::Blue, 900, 100);
	}
	int getTIME() {
		return ((tiempo - clock()) / 1000);
	}
	int getCANT_CORRUPTS() {
		return this->mis_corrupts->get_size();
	}
	int getCANT_ASSASINS() {
		return this->mis_assasins->get_size();
	}
	int getVIDAS_JUGADOR() {
		return this->jugador->get_vidas();
	}
	int getCANT_ALIADOS() {
		return (this->mis_aliados->get_size() + 2);
	}
	int getCANT_ALIADOSCORROMPIDOS() {////////////////7
		return mis_aliados->get_Corrompidos();
	}
	bool fin_time() {
		return (tiempo - clock() <= 0);
	}
	~Controladora() {
		delete this->jugador,	 this->imgJugador,
			this->caminos,		 this->img_camino,
			this->img_muro,		 this->mi_escenario;
		delete mis_aliados,		 this->img_aliado,
			 this->mis_corrupts, this->img_corrupt,
			 this->aliados_por_defecto,
			 this->mis_portales, this->img_portal,
			 this->mis_assasins, this->img_assasin,
			 this->meta,		 this->img_meta;
	}
	void MoverJugador(bool accion, Keys key)
	{
		if (accion == true)
		{
			if (key == Keys::W||key == Keys::Up)
			{
				jugador->setDY(-7);
				jugador->SetAccion(CaminarArriba);
			}
			else if (key == Keys::S||key == Keys::Down)
			{
				jugador->setDY(7);
				jugador->SetAccion(CaminarAbajo);
			}
			else if (key == Keys::A||key == Keys::Left)
			{
				jugador->setDX(-7);
				jugador->SetAccion(CaminarIzquierda);
			}
			else if (key == Keys::D||key == Keys::Right)
			{
				jugador->setDX(7);
				jugador->SetAccion(CaminarDerecha);
			}
		}
		else
		{
			if (key == Keys::W || key == Keys::Up)
				jugador->setDY(0);
			else if (key == Keys::S || key == Keys::Down)
				jugador->setDY(0);
			else if (key == Keys::A || key == Keys::Left)
				jugador->setDX(0);
			else if (key == Keys::D || key == Keys::Right)
				jugador->setDX(0);
		}
	}
	bool get_perdiste() {
		return this->perdiste;
	}
	bool get_ganaste() {
		return this->ganaste;
	}
	void set_ganaste(bool ganaste) {
		this->ganaste = ganaste;
	}
	void set_perdiste(bool perdiste) {
		this->perdiste = perdiste;
	}
	void Animar_escenario(Graphics^ g) {
		mi_escenario->mostrar_muros(g, img_muro);
		mi_escenario->mostrar_celdas(g, img_camino);
	}
	void reset_tiempo() {
		tiempo = t * 1000 + clock();
	}
	//////////////CAMBIO AQUI//////////
	bool Animar_personajes(Graphics^ g) { //FASE 1
		if (this->cont > 0) {
			correr_time(g);
		}
		else {
			reset_tiempo();
		}
			
		this->mis_corazones->MostrarMCorazones(g, img_Corazones);//
		this->mis_corazones->eliminar_corazones(this->jugador);//

		this->aliados_por_defecto->mover_aliados(g, img_aliado, jugador, mi_escenario, caminos);
		if (cont == 0) {
			this->aliados_por_defecto->validar_aliados_con_el_jugador(jugador);
		}
		if (iniciar_corrupts_y_aliados == true) {
			mis_aliados->mover_aliados(g, img_aliado,jugador,mi_escenario,caminos);
			mis_corrupts->corromper(mis_aliados, g, img_corrupt, mi_escenario, caminos);
			mis_aliados->eliminar_aliado(jugador);
		}
		if (this->aliados_por_defecto->mover_jugador() == true) {
			jugador->Movimiento(mi_escenario);
			++cont;
			iniciar_corrupts_y_aliados = true;
		}
		jugador->dibujar(g, imgJugador);
		if (jugador->get_vidas() > 0 && fin_time() == true) {
			ganaste = true;
			return false;
		}
		if (jugador->get_vidas() <= 0 && fin_time() == true || jugador->get_vidas() <= 0 && fin_time() == false) {
			perdiste = true;
			return false;
		}

		return true;
	}
	//////////////CAMBIO AQUI//////////
	bool Animar_fase_2(Graphics^ g) { //FASE 2
		correr_time(g);
		mis_assasins->mover_assasins(jugador, mi_escenario, caminos, g, img_assasin);
		mis_assasins->explotar_assasins(jugador);
		mis_portales->mostrar_portales(g, img_portal);
		meta->dibujar(g, img_meta);
		if (mis_portales->colision_jugador(jugador)) {
			jugador->colision_portal(caminos);
			jugador->setDX(0);
			jugador->setDY(0);
		}
		jugador->Movimiento(mi_escenario);
		jugador->dibujar(g, imgJugador);
		if (jugador->colision_meta(meta) == true && fin_time() == false) {
			ganaste = true;
			return false;
		}
		if (jugador->colision_meta(meta) == false && jugador->get_vidas() > 0 && fin_time() == true || jugador->get_vidas() <= 0 && fin_time() == false) {
			perdiste = true;
			return false;
		}
		return true;
	}
private:
	void calcular_cantidad_personajes(int cant) {
		this->cant_aliados = cant - 2;
		double n_corrupts = (cant * 0.6);
		int n1 = (cant * 0.6);
		double c1 = n_corrupts - n1;
		if (c1 >= 0.5) {
			n1 += 1;
		}
		this->cant_corrupts = n1;
		double n_assasins = (cant * 0.4);
		int n2 = (cant * 0.4);
		double c2 = n_assasins - n2;
		if (c2 >= 0.5) {
			n2 += 1;
		}
		this->cant_assasins = n2;
	}
};

