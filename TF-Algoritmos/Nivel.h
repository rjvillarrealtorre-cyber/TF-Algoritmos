#pragma once
#include "Mapa.h"
using namespace System::Collections::Generic;

ref class Nivel {
private:
	List<Mapa^>^ mapas;
	int mapaActual;
public:
	Nivel(List<Mapa^>^ m) {
		mapas = m;
		mapaActual = 0;
	}

	Nivel() {
		mapas = gcnew List<Mapa^>();
		mapaActual = 0;
	}

	~Nivel() {
		for (int i = 0; i < mapas->Count; i++) delete mapas[i];
		delete mapas;
	}

	void agregarMapa(Mapa^ mapaAgregar) {
		mapas->Add(mapaAgregar);
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

	List<Mapa^>^ getMapas() { return mapas; }
	int getMapaActual() { return mapaActual; }
};