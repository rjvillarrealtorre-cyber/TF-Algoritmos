#pragma once

using namespace System::Drawing;

constexpr int TIEMPO_SLEEP = 75;
constexpr float CONVERSOR_SEG = (TIEMPO_SLEEP * 1.0 / 1000);
constexpr float CONVERSOR_CONT = (1000 / TIEMPO_SLEEP * 1.0);

inline bool verificarColision(System::Drawing::Rectangle a, System::Drawing::Rectangle b) {
	if (a.IntersectsWith(b)) return true;
	return false;
}