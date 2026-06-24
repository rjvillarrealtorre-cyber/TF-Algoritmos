#pragma once
#include "Entidad.h"
#include "ArbolDialogo.h"

using namespace System;

ref class EntidadEstatica : public Entidad {
private:
	ArbolDialogo^ arbol;

	Bitmap^ cuadroInteractuar;
	Bitmap^ cuadroDialogo;

	bool mostrandoCuadroDialogo;
	Point^ coordCuadro;
public:
	EntidadEstatica(int px, int py, Bitmap^ bmp, ArbolDialogo^ ar) : Entidad(px, py, 0) {
		sprites = gcnew array<Sprite^>(1);
		sprites[0] = gcnew Sprite(bmp, true);
		mostrandoCuadroDialogo = false;
		arbol = gcnew ArbolDialogo();
		coordCuadro = gcnew Point(0, 0);
		arbol = ar;

		cuadroInteractuar = gcnew Bitmap("sprites\\otros\\interactuar.png");
		cuadroDialogo = gcnew Bitmap("sprites\\otros\\pergamino.png");
	}

	~EntidadEstatica() {
		delete cuadroInteractuar;
		delete cuadroDialogo;
		delete arbol;
		delete coordCuadro;
	}

	void mover() override {}

	void mostrarInteractuar(Graphics^ gr) {
		gr->DrawImage(cuadroInteractuar, x - sprites[0]->ancho + 5, 
			y - sprites[0]->alto + 7, 85, 37);
	}

	void mostrarCuadroDialogo(Graphics^ gr) {
		gr->DrawImage(cuadroDialogo, coordCuadro->X,
			coordCuadro->Y, 900, 155);
	}

	bool determinarCercania(Jugador^ jugador) {
		if (Math::Abs(x - jugador->getX()) < 100 && 
			Math::Abs(y - jugador->getY()) < 50) return true;

		return false;
	}

	bool manejarDialogo(Graphics^ gr, Jugador^ jugador, Font^ fuente, bool teclaE, array<bool>^ teclaOpciones, array<bool>^ teclaOpcionesAnterior) {
		if (determinarCercania(jugador) && teclaE)
			mostrandoCuadroDialogo = true;

		bool aa = false;

		if (mostrandoCuadroDialogo) {
			mostrarCuadroDialogo(gr);
			arbol->mostrarDialogo(gr, fuente, coordCuadro, 0);
			aa = arbol->manejarFlujoInteraccion(gr, fuente, coordCuadro, teclaE, teclaOpciones, teclaOpcionesAnterior, jugador);
		}
		
		if(!determinarCercania(jugador)) mostrandoCuadroDialogo = false;

		return aa;
	}

	bool manejar(Graphics^ gr, Jugador^ jugador, Font^ fuente, bool teclaE, array<bool>^ teclaOpciones, array<bool>^ teclaOpcionesAnterior) {
		mostrarInteractuar(gr);
		bool aa = manejarDialogo(gr, jugador, fuente, teclaE, teclaOpciones, teclaOpcionesAnterior);
		mostrar(gr);

		return aa;
	}

	ArbolDialogo^ getArbol() { return arbol; }
};