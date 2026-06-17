#pragma once
#include "Entidad.h"

ref class EntidadDinamica : public Entidad {
protected:
	bool movDerecha, movIzquierda, movArriba, movAbajo;
public:
	EntidadDinamica(int px, int py, int v) : Entidad(px, py, v) {
		movDerecha = movIzquierda = movAbajo = movArriba = false;
	}

	void determinarDireccion() {
		if (movDerecha && !movAbajo && !movArriba) direccionActual = Derecha;
		else if (movIzquierda && !movAbajo && !movArriba) direccionActual = Izquierda;
		else if (movArriba && !movDerecha && !movIzquierda) direccionActual = Arriba;
		else if (movAbajo && !movDerecha && !movIzquierda) direccionActual = Abajo;
		else if (movDerecha && movAbajo) direccionActual = Sureste;
		else if (movDerecha && movArriba) direccionActual = Noreste;
		else if (movIzquierda && movAbajo) direccionActual = Suroeste;
		else if (movIzquierda && movArriba) direccionActual = Noroeste;
		moviendose = true;

		if (!movDerecha && !movIzquierda && !movAbajo && !movArriba) {
			direccionActual = Quieto;
			moviendose = false;
		}
	}

	void reiniciarEstado() {
		movDerecha = movIzquierda = movAbajo = movArriba = false;
	}
};