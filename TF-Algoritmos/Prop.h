#pragma once

using namespace System::Drawing;

ref class Prop {
protected:
    Bitmap^ img;
    float escala;
    int ancho, alto;
    bool activo;
    int x, y;
    float velocidad;
    int dano;
public:
    Prop(Bitmap^ i, int px, int py, int v, float e) {
        img = i;
        escala = e;
        ancho = img->Width * escala;
        alto = img->Height * escala;
        activo = true;
        // DEFINIR DAÑO
        x = px; y = py;
        velocidad = v;
    }

    ~Prop() {
        delete img;
    }

    void mover() {
        x += velocidad;
    }

    void mostrar(Graphics^ gr) {
        gr->DrawImage(img, x, y, ancho, alto);
    }

    Rectangle getRectangle() { return Rectangle(x, y, ancho, alto); }

    bool getActivo() { return activo; }
    float getX() { return x; }
    float getY() { return y; }
    float getVelocidad() { return velocidad; }
    int getDano() { return dano; }

    void setX(float p) { x = p; }
};