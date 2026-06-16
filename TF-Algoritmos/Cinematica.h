#pragma once

using namespace System::Collections::Generic;
using namespace System::Drawing;
using namespace System;

ref class Slide {
private:
	List<String^>^ texto;
	Bitmap^ img;
public:
	Slide(List<String^>^ t, Bitmap^ i) {
		img = i;
		texto = t;
	}

	~Slide() {
		for each (String ^ s in texto) delete s;
		delete texto;
		delete img;
	}

	List<String^>^ getTexto() { return texto; }
	Bitmap^ getImg() { return img; }
};

ref class Cinematica {
private:
	List<Slide^>^ cinematica;
	int numSlide;
	bool enCinematica;
	bool dibujadoPrimeraVez;
	bool terminado;
public:
	Cinematica() {
		cinematica = gcnew List<Slide^>();
		numSlide = 0;
		enCinematica = true;
		dibujadoPrimeraVez = false;
		terminado = false;
	}

	~Cinematica() {
		for each (Slide ^ s in cinematica) delete s;
		delete cinematica;
	}

	void agregarSlide(List<String^>^ s, Bitmap^ img) {
		Slide^ nuevaSlide = gcnew Slide(s, img);
		cinematica->Add(nuevaSlide);
	}

	void mostrarSlide(Graphics^ gr, Font^ fuente) {
		gr->Clear(Color::Black);

		if (numSlide == 0) {
			gr->DrawImage(cinematica[numSlide]->getImg(), 88, 0, 1024, 514);
			return;
		}

		Bitmap^ perga = gcnew Bitmap("sprites\\otros\\papel_cinem.jpg");
		gr->DrawImage(perga, -10, -10, 540, 534);

		gr->DrawImage(cinematica[numSlide]->getImg(), 530, 0, 1200 - 530, 514);

		short centrarX = (530 - cinematica[numSlide]->getTexto()[0]->Length * 10) / 2 - 10;
		short centrarY = (514 - cinematica[numSlide]->getTexto()->Count * 19) / 2;

		for (int i = 0; i < cinematica[numSlide]->getTexto()->Count; i++) {
			gr->DrawString(
				cinematica[numSlide]->getTexto()[i],
				fuente,
				Brushes::Black,
				centrarX,
				centrarY + i * 19
			);
		}

		delete perga;
	}

	void manejarCambioSlide(Graphics^ gr, Font^ fuente, bool tDerecha, bool tDerechaAnterior, bool tIzquierda, bool tIzquierdaAnterior, bool tEscape) {
		if (tDerecha && !tDerechaAnterior) {
			if (numSlide >= cinematica->Count - 1) {
				enCinematica = false;
				terminado = true;
			}
			else {
				numSlide++;
				mostrarSlide(gr, fuente);
			}
		}
		else if (tIzquierda && (numSlide > 0) && !tIzquierdaAnterior) {
			numSlide--;
			mostrarSlide(gr, fuente);
		}
		else if (tEscape) {
			enCinematica = false;
			terminado = true;
		}
	}

	void setEnCinematica(bool p) { enCinematica = p; }
	bool getEnCinematica() { return enCinematica; }

	bool getTerminado() { return terminado; }
	void setTerminado(bool p) { terminado = p; }

	bool getDibujadoPrimeraVez() { return dibujadoPrimeraVez; }
	void setDibujadoPrimeraVez(bool p) { dibujadoPrimeraVez = p; }
};