#pragma once
#include "Jugador.h"
#include "EntidadDinamica.h"
#include "Aliado.h"

using namespace System;

ref class Talador : public EntidadDinamica {
protected:
    float xO, yO;
    int arbolObjetivo;

    bool primeraVezHuye;
    bool enHuida;
    int contFramesHuida;
public:
    Talador(int px, int py, int v) : EntidadDinamica(px, py, v) {
        xO = px;
        yO = py;
        arbolObjetivo = -1;

        primeraVezHuye = true;
        enHuida = false;
        contFramesHuida = 0;

        sprites = gcnew array<Sprite^>(9);
        sprites[Quieto] = gcnew Sprite(gcnew Bitmap("sprites\\entidades\\talador_idle.png"), true);
        sprites[Derecha] = gcnew Sprite(gcnew Bitmap("sprites\\entidades\\talador_walkingsheet_right.png"));
        sprites[Izquierda] = gcnew Sprite(gcnew Bitmap("sprites\\entidades\\talador_walkingsheet_left.png"));
        sprites[Abajo] = gcnew Sprite(gcnew Bitmap("sprites\\entidades\\talador_walkingsheet_down.png"));
        sprites[Arriba] = gcnew Sprite(gcnew Bitmap("sprites\\entidades\\talador_walkingsheet_up.png"));
        sprites[Suroeste] = gcnew Sprite(gcnew Bitmap("sprites\\entidades\\talador_walkingsheet_southwest.png"));
        sprites[Sureste] = gcnew Sprite(gcnew Bitmap("sprites\\entidades\\talador_walkingsheet_southeast.png"));
        sprites[Noreste] = gcnew Sprite(gcnew Bitmap("sprites\\entidades\\talador_walkingsheet_northeast.png"));
        sprites[Noroeste] = gcnew Sprite(gcnew Bitmap("sprites\\entidades\\talador_walkingsheet_northwest.png"));
    }

    virtual ~Talador() {}

    void determinarObjetivo(List<Arbol^>^ arboles) {
        if (arboles->Count == 0 || enHuida) return;

        if ((arbolObjetivo != -1 && (!arboles[arbolObjetivo]->getEstaVivo() || !arboles[arbolObjetivo]->getEstaGerminando())) || (arbolObjetivo == -1)) {
            Random^ r = gcnew Random();
            arbolObjetivo = r->Next(arboles->Count);
            delete r;
        }
    }

    void irArboles(List<Arbol^>^ arboles) {
        if (enHuida) return;

        reiniciarEstado();

        if (arbolObjetivo == -1) return;

        if (arboles[arbolObjetivo]->getX() - x > 5) 
            movDerecha = true;
        else if (arboles[arbolObjetivo]->getX() - x < -5) 
            movIzquierda = true;

        if (arboles[arbolObjetivo]->getY() - y > 10)
            movAbajo = true;
        else if (arboles[arbolObjetivo]->getY() - y < -10) 
            movArriba = true;

        determinarDireccion();
    }

    void moverInicio() {
        reiniciarEstado();

        if (xO - x > 0) movDerecha = true;
        else if (xO - x < 0) movIzquierda = true;

        if (yO - y > 0) movAbajo = true;
        else if (yO - y < 0) movArriba = true;

        determinarDireccion();
    }

    void manejarEstado() {
        if (enHuida) contFramesHuida++;

        if (contFramesHuida >= 10 * CONVERSOR_CONT) {
            enHuida = false;
            primeraVezHuye = false;
        }
    }

    void manejarMovimiento(List<Arbol^>^ arboles) {
        if (enHuida) moverInicio();
        else irArboles(arboles);

        mover();
    }

    bool determinarCercaniaAliado(Aliado^ ali) {
        if ( ( (ali->getX() - x <= -80) || (ali->getX() + ali->getSprites()[0]->ancho - x <= 80) ) && ((ali->getY() - y <= -35) || (ali->getY() + ali->getSprites()[0]->alto - y <= 35)))
            return true;
        return false;
    }

    void sabotear(List<Arbol^>^ arboles, Aliado^ ali) {
        if (arbolObjetivo == -1) return;

        bool hayColision = verificarColision(arboles[arbolObjetivo]->getRectangle(), getRectangle());

        if (hayColision && determinarCercaniaAliado(ali)) {
            arboles[arbolObjetivo]->anadirMultiplicador();
            arboles[arbolObjetivo]->setVelocidadSabotaje(0.5 * (arboles[arbolObjetivo]->getMultiplicadorSabotaje() + 1 - 1));
            arboles[arbolObjetivo]->setSiendoSabotead(true);
        }
        else if (hayColision) {
            // ---
            arboles[arbolObjetivo]->anadirMultiplicador();
            arboles[arbolObjetivo]->setVelocidadSabotaje(1 * (arboles[arbolObjetivo]->getMultiplicadorSabotaje() + 1 - 1));
            arboles[arbolObjetivo]->setSiendoSabotead(true);
        }
        else if (!hayColision && arboles[arbolObjetivo]->getSiendoSaboteado()) {
            arboles[arbolObjetivo]->setSiendoSabotead(false);
        }
    }

    void verColisionJugador(Jugador^ jugador) {
        bool hayColision = verificarColision(getRectangle(), jugador->getRectangle());

        if (!hayColision) return;

        if (!jugador->getInvulnerable()) {
            jugador->setVida(jugador->getVida() - 10);
            jugador->setInvulnerable(true);
            invulnerable = true;
        }

        if (arbolObjetivo == -1 || jugador->getArboles()->Count == 0) return;

        if (arbolObjetivo >= 0 && jugador->getArboles()[arbolObjetivo]->getEstaVivo() && !invulnerable)
            jugador->getArboles()[arbolObjetivo]->setContFramesSabotear(jugador->getArboles()[arbolObjetivo]->getContFramesSabotear() - (3 / (1000 / TIEMPO_SLEEP)));
        if (primeraVezHuye) {
            reiniciarEstado();
            enHuida = true;
            jugador->getArboles()[arbolObjetivo]->setSiendoSabotead(false);
            arbolObjetivo = -1;
        }
    }

    void manejarTalador(Graphics^ gr, Jugador^ jugador, Aliado^ ali) {
        determinarObjetivo(jugador->getArboles());
        verColisionJugador(jugador);
        manejarEstado();
        manejarContador();
        manejarMovimiento(jugador->getArboles());
        sabotear(jugador->getArboles(), ali);
        mostrar(gr);
    }

};