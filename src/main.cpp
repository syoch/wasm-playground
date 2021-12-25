#include <emscripten.h>

#include <iostream>
#include <string>

template <typename T>
void PushArgument(T arg) {
  EM_ASM({ wasm_args.push($0); }, arg);
}

template <>
void PushArgument(const char *arg) {
  EM_ASM({ wasm_args.push(UTF8ToString($0)); }, arg);
}

template <typename T, typename... Args>
void CallJSFunction(T name, Args &&...args) {
  EM_ASM(wasm_args = [];);
  (PushArgument(args), ...);
  EM_ASM({ eval(UTF8ToString($0))(... wasm_args); }, name);
}

template <typename T>
void DrawRect(int x, int y, int w, int h, T color) {
  CallJSFunction("DrawRect", x, y, w, h, color);
}

int main() {
  CallJSFunction("console.log", 1, "Hello, world!");
  DrawRect(0, 0, 100, 100, "red");
  return 0;
}