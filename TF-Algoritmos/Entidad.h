#pragma once
#include "Sprite.h"

using namespace System;
using namespace System::Drawing;

// Direcciones
enum Direccion {
	Derecha, Izquierda, Arriba, Abajo,
	Suroeste, Sureste, Noroeste, Noreste,
	Quieto
};

//Clase
ref class Entidad {
protected:
	float escala;
	int x, y;
	int velocidad;

	array<Sprite^>^ sprites;
	bool moviendose;
	int direccionActual;
public:
	Entidad(int px, int py, int v) {
		escala = 1.6;
		x = px; y = py;
		velocidad = v;
		moviendose = false;
		direccionActual = 0;
	}

	~Entidad() {
		for (int i = 0; i < sprites->Length; i++) delete sprites[i];
		delete sprites;
	}

	virtual void mover() {
		switch (direccionActual) {
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

		if (direccionActual != Quieto) {
			sprites[direccionActual]->frames++;
			if (sprites[direccionActual]->frames > 5) sprites[direccionActual]->frames = 0;
		}
	}

	virtual void mostrar(Graphics^ gr) {
		Rectangle origen(
			sprites[direccionActual]->frames * sprites[direccionActual]->ancho,
			0,
			sprites[direccionActual]->ancho,
			sprites[direccionActual]->alto
		);

		Rectangle destino(
			x,
			y,
			sprites[direccionActual]->ancho * escala,
			sprites[direccionActual]->alto * escala
		);

		if (!moviendose) {
			gr->DrawImage(
				sprites[direccionActual]->spr,
				destino
			);
		}
		else {
			gr->DrawImage(
				sprites[direccionActual]->spr,
				destino,
				origen,
				GraphicsUnit::Pixel
			);
		}
	}

	//Setters y getters

	void setDir(char d) { direccionActual = d; }
	void setMov(bool d) { moviendose = d; }
	void setX(int px) { x = px; }
	void setY(int p) { y = p; }

	bool getMov() { return moviendose; }
	char getDir() { return direccionActual; }
	int getX() { return x; }
	int getY() { return y; }

	array<Sprite^>^ getSprites() { return sprites; }
};