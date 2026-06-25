#pragma once
#include "Jugador.h"
#include "EntidadDinamica.h"
#include "Prop.h"

using namespace System;

ref class Disparo : public Prop {
public:
    Disparo(Bitmap^ i, int px, int py, float v) : Prop(i, px, py, v, 0.1) {
        dano = 15;
    }
};

// --------

ref class EnemigoBote : public EntidadDinamica {
protected:
    array<Disparo^>^ disparos;
    int contDisparos;
public:
    EnemigoBote(int px, int py, int v) : EntidadDinamica(px, py, v) {
        sprites = gcnew array<Sprite^>(9);
        disparos = gcnew array<Disparo^>(0);
        escala = 0.25;
        enBote = true;
        contDisparos = 0;
        
        for (int i = 0; i < 9; i++) sprites[i] = gcnew Sprite(gcnew Bitmap("sprites\\entidades\\enemigoBote.png"), true);
    }

    virtual ~EnemigoBote() {
        for each(Disparo ^ disparo in disparos) delete disparo;
        delete disparos;
    }

    void seguirJugador(Jugador^ jugador) {
        reiniciarEstado();

        if (jugador->getY() + jugador->getSprites()[jugador->getDir()]->alto * escala - y > 80)
            movAbajo = true;
        else if (jugador->getY() - y < -80)
            movArriba = true;

        determinarDireccion();
    }

    void disparar() {
        int oldLen = disparos->Length;
        array<Disparo^>^ tmp = gcnew array<Disparo^>(oldLen + 1);
        for (int i = 0; i < oldLen; i++) tmp[i] = disparos[i];
        tmp[oldLen] = gcnew Disparo(gcnew Bitmap("sprites\\entidades\\bala.png"), x + sprites[0]->ancho * 0.25 + 5, y + sprites[0]->alto * 0.25 / 2, 12);
        disparos = tmp;
    }

    void borrarDisparo(int i) {
        if (i >= disparos->Length) return;

        int oldLen = disparos->Length;
        if (oldLen == 0) return;

        delete disparos[i];

        array<Disparo^>^ tmp = gcnew array<Disparo^>(oldLen - 1);
        int k = 0;
        for (int j = 0; j < oldLen; j++) {
            if (j == i) continue;
            tmp[k++] = disparos[j];
        }
        disparos = tmp;
    }

    void manejarDisparos(Graphics^ gr) {
        contDisparos++;
        if (contDisparos >= 5 * CONVERSOR_CONT) {
            disparar();
            contDisparos = 0;
        }

        for (int i = 0; i < disparos->Length; i++) {
            disparos[i]->mover();
            disparos[i]->mostrar(gr);

            if (disparos[i]->getX() < 1020) continue;

            // Borrar
            borrarDisparo(i);
            i--;
        }
    }

    void manejarColisiones(Jugador^ jugador) {
        for (int i = 0; i < disparos->Length; i++) {
            if (!verificarColision(disparos[i]->getRectangle(), jugador->getRectangle())) continue;

            jugador->setVida(jugador->getVida() - disparos[i]->getDano());
            jugador->setInvulnerable(true);
            borrarDisparo(i);
            i--;
        }
    }

    void manejarEnemigoBote(Graphics^ gr, Jugador^ jugador) {
        manejarDisparos(gr);
        manejarColisiones(jugador);
        seguirJugador(jugador);
        mover();
        mostrar(gr);
    }

};