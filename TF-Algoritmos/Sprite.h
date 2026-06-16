#pragma once
using namespace System::Drawing;

ref struct Sprite {
	Bitmap^ spr;
	int frames;
	int ancho;
	int alto;

	Sprite(Bitmap^ sp, bool estaQuieto) {
		spr = sp;
		frames = 0;

		ancho = spr->Width;
		alto = spr->Height;
	}

	Sprite(Bitmap^ sp) {
		spr = sp;
		frames = 0;

		ancho = spr->Width / 6;
		alto = spr->Height;
	}

	~Sprite() {
		delete spr;
	}
};
