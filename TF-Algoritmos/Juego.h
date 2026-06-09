#pragma once
#include "Jugador.h"
#include "Nivel.h"

ref class Juego {
private:
	Jugador^ jugador;
	List<Nivel^>^ niveles;
	int nivelActual;
public:
	Juego() {
		jugador = gcnew Jugador(25, 25, 7);
		niveles = gcnew List<Nivel^>();

		//Setup (temporal)
		Mapa^ mapa1 = gcnew Mapa(gcnew Bitmap("sprites\\escenarios\\test.jpg"));
		Nivel^ nvl1 = gcnew Nivel();
		nvl1->agregarMapa(mapa1);
		this->agregarNivel(nvl1);
	}

	~Juego() {
		delete jugador;
		for (int i = 0; i < niveles->Count; i++) delete niveles[i];
		delete niveles;
	}

	void manejarBuclePrincipal(Graphics^ gr) {
		//Borrar todo -- FINAL
		niveles[nivelActual]->getMapas()[niveles[nivelActual]
			->getMapaActual()]->dibujarFondo(gr);
		//Jugador
		jugador->manejarMovimiento();
		jugador->mover();

		jugador->mostrar(gr);
	}

	void agregarNivel(Nivel^ nvl) {
		niveles->Add(nvl);
	}

	//Setters y getters
	Jugador^ getJugador() { return jugador; }
};