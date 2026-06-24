#pragma once
#include "Aliado.h"
#include "Talador.h"

using namespace System::Collections::Generic;

ref class Mapa {
private:
	Bitmap^ fondo;

	array<EntidadEstatica^>^ entEstaticas;
	array<Aliado^>^ aliados;
	array<Talador^>^ taladores;

	int contador;
public:
	Mapa(Bitmap^ f) {
		fondo = f;

		aliados = gcnew array<Aliado^>(0);
		entEstaticas = gcnew array<EntidadEstatica^>(0);
		taladores = gcnew array<Talador^>(0);
	}

	~Mapa() {
		delete fondo;
		for (int i = 0; i < entEstaticas->Length; i++) delete entEstaticas[i];
		delete entEstaticas;
		for each (Aliado ^ aliado in aliados) delete aliado;
		delete aliados;
		for each (Talador ^ tala in taladores) delete tala;
		delete taladores;
	}

	void dibujarFondo(Graphics^ gr) {
		gr->DrawImage(fondo, 0, 0, 900, 514);
	}

	void manejarEventos() {
		//Por ahora, el único evento es el tercer talador
		// del nivel 2
		contador++;

        if (contador == 30 * CONVERSOR_CONT) {
			int oldLen = taladores->Length;
			array<Talador^>^ tmp = gcnew array<Talador^>(oldLen + 1);
			for (int i = 0; i < oldLen; i++) tmp[i] = taladores[i];
			tmp[oldLen] = gcnew Talador(840, 236, 9);
			taladores = tmp;
		}
	}

    void agregarEntidadEstatica(EntidadEstatica^ ee) {
		int oldLen = entEstaticas->Length;
		array<EntidadEstatica^>^ tmp = gcnew array<EntidadEstatica^>(oldLen + 1);
		for (int i = 0; i < oldLen; i++) tmp[i] = entEstaticas[i];
		tmp[oldLen] = ee;
		entEstaticas = tmp;
	}

    void agregarAliado(Aliado^ a) {
		int oldLen = aliados->Length;
		array<Aliado^>^ tmp = gcnew array<Aliado^>(oldLen + 1);
		for (int i = 0; i < oldLen; i++) tmp[i] = aliados[i];
		tmp[oldLen] = a;
		aliados = tmp;
	}

    void agregarTalador(Talador^ t) {
		int oldLen = taladores->Length;
		array<Talador^>^ tmp = gcnew array<Talador^>(oldLen + 1);
		for (int i = 0; i < oldLen; i++) tmp[i] = taladores[i];
		tmp[oldLen] = t;
		taladores = tmp;
	}

	array<EntidadEstatica^>^ getEntEstaticas() { return entEstaticas; }
	array<Aliado^>^ getAliados() { return aliados; }
	array<Talador^>^ getTaladores() { return taladores; }
};