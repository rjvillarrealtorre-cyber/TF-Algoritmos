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
	array<Nivel^>^ niveles;
	int nivelActual;
	bool puedeAcabarNivel;
	bool enDerrota;
	bool cinFinalIniciada;

	Fuente^ fuente;
	int contador;
	int TIEMPO_SLEEP;

	bool teclaE, teclaQ;
	bool teclaEAnt, teclaQAnt;
	array<bool>^ teclasOpciones;
	array<bool>^ teclasOpcionesAnterior;
public:
	Juego() {
		jugador = gcnew Jugador(300, 250, 14);
		niveles = gcnew array<Nivel^>(0);
		fuente = gcnew Fuente();
		contador = 0;
		TIEMPO_SLEEP = 75;
		teclaE = false;
		enDerrota = false;
		puedeAcabarNivel = false;
		cinFinalIniciada = false;
		teclasOpciones = gcnew array<bool>(4) { false, false, false, false };
		teclasOpcionesAnterior = gcnew array<bool>(4) { false, false, false, false };
       //Setup FINAL
		//niveles->Add(setupNivel1());
		agregarNivel(setupNivel2());

		hud = gcnew Hud();
	}

	~Juego() {
		delete jugador;
		for (int i = 0; i < niveles->Length; i++) delete niveles[i];
		delete niveles;
		delete hud;
		delete fuente;
		
	}

	void acabarNivel() {
		if (!puedeAcabarNivel) return;
		// if (nivelActual + 1 >= niveles->Length) return;

		if (!cinFinalIniciada &&
			niveles[nivelActual]->getCinematicas()->Length == 2)
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

	void mostrarVentanaDerrota(Graphics^ gr) {
		if (!enDerrota) return;

		Bitmap^ md = gcnew Bitmap("sprites\\menu\\derrota.jpg");
		gr->DrawImage(md, 88, 0, 1024, 514);

		if (jugador->getTeclaEscape()) {
			niveles[nivelActual]->~Nivel();

			switch (nivelActual) {
			case 0:
				niveles[nivelActual] = setupNivel1();
				break;
			case 1:
				niveles[nivelActual] = setupNivel2();
				break;
			case 2:
				// FALTA
				// niveles[nivelActual] = setupNivel3();
				break;
			}

			enDerrota = false;
		}

		delete md;
	}

	void manejarBuclePrincipal(Graphics^ gr) {
		//Derrota
		mostrarVentanaDerrota(gr);
		if (enDerrota) return;
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
			aliado->manejarEstados(teclaQ, teclaQAnt);
			aliado->manejarMovimiento(gr, jugador);
		}

		//Taladores (nivel 2)
		for each (Talador^ talador in niveles[nivelActual]->getMapas()[niveles[nivelActual]
			->getMapaActual()]->getTaladores()) {
			talador->manejarTalador(gr, jugador, niveles[nivelActual]->getMapas()[niveles[nivelActual]
				->getMapaActual()]->getAliados()[0]);
		}

		//Jugador
		jugador->plantarArbol(teclaE, teclaEAnt);
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

		//Evento (nivel 2)
		if (true) {
			niveles[nivelActual]->getMapas()[niveles[nivelActual]
				->getMapaActual()]->manejarEventos();
			bool terminara = jugador->verPorArboles();

			if (terminara) puedeAcabarNivel = true;
		}
			

		//Otros
		for (int i = 0; i < 4; i++) teclasOpcionesAnterior[i] = teclasOpciones[i];
		teclaEAnt = teclaE;
		teclaQAnt = teclaQ;

		//Contadores
		jugador->manejarContador();

		contador++;
	}

 void agregarNivel(Nivel^ nvl) {
		int oldLen = niveles->Length;
		array<Nivel^>^ tmp = gcnew array<Nivel^>(oldLen + 1);
		for (int i = 0; i < oldLen; i++) tmp[i] = niveles[i];
		tmp[oldLen] = nvl;
		niveles = tmp;
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
	array<bool>^ getTeclasOpciones() { return teclasOpciones; }
	array<bool>^ getTeclasOpcionesAnterior() { return teclasOpcionesAnterior; }
};