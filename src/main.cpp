#include <iostream>
#include <charconv>

#include "canvas.hpp"

extern "C" {
void EMSCRIPTEN_KEEPALIVE tick() {
  static int y = 0;
  static int t = 0;

  for (int x = 0; x < canvas::GetWidth(); x++) {
    canvas::DrawPixel(x, y, (~x ^ y) | t, (x ^ y) | t, (x ^ ~y) | t);
  }

  y = y + 1;
  if (y == canvas::GetHeight()) {
    t = (t + 0x10) & 0xff;
    y = 0;
  }
}
}

int main() {
  std::cout << "Loading canvas variables" << std::endl;
  val document = val::global("document");
  canvas::canvas = document.call<val>("getElementById", "canvas"s);
  canvas::ctx = canvas::canvas.call<val>("getContext", "2d"s);

  std::cout << "Starting main loop" << std::endl;
  emscripten_set_main_loop(&tick, 1000, 0);

  return 0;
}