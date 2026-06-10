#pragma once

using namespace System;

ref class Hud {
private:
	Bitmap^ img;
public:
	Hud() {
		img = gcnew Bitmap("sprites\\otros\\hud.png");
	}

	~Hud() {
		delete img;
	}

	void mostrarHud(Graphics^ gr) {
		gr->DrawImage(img, 885, -18, 322, 538);
	}

	void mostrarDatos(Graphics^ gr, Font^ fuente, 
		Jugador^ jugador, int nivelActual, int contador, int tiempoSleep) {
		int separacionLineas = 45;

		String^ vida = "[Vida]: " + jugador->getVida();
		gr->DrawString(
			vida,
			fuente,
			Brushes::White,
			965, separacionLineas + separacionLineas * 0
		);

		String^ confianza = "[Confianza]: " + jugador->getConfianza();
		gr->DrawString(
			confianza,
			fuente,
			Brushes::White,
			965, separacionLineas + separacionLineas * 1
		);

		String^ conLengua = "[Con Lengua]: " + jugador->getConocimiento();
		gr->DrawString(
			conLengua,
			fuente,
			Brushes::White,
			965, separacionLineas + separacionLineas * 2
		);

		String^ evidencia = "[Evidencia]: " + jugador->getEvidencia();
		gr->DrawString(
			evidencia,
			fuente,
			Brushes::White,
			965, separacionLineas + separacionLineas * 3
		);

		int nv = nivelActual + 1;
		String^ nivel = "[Nivel]: " + nv;
		gr->DrawString(
			nivel,
			fuente,
			Brushes::White,
			965, separacionLineas + separacionLineas * 4
		);

		int segundos = static_cast<int>(((tiempoSleep * 1.0 / 1000) * contador)) % 60;
		int minutos = ((tiempoSleep * 1.0 / 1000) * contador) / 60;
		String^ segMostrar = segundos < 10 ? "0" + segundos : "" + segundos;
		String^ minMostrar = minutos < 10 ? "0" + minutos : "" + minutos;

		String^ Tiempo = "[Tiempo]: " + minMostrar + ":" + segMostrar;
		gr->DrawString(
			Tiempo,
			fuente,
			Brushes::White,
			965, separacionLineas + separacionLineas * 5
		);

		// ¿Debería hacerlo?
		delete vida;
		delete confianza;
		delete conLengua;
		delete evidencia;
		delete nivel;
		delete segMostrar;
		delete minMostrar;
		delete Tiempo;
	}
};