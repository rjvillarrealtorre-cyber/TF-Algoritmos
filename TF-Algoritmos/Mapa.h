#pragma once
#include "Entidad.h"

using namespace System::Collections::Generic;

ref class Mapa {
private:
	Bitmap^ fondo;

	List<EntidadEstatica^>^ entEstaticas;
public:
	Mapa(Bitmap^ f) {
		fondo = f;

		entEstaticas = gcnew List<EntidadEstatica^>();
	}

	~Mapa() {
		delete fondo;
		for (int i = 0; i < entEstaticas->Count; i++) delete entEstaticas[i];
		delete entEstaticas;
	}

	void dibujarFondo(Graphics^ gr) {
		gr->DrawImage(fondo, 0, 0, 900, 514);
	}

	void agregarEntidadEstatica(EntidadEstatica^ ee) {
		entEstaticas->Add(ee);
	}

	List<EntidadEstatica^>^ getEntEstaticas() { return entEstaticas; }
};