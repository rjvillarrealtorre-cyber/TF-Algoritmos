#pragma once
#include "Mapa.h"
#include "Cinematica.h"
using namespace System::Collections::Generic;

ref class Nivel {
private:
	List<Mapa^>^ mapas;
	List<Cinematica^>^ cinematicas;
	int mapaActual;
	int numCinem;
public:
	Nivel(List<Mapa^>^ m) {
		cinematicas = gcnew List<Cinematica^>();
		mapas = m;
		mapaActual = 0;
		numCinem = 0;
	}

	Nivel() {
		cinematicas = gcnew List<Cinematica^>();
		mapas = gcnew List<Mapa^>();
		mapaActual = 0;
		numCinem = 0;
	}

	~Nivel() {
		for (int i = 0; i < mapas->Count; i++) delete mapas[i];
		delete mapas;
		for each (Cinematica ^ c in cinematicas) delete c;
		delete cinematicas;
	}

	void agregarMapa(Mapa^ mapaAgregar) {
		mapas->Add(mapaAgregar);
	}

	void agregarCinematica(Cinematica^ c) {
		cinematicas->Add(c);
	}

	void manejarCambioMapa(Jugador^ jugador, bool teclaE) {
		if (jugador->getX() > 800 && teclaE && mapaActual < mapas->Count - 1) {
			jugador->setX(50);
			mapaActual++;
		}
		else if (jugador->getX() < 50 && teclaE && mapaActual > 0) {
			jugador->setX(850);
			mapaActual--;
		}
	}

	void mostrarCinematica(Graphics^ gr, Font^ fuente, bool esCinFinal, bool tDerecha, bool tDerechaAnterior, bool tIzquierda, bool tIzquierdaAnterior, bool tEscape) {
		if (cinematicas->Count == 0) return;

		if (!esCinFinal) numCinem = 0;
		else if (esCinFinal) numCinem = 1;

		if (numCinem == -1) return;

		if (cinematicas[numCinem]->getEnCinematica()) {
			if (numCinem != 0 && numCinem != 1) return;

			cinematicas[numCinem]->mostrarSlide(gr, fuente);
			cinematicas[numCinem]->manejarCambioSlide(gr, fuente, tDerecha, tDerechaAnterior, tIzquierda, tIzquierdaAnterior, tEscape);
		}

		if (cinematicas[numCinem]->getTerminado()) {
			gr->Clear(Color::Black);
			mapas[mapaActual]->dibujarFondo(gr);
			cinematicas[numCinem]->setTerminado(false);
		}
	}

	void detenerBucle() {
		if (cinematicas[numCinem]->getEnCinematica()) return;
	}

	List<Mapa^>^ getMapas() { return mapas; }
	int getMapaActual() { return mapaActual; }
	List<Cinematica^>^ getCinematicas() { return cinematicas; }
	int getNumCinem() { return numCinem; }
};