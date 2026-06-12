#pragma once
#include "Sprite.h"

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
	int dirI;
	int direccionActual;
public:
	Entidad(int px, int py, int v) {
		escala = 1.6;
		x = px; y = py;
		velocidad = v;
		moviendose = false;
		dirI = 0;
		direccionActual = 0;
	}

	~Entidad() {
		for (int i = 0; i < sprites->Length; i++) delete sprites[i];
		delete sprites;
	}

	void determinarIntPorDireccion() {
		direccionActual = dirI;
	}

	virtual void mover() = 0;

	void mostrar(Graphics^ gr) {
		determinarIntPorDireccion();

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

	void setDir(char d) { dirI = d; }
	void setMov(bool d) { moviendose = d; }
	void setX(int px) { x = px; }

	bool getMov() { return moviendose; }
	char getDir() { return dirI; }
	int getX() { return x; }
	int getY() { return y; }
};