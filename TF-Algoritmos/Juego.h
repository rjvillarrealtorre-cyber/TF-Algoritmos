#pragma once
#include "Fuente.h"
#include "Jugador.h"
#include "Hud.h"
#include "Nivel.h"

using namespace System::Collections::Generic;

ref class Juego {
private:
	Jugador^ jugador;
	Hud^ hud;
	List<Nivel^>^ niveles;
	int nivelActual;

	Fuente^ fuente;
	int contador;
	int tiempoSleep;
public:
	Juego() {
		jugador = gcnew Jugador(25, 25, 7);
		niveles = gcnew List<Nivel^>();
		fuente = gcnew Fuente();
		contador = 0;
		tiempoSleep = 75;

		//Setup (temporal)
		Mapa^ mapa1 = gcnew Mapa(gcnew Bitmap("sprites\\escenarios\\test.jpg"));
		Nivel^ nvl1 = gcnew Nivel();
		nvl1->agregarMapa(mapa1);
		this->agregarNivel(nvl1);

		hud = gcnew Hud();
	}

	~Juego() {
		delete jugador;
		for (int i = 0; i < niveles->Count; i++) delete niveles[i];
		delete niveles;
		delete hud;
		delete fuente;
	}

	void manejarBuclePrincipal(Graphics^ gr) {
		//Borrar todo -- FINAL
		niveles[nivelActual]->getMapas()[niveles[nivelActual]
			->getMapaActual()]->dibujarFondo(gr);
		//Jugador
		jugador->manejarMovimiento();
		jugador->mover();

		jugador->mostrar(gr);

		//Mostrar HUD
		hud->mostrarHud(gr);
		hud->mostrarDatos(
			gr, fuente->getFuenteFinal(), jugador,
			nivelActual, contador, tiempoSleep
		);

		//Otros
		contador++;
	}

	void agregarNivel(Nivel^ nvl) {
		niveles->Add(nvl);
	}

	//Setters y getters
	Jugador^ getJugador() { return jugador; }
};