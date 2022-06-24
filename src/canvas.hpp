#pragma once
#include "wrapper.hpp"

template <typename T>
void DrawRect(int x, int y, int w, int h, T color) {
  CallJSFunction("draw_rect", x, y, w, h, color);
}

// color: RGB u8
void DrawPixel(int x, int y, uint32_t color) {
  CallJSFunction("draw_pixel", x, y, color);
}

inline int GetCanvasWidth() { return EM_ASM_INT({return get_canvas_width()}); }

inline int GetCanvasHeight() {
  return EM_ASM_INT_V({return get_canvas_height()});
}

inline void ClearCanvas() { CallJSFunction("clear_canavs"); }