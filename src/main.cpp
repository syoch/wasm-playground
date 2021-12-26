#include <iostream>

#include "canvas.hpp"

extern "C" {
void EMSCRIPTEN_KEEPALIVE tick() {
  static int i = 0;
  i++;
  if (i % 30 != 0) {
    return;
  }

  if (i % 60 == 0) {
    DrawRect(0, 0, 100, 100, "red");
  }
  if (i % 60 == 30) {
    DrawRect(0, 0, 100, 100, "blue");
  }
}
}
int main() {
  CallJSFunction("start_canvas_loop");

  return 0;
}