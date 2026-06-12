#pragma once
#include "Mapa.h"
#include "Nivel.h"
#include "BuilderEntidadEstatica.h"

Mapa^ setupMapa1Nivel1() {
    Mapa^ mapa1 = gcnew Mapa(gcnew Bitmap("sprites\\escenarios\\nvl1mapa1.jpg"));

    mapa1->agregarEntidadEstatica(setupNINivel1Mapa1Lenador1());

    return mapa1;
}

Nivel^ setupNivel1() {
    // ------------------- Final ----------------

    Nivel^ nvl = gcnew Nivel();

    nvl->agregarMapa(setupMapa1Nivel1());

    //nvl->adjuntarCinematica({ setupCinNvl1Inicio(), setupCinNvl1Final() });

    return nvl;
}