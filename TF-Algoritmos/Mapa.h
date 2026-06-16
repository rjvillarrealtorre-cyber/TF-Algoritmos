#pragma once
#include "Aliado.h"

using namespace System::Collections::Generic;

ref class Mapa {
private:
	Bitmap^ fondo;

	List<EntidadEstatica^>^ entEstaticas;
	List<Aliado^>^ aliados;
public:
	Mapa(Bitmap^ f) {
		fondo = f;

		aliados = gcnew List<Aliado^>();
		entEstaticas = gcnew List<EntidadEstatica^>();
	}

	~Mapa() {
		delete fondo;
		for (int i = 0; i < entEstaticas->Count; i++) delete entEstaticas[i];
		delete entEstaticas;
		for each (Aliado ^ aliado in aliados) delete aliado;
		delete aliados;
	}

	void dibujarFondo(Graphics^ gr) {
		gr->DrawImage(fondo, 0, 0, 900, 514);
	}

	void agregarEntidadEstatica(EntidadEstatica^ ee) {
		entEstaticas->Add(ee);
	}

	void agregarAliado(Aliado^ a) {
		aliados->Add(a);
	}

	List<EntidadEstatica^>^ getEntEstaticas() { return entEstaticas; }
	List<Aliado^>^ getAliados() { return aliados; }
};