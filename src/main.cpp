#include <iostream>

#include "canvas.hpp"

extern "C" {
void EMSCRIPTEN_KEEPALIVE tick() { std::cout << "tick" << std::endl; }
}
int main() {
  CallJSFunction("start_canvas_loop");
  DrawRect(0, 0, 100, 100, "red");

  ClearCanvas();
  return 0;
}