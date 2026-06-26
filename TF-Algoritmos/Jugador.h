#pragma once
#include "Entidad.h"
#include "Arbol.h"

using namespace System;
using namespace System::Collections::Generic;

ref class Jugador : public Entidad {
private:
	bool tDerecha, tIzquierda, tArriba, tAbajo;
	bool tDerechaAnterior, tIzquierdaAnterior;
	bool tEscape;
	int vida;
	int confianza, conLengua, evidencia;
	//Nivel 2
	int semillas;
	array<Arbol^>^ arboles;
	int totalArbolesGerminados;
	//Nivel 3
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
		totalArbolesGerminados = 0;
		tEscape = false;
		tDerechaAnterior = tIzquierdaAnterior = false;
		semillas = 6; // TEMPORAL
		tiempoInvulnerabilidad = 2;
		arboles = gcnew array<Arbol^>(0);

		activarEnBote();
	}

	~Jugador() {
        for (int i = 0; i < arboles->Length; i++) delete arboles[i];
		delete arboles;
	}

	void activarEnBote() {
		enBote = true;
		escala = 0.25;

		for (int i = 0; i < sprites->Length; i++) {
			delete sprites[i];
			sprites[i] = gcnew Sprite(gcnew Bitmap("sprites\\protagonista\\bote.png"), true);
		}
	}

	void plantarArbol(bool teclaE, bool teclaEAnt) {
		if ((!teclaE || teclaEAnt) || semillas <= 0) return;

		if (direccionActual == Derecha || direccionActual == Sureste || direccionActual == Noreste) { // falta restriccion por parcelas
            {
				int oldLen = arboles->Length;
				array<Arbol^>^ tmp = gcnew array<Arbol^>(oldLen + 1);
				for (int i = 0; i < oldLen; i++) tmp[i] = arboles[i];
				tmp[oldLen] = gcnew Arbol(x + sprites[0]->ancho + 5, y + sprites[0]->alto / 2);
				arboles = tmp;
			}
		}
		else if (direccionActual == Izquierda || direccionActual == Suroeste || direccionActual == Noroeste) {
            {
				int oldLen = arboles->Length;
				array<Arbol^>^ tmp = gcnew array<Arbol^>(oldLen + 1);
				for (int i = 0; i < oldLen; i++) tmp[i] = arboles[i];
				tmp[oldLen] = gcnew Arbol(x - 5, y + sprites[0]->alto / 2);
				arboles = tmp;
			}
		}
		else if (direccionActual == Arriba) {
            {
				int oldLen = arboles->Length;
				array<Arbol^>^ tmp = gcnew array<Arbol^>(oldLen + 1);
				for (int i = 0; i < oldLen; i++) tmp[i] = arboles[i];
				tmp[oldLen] = gcnew Arbol(x + sprites[0]->ancho / 2, y - 5);
				arboles = tmp;
			}
		}
		else {
            {
				int oldLen = arboles->Length;
				array<Arbol^>^ tmp = gcnew array<Arbol^>(oldLen + 1);
				for (int i = 0; i < oldLen; i++) tmp[i] = arboles[i];
				tmp[oldLen] = gcnew Arbol(x + sprites[0]->ancho / 2, y + sprites[0]->alto + 5);
				arboles = tmp;
			}
		}

		semillas--;
	}

	bool verPorArboles() {
		for each (Arbol ^ arbol in arboles) {
			if (arbol->getEstaGerminando() || !arbol->getEstaVivo() || arbol->getMarcadorCrecer()) continue;
			totalArbolesGerminados++;
			arbol->setMarcadorCrecer(true);
		}

		if (totalArbolesGerminados >= 4) return true;
		return false;
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
	void setSemillas(int c) { semillas = c; }
	void setEnBote(bool p) { enBote = p; }

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
	bool getInvulnerable() { return invulnerable; }
	bool getTeclaEscape() { return tEscape; }
	int getSemillas() { return semillas; }
	bool getEnBote() { return enBote; }
	int getContadorInvulnerabilidad() { return contadorInvulnerabilidad; }
	array<Arbol^>^ getArboles() { return arboles; }
	int getTotalArbolesGerminados() { return totalArbolesGerminados; }
};