#include <iostream>
#include <charconv>

#include "canvas.hpp"

extern "C" {
void EMSCRIPTEN_KEEPALIVE tick() {
  static int y = 0;

  for (int x = 0; x < 255; x++) {
    DrawPixel(x, y, (x | y) << 0x10 | (x ^ ~y) << 0x08 | (x ^ y));
  }

  y = (y + 1) % 256;
}
}
int main() {
  CallJSFunction("start_canvas_loop", 1);

  return 0;
}