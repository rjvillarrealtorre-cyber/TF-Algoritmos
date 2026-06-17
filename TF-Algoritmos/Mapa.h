#pragma once
#include "Aliado.h"
#include "Talador.h"

using namespace System::Collections::Generic;

ref class Mapa {
private:
	Bitmap^ fondo;

	List<EntidadEstatica^>^ entEstaticas;
	List<Aliado^>^ aliados;
	List<Talador^>^ taladores;
public:
	Mapa(Bitmap^ f) {
		fondo = f;

		aliados = gcnew List<Aliado^>();
		entEstaticas = gcnew List<EntidadEstatica^>();
		taladores = gcnew List<Talador^>();
	}

	~Mapa() {
		delete fondo;
		for (int i = 0; i < entEstaticas->Count; i++) delete entEstaticas[i];
		delete entEstaticas;
		for each (Aliado ^ aliado in aliados) delete aliado;
		delete aliados;
		for each (Talador ^ tala in taladores) delete tala;
		delete taladores;
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

	void agregarTalador(Talador^ t) {
		taladores->Add(t);
	}

	List<EntidadEstatica^>^ getEntEstaticas() { return entEstaticas; }
	List<Aliado^>^ getAliados() { return aliados; }
	List<Talador^>^ getTaladores() { return taladores; }
};