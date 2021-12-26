#include <iostream>

#include "canvas.hpp"

extern "C" {
void EMSCRIPTEN_KEEPALIVE tick() {
  static int i = 0;

  if (i % 2 == 0) {
    DrawRect(0, 0, 100, 100, "red");
  }
  if (i % 2 == 1) {
    DrawRect(0, 0, 100, 100, "blue");
  }

  i++;
}
}
int main() {
  CallJSFunction("start_canvas_loop", 250);

  return 0;
}