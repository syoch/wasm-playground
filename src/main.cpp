#include <emscripten.h>

#include <iostream>

template <typename T>
void PushArgument(T arg) {
  EM_ASM({ wasm_args.push($0); }, arg);
}

template <>
void PushArgument(const char *arg) {
  EM_ASM({ wasm_args.push(UTF8ToString($0)); }, arg);
}

template <typename... Args>
void CallJSFunction(char *name, Args &&...args) {
  (PushArgument(args), ...);
  EM_ASM({ eval(UTF8ToString($0))(... wasm_args); }, name);
}

int main() {
  CallJSFunction("console.log", 1, "Hello, world!");
  return 0;
}