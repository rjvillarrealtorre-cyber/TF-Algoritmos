#pragma once
#include "Entidad.h"

using namespace System::Collections::Generic;

ref class Mapa {
private:
	Bitmap^ fondo;
	//to-do: lista de entidades (o lo que sea)
public:
	Mapa(Bitmap^ f) {
		fondo = f;
	}

	~Mapa() {
		delete fondo;
	}

	void dibujarFondo(Graphics^ gr) {
		gr->DrawImage(fondo, 0, 0, 900, 514);
	}
};