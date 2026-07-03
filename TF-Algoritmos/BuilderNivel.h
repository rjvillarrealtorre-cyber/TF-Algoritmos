#pragma once
#include "Mapa.h"
#include "Nivel.h"
#include "BuilderCinematicas.h"
#include "BuilderEntidadEstatica.h"

Mapa^ setupMapa1Nivel1() {
    Mapa^ mapa1 = gcnew Mapa(gcnew Bitmap("sprites\\escenarios\\nvl1mapa1.jpg"),
        Point(260, 142), Point(950, 430));

    mapa1->agregarEntidadEstatica(setupNINivel1Mapa1Lenador1());

    return mapa1;
}

Mapa^ setupMapa2Nivel1() {
    Mapa^ mapa = gcnew Mapa(gcnew Bitmap("sprites\\escenarios\\nvl1mapa2.jpg"),
        Point(-100, 142), Point(950, 430));

    mapa->agregarEntidadEstatica(setupNINivel1Mapa2Wilmer());
    mapa->agregarEntidadEstatica(setupNINivel1Mapa2Rosa());
    mapa->agregarEntidadEstatica(setupNINivel1Mapa2Kevin());
    mapa->agregarEntidadEstatica(setupNINivel1Mapa2Tomas());

    return mapa;
}

Mapa^ setupMapa3Nivel1() {
    Mapa^ mapa = gcnew Mapa(gcnew Bitmap("sprites\\escenarios\\nvl1mapa3.png"),
        Point(-100, 142), Point(950, 430));

    mapa->agregarEntidadEstatica(setupNINivel1Mapa3Elena());
    mapa->agregarEntidadEstatica(setupNINivel1Mapa3Silvia());
    mapa->agregarEntidadEstatica(setupNINivel1Mapa3Clara());

    return mapa;
}

Mapa^ setupMapa4Nivel1() {
    Mapa^ mapa = gcnew Mapa(gcnew Bitmap("sprites\\escenarios\\nvl1mapa4.jpg"),
        Point(-100, 142), Point(763, 345));

    mapa->agregarEntidadEstatica(setupNINivel1Mapa4Timoteo());
    mapa->agregarEntidadEstatica(setupNINivel1Mapa4Jeremias());
    mapa->agregarEntidadEstatica(setupNINivel1Mapa4Maza());

    return mapa;
}

Mapa^ setupMapaNivel2() {
    Mapa^ mapa = gcnew Mapa(gcnew Bitmap("sprites\\escenarios\\nvl2.jpg"),
        Point(145, 83), Point(899, 430));

    // Coords del jugador: 800, 205
    mapa->agregarAliado(gcnew Aliado(740, 230, 10));
    mapa->agregarTalador(gcnew Talador(230, 130, 9));
    mapa->agregarTalador(gcnew Talador(190, 215, 9));

    return mapa;
}

Mapa^ setupMapaNivel3() {
    Mapa^ mapa = gcnew Mapa(gcnew Bitmap("sprites\\escenarios\\nvl3.jpg"),
        Point(260, 155), Point(899, 430));

    mapa->agregarEnemigoBote(gcnew EnemigoBote(50, 300, 10));

    return mapa;
}

Nivel^ setupNivel1() {
    // ------------------- Final ----------------

    Nivel^ nvl = gcnew Nivel("archivos\\bgm_action_1.wav");

    nvl->agregarMapa(setupMapa1Nivel1());
    nvl->agregarMapa(setupMapa2Nivel1());
    nvl->agregarMapa(setupMapa3Nivel1());
    nvl->agregarMapa(setupMapa4Nivel1());

    nvl->agregarCinematica(setupCinNvl1Inicio());
    nvl->agregarCinematica(setupCinNvl1Final());

    return nvl;
}

Nivel^ setupNivel2() {
    // ------------------- Final ----------------

    Nivel^ nvl = gcnew Nivel("archivos\\bgm_action_2.wav");

    nvl->agregarMapa(setupMapaNivel2());

    nvl->agregarCinematica(setupCinNvl2Inicio());
    nvl->agregarCinematica(setupCinNvl2Final());

    return nvl;
}

Nivel^ setupNivel3() {
    // ------------------- Final ----------------

    Nivel^ nvl = gcnew Nivel("archivos\\bgm_action_3.wav");

    nvl->agregarMapa(setupMapaNivel3());

    nvl->agregarCinematica(setupCinNvl3Inicio());
    nvl->agregarCinematica(setupCinNvl3Final());

    return nvl;
}