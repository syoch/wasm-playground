#pragma once
#include "wrapper.hpp"

template <typename T>
void DrawRect(int x, int y, int w, int h, T color) {
  CallJSFunction("DrawRect", x, y, w, h, color);
}