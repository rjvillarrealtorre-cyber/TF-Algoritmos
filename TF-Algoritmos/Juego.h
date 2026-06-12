#pragma once
#include "Fuente.h"
#include "Jugador.h"
#include "ArbolDialogo.h"
#include "EntidadEstatica.h"

#include "Hud.h"
#include "Nivel.h"

// BUILDERS
#include "BuilderMapa.h"

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

	bool teclaE;
	List<bool>^ teclasOpciones;
	List<bool>^ teclasOpcionesAnterior;
public:
	Juego() {
		jugador = gcnew Jugador(300, 250, 14);
		niveles = gcnew List<Nivel^>();
		fuente = gcnew Fuente();
		contador = 0;
		tiempoSleep = 75;
		teclaE = false;
		teclasOpciones = gcnew List<bool>(
			gcnew array<bool> {false, false, false, false});
		teclasOpcionesAnterior = gcnew List<bool>(
			gcnew array<bool> {false, false, false, false});

		//Setup FINAL
		niveles->Add(setupNivel1());

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
		gr->Clear(Color::Black);
		niveles[nivelActual]->getMapas()[niveles[nivelActual]
			->getMapaActual()]->dibujarFondo(gr);
		// ------------ ENTIDADES -----------

		//Entidad estática
		// Nota: Experimental. Hecho por Github Copilot (IA)
		for each (EntidadEstatica ^ ee in niveles[nivelActual]->getMapas()[niveles[nivelActual]
			->getMapaActual()]->getEntEstaticas()) {
			ee->manejar(gr, jugador, fuente->getFuenteFinal(), teclaE, teclasOpciones, teclasOpcionesAnterior);
		}

		//Jugador
		jugador->manejarMovimiento();
		jugador->mover();

		jugador->mostrar(gr);

		//Manejar cambio de mapa
		niveles[nivelActual]->manejarCambioMapa(jugador, teclaE);

		//Mostrar HUD
		hud->mostrarHud(gr);
		hud->mostrarDatos(
			gr, fuente->getFuenteFinal(), jugador,
			nivelActual, contador, tiempoSleep
		);

		//Otros
		for (int i = 0; i < 4; i++) teclasOpcionesAnterior[i] = teclasOpciones[i];
		contador++;
	}

	void agregarNivel(Nivel^ nvl) {
		niveles->Add(nvl);
	}

	//Setters y getters
	Jugador^ getJugador() { return jugador; }

	void setTeclaE(bool e) { teclaE = e; }
	bool getTeclaE() { return teclaE; }

	void setTeclaOpciones(bool e, int i) { 
		if (i < 1) return;
		teclasOpciones[i - 1] = e;
	}
	void setTeclaOpcionesAnterior(bool e, int i) {
		if (i < 1) return;
		teclasOpciones[i - 1] = e;
	}
	List<bool>^ getTeclasOpciones() { return teclasOpciones; }
	List<bool>^ getTeclasOpcionesAnterior() { return teclasOpcionesAnterior; }
};