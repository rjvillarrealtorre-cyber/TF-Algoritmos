#pragma once

using namespace System::Drawing;

ref class MenuC {
private:
	Bitmap^ fondo;
public:
	MenuC(Bitmap^ f) {
		fondo = f;
	}

	~MenuC() {
		delete fondo;
	}

	void mostrarFondo(Graphics^ gr) {
		gr->DrawImage(fondo, 0, 0, 1024, 576);
	}
};