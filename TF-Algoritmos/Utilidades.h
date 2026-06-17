#pragma once

constexpr int TIEMPO_SLEEP = 75;
constexpr float CONVERSOR_SEG = (TIEMPO_SLEEP * 1.0 / 1000);
constexpr float CONVERSOR_CONT = (1000 / TIEMPO_SLEEP * 1.0);

inline bool verificarColision(Rectangle a, Rectangle b) {
	if (a.IntersectsWith(b)) return true;
	return false;
}