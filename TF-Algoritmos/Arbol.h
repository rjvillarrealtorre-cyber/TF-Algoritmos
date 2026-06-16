#pragma once
#include "Utilidades.h"
#include "Entidad.h"

using namespace System::Drawing;

ref class Arbol : public Entidad {
private:
	int alto, ancho;
	bool vivo;
	bool germinando;
	bool siendoSaboteado;
	int contadorGerminar;
	int contadorSabotear;
	float velocidadSabotaje;

	int contFramesGerminar;
	float contFramesSabotear;

	int multiplicadorSabotaje; // # enemigos en el árbol
public:
	Arbol(int px, int py) : Entidad(px, py, 0) {
		x = px; y = py;

		sprites = gcnew array<Sprite^>(4);
		sprites[0] = gcnew Sprite(gcnew Bitmap("sprites\\entidades\\tallo1.png"), true);
		sprites[1] = gcnew Sprite(gcnew Bitmap("sprites\\entidades\\tallo2.png"), true);
		sprites[2] = gcnew Sprite(gcnew Bitmap("sprites\\entidades\\tallo3.png"), true);
		sprites[3] = gcnew Sprite(gcnew Bitmap("sprites\\entidades\\tallo4.png"), true);
		direccionActual = 0; // Equivalente a "spriteActual"
		escala = 0.6;

		alto = sprites[0]->alto * escala;
		ancho = sprites[0]->ancho * escala;

		vivo = true;
		germinando = true;
		siendoSaboteado = false;
		contadorGerminar = 0;
		contadorSabotear = 0;
		contFramesGerminar = 0;
		contFramesSabotear = 0;
		multiplicadorSabotaje = 0;
	}

	void mover() override {}

	void mostrar(Graphics^ gr) override {
		Rectangle destino(
			x,
			y,
			ancho,
			alto
		);

		gr->DrawImage(
			sprites[direccionActual]->spr,
			destino
		);
	}

	void manejarVida() {
		if (contadorSabotear >= 10 && germinando) {
			vivo = false;
			germinando = false;
			siendoSaboteado = false;

			direccionActual = 0;
		}
	}

	void manejarContadores() {
		if (!vivo) return;
		if (!germinando) return;

		if (siendoSaboteado) contFramesSabotear += velocidadSabotaje;
		contFramesGerminar++;

		contadorGerminar = contFramesGerminar / CONVERSOR_CONT;
		if (siendoSaboteado) contadorSabotear = contFramesSabotear / CONVERSOR_CONT;
	}

	void mostrarContadores(Graphics^ gr, Font^ fuente) {
		if (!vivo) return;
		if (!germinando) return;

		gr->DrawString("G:" + contadorGerminar, fuente, Brushes::Green, x + ancho / 5, y + alto);

		gr->DrawString("S:" + contadorSabotear, fuente, Brushes::Red, x + ancho / 5, y - 18);
	}

	void recalcularDimensiones() {
		ancho = sprites[direccionActual]->ancho * escala;
		alto = sprites[direccionActual]->alto * escala;
	}

	void cambiarSprites() {
		if (!vivo) return;
		if (!germinando) return;

		if (contadorGerminar >= 5 && contadorGerminar < 10) {
			direccionActual = 1;
			recalcularDimensiones();
		}
		else if (contadorGerminar >= 10 && contadorGerminar < 20) {
			direccionActual = 2;
			recalcularDimensiones();
		}
		else if (contadorGerminar >= 20) {
			direccionActual = 3;
			recalcularDimensiones();
			germinando = false;
		}
	}

	void manejarCrecimiento(Graphics^ gr, Font^ fuente) {
		if (!vivo) return;

		multiplicadorSabotaje = 0;

		manejarVida();
		manejarContadores();
		mostrarContadores(gr, fuente);
		cambiarSprites();

		velocidadSabotaje = 1;
	}

	bool getEstaVivo() { return vivo; }
	bool getEstaGerminando() { return germinando; }
	void setSiendoSabotead(bool p) { siendoSaboteado = p; }
	bool getSiendoSaboteado() { return siendoSaboteado; }

	int getContFramesSabotear() { return contFramesSabotear; }
	void setContFramesSabotear(int p) { contFramesSabotear = p; }

	void setVelocidadSabotaje(float p) { velocidadSabotaje = p; }
	int getMultiplicadorSabotaje() { return multiplicadorSabotaje; }
	void setMultiplicadorSabotaje(int p) { multiplicadorSabotaje = p; }

	void anadirMultiplicador() { multiplicadorSabotaje++; }
};