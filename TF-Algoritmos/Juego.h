#pragma once
#include "Fuente.h"
#include "Jugador.h"
#include "ArbolDialogo.h"
#include "EntidadEstatica.h"

#include "Hud.h"
#include "Nivel.h"

// BUILDERS
#include "BuilderNivel.h"

using namespace System::Collections::Generic;

ref class Juego {
private:
	Jugador^ jugador;
	Hud^ hud;
	List<Nivel^>^ niveles;
	int nivelActual;
	bool puedeAcabarNivel;
	bool cinFinalIniciada;

	Fuente^ fuente;
	int contador;
	int TIEMPO_SLEEP;

	bool teclaE;
	bool teclaQ;
	List<bool>^ teclasOpciones;
	List<bool>^ teclasOpcionesAnterior;
public:
	Juego() {
		jugador = gcnew Jugador(300, 250, 14);
		niveles = gcnew List<Nivel^>();
		fuente = gcnew Fuente();
		contador = 0;
		TIEMPO_SLEEP = 75;
		teclaE = false;
		puedeAcabarNivel = false;
		cinFinalIniciada = false;
		teclasOpciones = gcnew List<bool>(
			gcnew array<bool> {false, false, false, false});
		teclasOpcionesAnterior = gcnew List<bool>(
			gcnew array<bool> {false, false, false, false});

		//Setup FINAL
		//niveles->Add(setupNivel1());
		niveles->Add(setupNivel2());

		hud = gcnew Hud();
	}

	~Juego() {
		delete jugador;
		for (int i = 0; i < niveles->Count; i++) delete niveles[i];
		delete niveles;
		delete hud;
		delete fuente;
		
	}

	void acabarNivel() {
		if (!puedeAcabarNivel) return;
		// if (nivelActual + 1 >= niveles->Count) return;

		if (!cinFinalIniciada &&
			niveles[nivelActual]->getCinematicas()->Count == 2)
		{
			niveles[nivelActual]->getCinematicas()[1]->setEnCinematica(true);
			cinFinalIniciada = true;
		}
		if (niveles[nivelActual]->getCinematicas()[1]->getEnCinematica() &&
			!niveles[nivelActual]->getCinematicas()[1]->getTerminado()) return;

		nivelActual++;

		if (nivelActual == 1) {
			jugador->setX(50);
			jugador->setY(50);
		}

		puedeAcabarNivel = false;
	}

	void manejarCinematicas(Graphics^ gr, bool esFinal) { // 0 = inicial / 1 = final
		int numeroActual = esFinal ? nivelActual - 1 : nivelActual;
		if (nivelActual <= 0) return;

		niveles[numeroActual]->mostrarCinematica(gr, fuente->getFuenteFinal(), false, jugador->getTDerecha(),
			jugador->getTDerechaAnterior(), jugador->getTIzquierda(),
			jugador->getTIzquierdaAnterior(), jugador->getTeclaEscape());
		if (niveles[numeroActual]->getCinematicas()[numeroActual]->getEnCinematica()) return;
	}

	void manejarBuclePrincipal(Graphics^ gr) {
		//Cinematica
		acabarNivel();
		int numCinActual = puedeAcabarNivel ? 1 : 0;

		niveles[nivelActual]->mostrarCinematica(gr, fuente->getFuenteFinal(), puedeAcabarNivel, jugador->getTDerecha(),
			jugador->getTDerechaAnterior(), jugador->getTIzquierda(), 
			jugador->getTIzquierdaAnterior(), jugador->getTeclaEscape());
		if (niveles[nivelActual]->getCinematicas()[numCinActual]->getEnCinematica()) return;
		//Borrar todo -- FINAL
		gr->Clear(Color::Black);
		niveles[nivelActual]->getMapas()[niveles[nivelActual]
			->getMapaActual()]->dibujarFondo(gr);
		// ------------ ENTIDADES -----------

		//Entidad estática
		for each (EntidadEstatica ^ ee in niveles[nivelActual]->getMapas()[niveles[nivelActual]
			->getMapaActual()]->getEntEstaticas()) {
			bool aa = ee->manejar(gr, jugador, fuente->getFuenteFinal(), teclaE, teclasOpciones, teclasOpcionesAnterior);
			if (aa) puedeAcabarNivel = true;;
		}

		//Arboles (nivel 2)
		for each (Arbol ^ arbol in jugador->getArboles()) {
			arbol->manejarCrecimiento(gr, fuente->getFuenteFinal());
			arbol->mostrar(gr);
		}

		//Aliados (nivel 2)
		for each (Aliado ^ aliado in niveles[nivelActual]->getMapas()[niveles[nivelActual]
			->getMapaActual()]->getAliados()) {
			aliado->manejarEstados(teclaQ);
			aliado->manejarMovimiento(gr, jugador);
		}

		//Taladores (nivel 2)
		for each (Talador^ talador in niveles[nivelActual]->getMapas()[niveles[nivelActual]
			->getMapaActual()]->getTaladores()) {
			talador->manejarTalador(gr, jugador, niveles[nivelActual]->getMapas()[niveles[nivelActual]
				->getMapaActual()]->getAliados()[0]);
		}

		//Jugador
		jugador->plantarArbol(teclaE);
		jugador->manejarMovimiento();
		jugador->mover();

		jugador->mostrar(gr);

		//Manejar cambio de mapa
		niveles[nivelActual]->manejarCambioMapa(jugador, teclaE);

		//Mostrar HUD
		hud->mostrarHud(gr);
		hud->mostrarDatos(
			gr, fuente->getFuenteFinal(), jugador,
			nivelActual, contador, TIEMPO_SLEEP
		);

		//Otros
		for (int i = 0; i < 4; i++) teclasOpcionesAnterior[i] = teclasOpciones[i];
		jugador->setTDerechaAnterior(jugador->getTDerecha());
		jugador->setTIzquierdaAnterior(jugador->getTIzquierda());

		//Contadores
		jugador->manejarContador();

		contador++;
	}

	void agregarNivel(Nivel^ nvl) {
		niveles->Add(nvl);
	}

	//Setters y getters
	Jugador^ getJugador() { return jugador; }

	void setTeclaE(bool e) { teclaE = e; }
	bool getTeclaE() { return teclaE; }
	void setTeclaQ(bool e) { teclaQ = e; }
	bool getTeclaQ() { return teclaQ; }

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