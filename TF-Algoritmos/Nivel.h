#pragma once
#include "Mapa.h"
#include "Cinematica.h"
using namespace System::Collections::Generic;

ref class Nivel {
private:
	array<Mapa^>^ mapas;
	array<Cinematica^>^ cinematicas;
	int mapaActual;
	int numCinem;
public:
	Nivel(array<Mapa^>^ m) {
		cinematicas = gcnew array<Cinematica^>(0);
		mapas = m;
		mapaActual = 0;
		numCinem = 0;
	}

	Nivel() {
		cinematicas = gcnew array<Cinematica^>(0);
		mapas = gcnew array<Mapa^>(0);
		mapaActual = 0;
		numCinem = 0;
	}

	~Nivel() {
        for (int i = 0; i < mapas->Length; i++) delete mapas[i];
		delete mapas;
		for (int i = 0; i < cinematicas->Length; i++) delete cinematicas[i];
		delete cinematicas;
	}

    void agregarMapa(Mapa^ mapaAgregar) {
		int oldLen = mapas->Length;
		array<Mapa^>^ tmp = gcnew array<Mapa^>(oldLen + 1);
		for (int i = 0; i < oldLen; i++) tmp[i] = mapas[i];
		tmp[oldLen] = mapaAgregar;
		mapas = tmp;
	}

    void agregarCinematica(Cinematica^ c) {
		int oldLen = cinematicas->Length;
		array<Cinematica^>^ tmp = gcnew array<Cinematica^>(oldLen + 1);
		for (int i = 0; i < oldLen; i++) tmp[i] = cinematicas[i];
		tmp[oldLen] = c;
		cinematicas = tmp;
	}

	void manejarCambioMapa(Jugador^ jugador, bool teclaE) {
		if (jugador->getX() > 800 && teclaE && mapaActual < mapas->Length - 1) {
			jugador->setX(50);
			mapaActual++;
		}
		else if (jugador->getX() < 50 && teclaE && mapaActual > 0) {
			jugador->setX(850);
			mapaActual--;
		}
	}

	void mostrarCinematica(Graphics^ gr, Font^ fuente, bool esCinFinal, bool tDerecha, bool tDerechaAnterior, bool tIzquierda, bool tIzquierdaAnterior, bool tEscape) {
		if (cinematicas->Length == 0) return;

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

	array<Mapa^>^ getMapas() { return mapas; }
	int getMapaActual() { return mapaActual; }
	array<Cinematica^>^ getCinematicas() { return cinematicas; }
	int getNumCinem() { return numCinem; }
};