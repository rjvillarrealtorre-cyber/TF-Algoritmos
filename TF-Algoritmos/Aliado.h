#pragma once
#include "Jugador.h"

ref class Aliado : public Entidad {
private:
	String^ estado;
	bool movDerecha, movIzquierda, movArriba, movAbajo;
public:
	Aliado(int px, int py, int v)
		: Entidad(px, py, v) {
		estado = "seguir";
		movDerecha = movIzquierda = movAbajo = movArriba = false;

		sprites = gcnew array<Sprite^>(9);
		sprites[Quieto] = gcnew Sprite(gcnew Bitmap("sprites\\entidades\\wilmer_idle.png"), true);
		sprites[Derecha] = gcnew Sprite(gcnew Bitmap("sprites\\entidades\\wilmer_walkingsheet_right.png"));
		sprites[Izquierda] = gcnew Sprite(gcnew Bitmap("sprites\\entidades\\wilmer_walkingsheet_left.png"));
		sprites[Abajo] = gcnew Sprite(gcnew Bitmap("sprites\\entidades\\wilmer_walkingsheet_down.png"));
		sprites[Arriba] = gcnew Sprite(gcnew Bitmap("sprites\\entidades\\wilmer_walkingsheet_up.png"));
		sprites[Suroeste] = gcnew Sprite(gcnew Bitmap("sprites\\entidades\\wilmer_walkingsheet_southwest.png"));
		sprites[Sureste] = gcnew Sprite(gcnew Bitmap("sprites\\entidades\\wilmer_walkingsheet_southeast.png"));
		sprites[Noreste] = gcnew Sprite(gcnew Bitmap("sprites\\entidades\\wilmer_walkingsheet_northeast.png"));
		sprites[Noroeste] = gcnew Sprite(gcnew Bitmap("sprites\\entidades\\wilmer_walkingsheet_northwest.png"));
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
		else if (!movDerecha && !movIzquierda && !movAbajo && !movArriba) direccionActual = Quieto;
	}

	void reiniciarEstado() {
		movDerecha = movIzquierda = movAbajo = movArriba = false;
	}

	void seguirJugador(Jugador^ jugador) {
		reiniciarEstado();

		if (jugador->getX() - x > 70)
			movDerecha = true;
		else if (jugador->getX() + jugador->getSprites()[jugador->getDir()]->ancho - x < -70)
			movIzquierda = true;

		if (jugador->getY() + jugador->getSprites()[jugador->getDir()]->alto - y > 30)
			movAbajo = true;
		else if (jugador->getY() - y < -30)
			movArriba = true;

		determinarDireccion();
	}

	void manejarEstados(bool teclaQ) {
		if (!teclaQ) return;

		if (estado == "seguir") estado = "parar";
		else if (estado == "parar") estado = "seguir";
	}

	void manejarMovimiento(Graphics^ gr, Jugador^ jugador) {
		if (estado == "seguir") {
			moviendose = true;
			seguirJugador(jugador);
			mover();
			mostrar(gr);
		}
		else {
			moviendose = false;
			mostrar(gr);
		}
	}

	String^ getEstado() { return estado; }
};