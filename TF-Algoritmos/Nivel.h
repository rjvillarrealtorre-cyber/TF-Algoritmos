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

	List<Mapa^>^ getMapas() { return mapas; }
	int getMapaActual() { return mapaActual; }
};