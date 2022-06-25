#include <iostream>
#include <charconv>

#include "canvas.hpp"

extern "C" {
void tick() {
  static int t = 0;

  // for (int x = 0; x < canvas::GetWidth(); x++) {
  // canvas::DrawPixel(x, y, (~x ^ y) | t, (x ^ y) | t, (x ^ ~y) | t);
  // }

  auto image = canvas::GetImageData();
  auto data = image["data"];

  auto height = canvas::GetHeight();
  auto width = canvas::GetWidth();

  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      auto offset = 4 * (y * width + x);
      data.set(offset + 0, (~x ^ y) | t);
      data.set(offset + 1, (x ^ y) | t);
      data.set(offset + 2, (x ^ ~y) | t);
      data.set(offset + 3, 255);
    }
  }

  canvas::PutImageData(image);

  t += 1;
  if (t == 256) t = 0;
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