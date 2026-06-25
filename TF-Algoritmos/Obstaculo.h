#pragma once
#include "Utilidades.h"
#include "Prop.h"
#include "Jugador.h"

using namespace System::Drawing;
using namespace System;

ref class Obstaculo : public Prop {
public:
	Obstaculo(Bitmap^ i, int px, int py, int v) : Prop(i, px, py, v, 0.1) {
		dano = 10;
		velocidad *= -1;
	}
};

// ---------

ref class ManejoObstaculos {
private:
	Random^ r = gcnew Random();
	array<Obstaculo^>^ obstaculos;
	int segundosEntreAparicion;
	int countFramesAparicion;
	int contFramesTotal;
public:
	ManejoObstaculos() {
		obstaculos = gcnew array<Obstaculo^>(0);

		segundosEntreAparicion = 5;
		countFramesAparicion = 0;
		contFramesTotal = 0;
	}

	~ManejoObstaculos() {
		for each(Obstaculo^ o in obstaculos) delete o;
		delete obstaculos;
		delete r;
	}

	void agregarObstaculo() {
		int veces = 2;

		if (contFramesTotal >= 10 && contFramesTotal < 20) veces = 3;
		else if (contFramesTotal >= 20 && contFramesTotal < 30) veces = 4;
		else if (contFramesTotal >= 40 && contFramesTotal < 50) veces = 5;
		else if (contFramesTotal >= 50 && contFramesTotal < 60) veces = 6;

		for (int j = 0; j < veces; j++) {
			int yA = r->Next(185, 480);

			int oldLen = obstaculos->Length;
			array<Obstaculo^>^ tmp = gcnew array<Obstaculo^>(oldLen + 1);
			for (int i = 0; i < oldLen; i++) tmp[i] = obstaculos[i];
			tmp[oldLen] = gcnew Obstaculo(gcnew Bitmap("sprites\\entidades\\barril.png"), 1050, yA, 10);
			obstaculos = tmp;
		}

	}

	void manejarAgregarObstaculo() {
		countFramesAparicion++;
		contFramesTotal++;

		float segTotalesTranscurridos = contFramesTotal * CONVERSOR_SEG;
		float segTranscurridos = countFramesAparicion * CONVERSOR_SEG;

		int intervaloAparicion = 5;
		if (segTotalesTranscurridos >= 10 && segTotalesTranscurridos < 30) intervaloAparicion = 4;
		else if (segTotalesTranscurridos >= 30 && segTotalesTranscurridos < 40) intervaloAparicion = 3;
		else if (segTotalesTranscurridos >= 40 && segTotalesTranscurridos < 50) intervaloAparicion = 2;
		else if (segTotalesTranscurridos >= 50 && segTotalesTranscurridos < 60) intervaloAparicion = 1;

		if (segTranscurridos >= intervaloAparicion) {
			agregarObstaculo();
			countFramesAparicion = 0;
		}
	}

	void borrarObstaculo(int i) {
		if (i >= obstaculos->Length) return;

		int oldLen = obstaculos->Length;
		if (oldLen == 0) return;

		delete obstaculos[i];

		array<Obstaculo^>^ tmp = gcnew array<Obstaculo^>(oldLen - 1);
		int k = 0;
		for (int j = 0; j < oldLen; j++) {
			if (j == i) continue;
			tmp[k++] = obstaculos[j];
		}
		obstaculos = tmp;

		// NO OLVIDAR: i--
	}

	void moverObstaculo(int i) {
		obstaculos[i]->mover();
	}

	void manejarColisiones(int i, Jugador^ jugador) {
		if (!verificarColision(obstaculos[i]->getRectangle(), jugador->getRectangle())) return;

		jugador->setInvulnerable(true);
		jugador->setVida(jugador->getVida() - obstaculos[i]->getDano());
		borrarObstaculo(i);
	}

	void manejarObstaculos(Graphics^ gr, Jugador^ jugador) {
		manejarAgregarObstaculo();

		for (int i = 0; i < obstaculos->Length; i++) {
			if (obstaculos[i]->getX() <= 0) {
				borrarObstaculo(i);
				i--;
				continue;
			}
			moverObstaculo(i);
			obstaculos[i]->mostrar(gr);

			manejarColisiones(i, jugador);
		}
	}
};