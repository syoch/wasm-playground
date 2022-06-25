#pragma once
#include "wrapper.hpp"

namespace std {
std::string to_string(const char* s) { return std::string(s); }
}  // namespace std

namespace canvas {

thread_local val ctx("0");
thread_local val canvas("0");

template <typename T>
void DrawRect(int x, int y, int w, int h, T color) {
  ctx.set("fillStyle", std::to_string(color));
  ctx.call<void>("fillRect", x, y, w, h);
}

inline void DrawPixel(int x, int y, uint8_t r, uint8_t g, uint8_t b) {
  val img = ctx.call<val>("getImageData", x, y, 1, 1);
  img["data"].set(0, r);
  img["data"].set(1, g);
  img["data"].set(2, b);
  img["data"].set(3, 255);
  ctx.call<void>("putImageData", img, x, y);
}

inline int GetWidth() { return canvas["width"].as<int>(); }

inline int GetHeight() { return canvas["height"].as<int>(); }

inline void Clear() { DrawRect(0, 0, GetWidth(), GetHeight(), "black"); }

inline val GetImageData() {
  return ctx.call<val>("getImageData", 0, 0, GetWidth(), GetHeight());
}

inline void PutImageData(val image) {
  ctx.call<void>("putImageData", image, 0, 0);
}

}  // namespace canvas