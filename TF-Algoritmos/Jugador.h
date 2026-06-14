#pragma once
#include "Entidad.h"

ref class Jugador : public Entidad {
private:
	bool tDerecha, tIzquierda, tArriba, tAbajo;
	bool tDerechaAnterior, tIzquierdaAnterior;
	bool tEscape;
	int vida;
	int confianza, conLengua, evidencia;
public:
	Jugador(int px, int py, int v) : Entidad(px, py, v) {
		//Sprites
		sprites = gcnew array<Sprite^>(9);
		sprites[Quieto] = gcnew Sprite(gcnew Bitmap("sprites\\protagonista\\player_idle.png"), true);
		sprites[Derecha] = gcnew Sprite(gcnew Bitmap("sprites\\protagonista\\player_walkingsheet_right.png"));
		sprites[Izquierda] = gcnew Sprite(gcnew Bitmap("sprites\\protagonista\\player_walkingsheet_left.png"));
		sprites[Abajo] = gcnew Sprite(gcnew Bitmap("sprites\\protagonista\\player_walkingsheet_down.png"));
		sprites[Arriba] = gcnew Sprite(gcnew Bitmap("sprites\\protagonista\\player_walkingsheet_up.png"));
		sprites[Suroeste] = gcnew Sprite(gcnew Bitmap("sprites\\protagonista\\player_walkingsheet_southwest.png"));
		sprites[Sureste] = gcnew Sprite(gcnew Bitmap("sprites\\protagonista\\player_walkingsheet_southeast.png"));
		sprites[Noreste] = gcnew Sprite(gcnew Bitmap("sprites\\protagonista\\player_walkingsheet_northeast.png"));
		sprites[Noroeste] = gcnew Sprite(gcnew Bitmap("sprites\\protagonista\\player_walkingsheet_northwest.png"));

		//Otros
		vida = 100;
		confianza = 100;
		conLengua = 0;
		evidencia = 0;
		tEscape = false;
		tDerechaAnterior = tIzquierdaAnterior = false;
	}

	void mover() override {
		determinarIntPorDireccion();

		switch (dirI) {
		case Derecha:
			x += velocidad;
			break;
		case Izquierda:
			x -= velocidad;
			break;
		case Arriba:
			y -= velocidad;
			break;
		case Abajo:
			y += velocidad;
			break;
		case Suroeste:
			x -= velocidad;
			y += velocidad;
			break;
		case Sureste:
			x += velocidad;
			y += velocidad;
			break;
		case Noreste:
			x += velocidad;
			y -= velocidad;
			break;
		case Noroeste:
			x -= velocidad;
			y -= velocidad;
			break;
		}

		if (dirI != Quieto) {
			sprites[direccionActual]->frames++;
			if (sprites[direccionActual]->frames > 5) sprites[direccionActual]->frames = 0;
		}
	}

	void manejarMovimiento() {
		if (tIzquierda || tAbajo || tDerecha || tArriba) setMov(true);
		//-------
		if (tIzquierda && tAbajo) setDir(Suroeste);
		else if (tDerecha && tAbajo) setDir(Sureste);
		else if (tDerecha && tArriba) setDir(Noreste);
		else if (tIzquierda && tArriba) setDir(Noroeste);
		else if (tDerecha) setDir(Derecha);
		else if (tIzquierda) setDir(Izquierda);
		else if (tArriba) setDir(Arriba);
		else if (tAbajo) setDir(Abajo);
		else {
			setMov(false);
			setDir(Quieto);
		}
	}

	void setTDerecha(bool d) { tDerecha = d; }
	void setTIzquierda(bool d) { tIzquierda = d; }
	void setTArriba(bool d) { tArriba = d; }
	void setTAbajo(bool d) { tAbajo = d; }
	void setTDerechaAnterior(bool d) { tDerechaAnterior = d; }
	void setTIzquierdaAnterior(bool d) { tIzquierdaAnterior = d; }
	void setConfianza(int c) { confianza = c; }
	void setConocimiento(int c) { conLengua = c; }
	void setEvidencia(int c) { evidencia = c; }
	void setVida(int c) { vida = c; }
	void setTeclaEscape(bool c) { tEscape = c; }

	bool getTDerecha() { return tDerecha; }
	bool getTIzquierda() { return tIzquierda; }
	bool getTAbajo() { return tAbajo; }
	bool getTArriba() { return tArriba; }
	bool getTDerechaAnterior() { return tDerechaAnterior; }
	bool getTIzquierdaAnterior() { return tIzquierdaAnterior; }
	int getConfianza() { return confianza; }
	int getConocimiento() { return conLengua; }
	int getEvidencia() { return evidencia; }
	int getVida() { return vida; }
	bool getTeclaEscape() { return tEscape; }
};