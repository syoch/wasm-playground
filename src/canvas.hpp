#pragma once
#include "wrapper.hpp"

template <typename T>
void DrawRect(int x, int y, int w, int h, T color) {
  CallJSFunction("draw_rect", x, y, w, h, color);
}

void ClearCanvas() { CallJSFunction("clear_canavs"); }