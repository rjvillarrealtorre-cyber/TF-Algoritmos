#pragma once
#include "Jugador.h"

using namespace System;


ref class Dialogo;

// Opciones
ref struct Opcion {
	String^ texto;
	array<int>^ efectos; // {confianza, lengua, evidencia}
	int siguienteDialogo;
	int confianzaReq = 0;
	int lenguaReq = 0;
	bool acabaNivel;

	// Con todos los requerimentos
	Opcion(String^ t, array<int>^ ef, int sd, int cr, int lr, bool an) {
		texto = t;
		efectos = ef;
		siguienteDialogo = sd;
		confianzaReq = cr;
		lenguaReq = lr;
		acabaNivel = an; // DEFAULT: FALSO
	}

	//Requiere confianza
	Opcion(String^ t, array<int>^ ef, int sd, int cr) {
		texto = t;
		efectos = ef;
		siguienteDialogo = sd;
		confianzaReq = cr;
		lenguaReq = 0;
		acabaNivel = false; // DEFAULT: FALSO
	}

	//Estandar
	Opcion(String^ t, array<int>^ ef, int sd) {
		texto = t;
		efectos = ef;
		siguienteDialogo = sd;
		confianzaReq = 0;
		lenguaReq = 0;
		acabaNivel = false; // DEFAULT: FALSO
	}

	~Opcion() {
		delete efectos;
		delete texto;
	}
};

ref class Dialogo {
private:
    array<String^>^ lineas;

	bool poderElegir;
	int eleccion;
    array<Opcion^>^ opciones;

	int sigDialogo;
	bool estaEnEspanol;
	int alturaDialogo;

	int randNum;

	// Generado con IA (Github Copilot)
	// Métodos de inicialización para evitar argumentos por defecto
    void initNoElegir(array<String^>^ l, int sd, bool eee) {
		lineas = l;
		opciones = gcnew array<Opcion^>(0);
		poderElegir = false;
		eleccion = -1;
		sigDialogo = sd;
		estaEnEspanol = eee;
		alturaDialogo = 0;
		Random^ rand = gcnew Random();
		randNum = rand->Next(1, 101);
	}

    void initConOpciones(array<String^>^ l, array<Opcion^>^ opc, bool eee) {
		lineas = l;
		poderElegir = true;
		opciones = opc;
		eleccion = -1;
		sigDialogo = -1;
		estaEnEspanol = eee;
		alturaDialogo = 0;
		Random^ rand = gcnew Random();
		randNum = rand->Next(1, 101);
	}

public:
	// Sobrecarga de constructores para evitar el molesto error
	// "no se permite argumentos predeterminados"
	Dialogo(array<String^>^ l, int sd, bool eee) {
		initNoElegir(l, sd, eee);
	}
	Dialogo(array<String^>^ l) { // equivalente a sd = -1, eee = true
		initNoElegir(l, -1, true);
	}

	Dialogo(array<String^>^ l, array<Opcion^>^ opc, bool eee) {
		initConOpciones(l, opc, eee);
	}
	Dialogo(array<String^>^ l, array<Opcion^>^ opc) { // equivalente a eee = true
		initConOpciones(l, opc, true);
	}

	// ---- FIN DE LOS CONSTRUCTORES ---

	~Dialogo() {
		for each (String ^ s in lineas) delete s;
		for each (Opcion ^ o in opciones) delete o;
		delete lineas;
		delete opciones;
	}

    void agregarLinea(String^ l) {
		int old = (lineas == nullptr) ? 0 : lineas->Length;
		Array::Resize<String^>(lineas, old + 1);
		lineas[old] = l;
	}

	void mostrarLineas(Graphics^ gr, Font^ fuente, Point^ cuadro, int numConLengua) { //Imprime el diálogo en la pantalla
		short centrarX = (900 - lineas[0]->Length * 10) / 2;
        short centrarY = (155 - (lineas->Length + opciones->Length) * 19) / 2;

		for (int i = 0; i < lineas->Length; i++) {
			if (!estaEnEspanol && (lineas[i]->ToCharArray()[0] != '[' && lineas[i]->ToCharArray()[0] != '|')) {
				for (int j = 0; j < lineas[i]->Length; j++) {
					if (lineas[i]->ToCharArray()[j] == ' ' || lineas[i]->ToCharArray()[j] == ',' ||
						lineas[i]->ToCharArray()[j] == '.' || (lineas[i]->ToCharArray()[j] >= 65 && lineas[i]->ToCharArray()[j] <= 90) ||
						lineas[i]->ToCharArray()[j] == ':') {
						String^ caracter = gcnew String(lineas[i]->ToCharArray(), j, 1);
						gr->DrawString(caracter, fuente, Brushes::Black, cuadro->X + centrarX + j * 10, cuadro->Y + centrarY + i * 18);
					}
					else if (randNum <= numConLengua) {
						String^ caracter = gcnew String(lineas[i]->ToCharArray(), j, 1);
						gr->DrawString(caracter, fuente, Brushes::Black, cuadro->X + centrarX + j * 10, cuadro->Y + centrarY + i * 18);
					}
					else {
						gr->DrawString("?", fuente, Brushes::Black, cuadro->X + centrarX + j * 10, cuadro->Y + centrarY + i * 18);
					}
					alturaDialogo = cuadro->Y + centrarY + i * 18;
				}
			}
			else {
				alturaDialogo = cuadro->Y + centrarY + i * 18;
				gr->DrawString(lineas[i], fuente, Brushes::Black, cuadro->X + centrarX, alturaDialogo);
			}
		}

        for (int i = 0; i < opciones->Length; i++) {
			String^ texto = (i + 1) + ": " + opciones[i]->texto;
			gr->DrawString(texto, fuente, Brushes::Black, cuadro->X + centrarX, alturaDialogo + 18 * (i + 1) );
		}
	}

	//elegir: Maneja la lógica de la elección
	void elegir(Jugador^ jugador, array<bool>^ teclasOpciones, array<bool>^ teclasOpcionesAnterior) {
		// Ve si el jugador ha presionado ciertos botones
		if (teclasOpciones[0] && !teclasOpcionesAnterior[0]) eleccion = 1;
		else if (teclasOpciones[1] && !teclasOpcionesAnterior[1]) eleccion = 2;
		else if (teclasOpciones[2] && !teclasOpcionesAnterior[2]) eleccion = 3;
		else if (teclasOpciones[3] && !teclasOpcionesAnterior[3]) eleccion = 4;

		if (eleccion == -1) return;

		//Comprobación...
		//Si la elección es mayor que las opciones disponibles: elección inválida
		if (eleccion > opciones->Length) {
			eleccion = -1;
			return;
		}

		Opcion^ op = opciones[eleccion - 1];

		//Si no se logran los requerimientos necesarios...
		if (jugador->getConfianza() < op->confianzaReq || jugador->getConocimiento() < op->lenguaReq) {
			eleccion = -1;
			return;
		}

		//Llamando a determinarConsecuencia...
		if (eleccion != -1) determinarConsecuencia(jugador, op);
	}

	void determinarConsecuencia(Jugador^ jugador, Opcion^ op) {
		if (!poderElegir || eleccion == -1) return;

		jugador->setConfianza(jugador->getConfianza() + op->efectos[0]);
		jugador->setConocimiento(jugador->getConocimiento() + op->efectos[1]);
		jugador->setEvidencia(jugador->getEvidencia() + op->efectos[2]);
	}

	// Para "borrar el caché" y que el sistema se restaure con cada nueva elección
	void resetEleccion() { eleccion = -1; }

	//Setters y getters

	int getEleccion() { return eleccion; }
	bool getPoderElegir() { return poderElegir; }
	int getSiguienteDialogo() { return sigDialogo; }

	Opcion^ getOpcionElegida() {
		return opciones[eleccion - 1];
	}
};

// Lo realmente importante
ref class ArbolDialogo {
private:
	array<Dialogo^>^ arbol; // -> Conjunto de interacciones
	// Una interacción sería: array<Dialogo> interaccion;
	int numDialogo;
public:
	ArbolDialogo(array<Dialogo^>^ a) {
		numDialogo = 0;
		arbol = a;
	}

    ArbolDialogo() {
		numDialogo = 0;
		arbol = gcnew array<Dialogo^>(0);
	}

	~ArbolDialogo() {
		for each (Dialogo ^ d in arbol) delete d;
		delete arbol;
	}

    // Para el setup...
	void agregarDialogo(Dialogo^ d) {
		int old = (arbol == nullptr) ? 0 : arbol->Length;
		Array::Resize<Dialogo^>(arbol, old + 1);
		arbol[old] = d;
	}

	// Imprime la interacción en la panatalla
	void mostrarDialogo(Graphics^ gr, Font^ fuente, Point^ cuadro, int numConLengua) {
		if (numDialogo >= arbol->Length || numDialogo < 0) return;

		arbol[numDialogo]->mostrarLineas(gr, fuente, cuadro, numConLengua);
	}

	// Función más importante. Se encarga del funcionamiento
	// de cada interacción.
	bool manejarFlujoInteraccion(Graphics^ gr, Font^ fuente, Point^ cuadro, bool teclaE, array<bool>^ teclasOpciones, array<bool>^ teclasOpcionesAnterior, Jugador^ jugador) {
		Dialogo^ d = arbol[numDialogo];

		mostrarDialogo(gr, fuente, cuadro, jugador->getConocimiento());

		// Caso sin elección (avanza con E)
		if (!d->getPoderElegir() && teclaE) {
			if (d->getSiguienteDialogo() != -1)
				numDialogo = d->getSiguienteDialogo();
			else
				numDialogo++;

			if (numDialogo >= arbol->Length)
				numDialogo = 0;
		}
		// Caso con opciones
		else if (d->getPoderElegir()) {
			d->elegir(jugador, teclasOpciones, teclasOpcionesAnterior);

			if (d->getEleccion() == -1) return false;

			Opcion^ op = d->getOpcionElegida();

			d->resetEleccion();

			if (op->acabaNivel) return true;

			// cambiar al siguiente nodo según opción
			numDialogo = op->siguienteDialogo;

			if (numDialogo >= arbol->Length) numDialogo = 0;
		}
		return false;
	}

	array<Dialogo^>^ getArbol() { return arbol; }
};