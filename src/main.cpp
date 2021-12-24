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

void SetFunction(char *name) {
  EM_ASM({ wasm_func = UTF8ToString($0); }, name);
}

void CallFunction() {
  EM_ASM({ wasm_call(); });
}

template <typename... Args>
void CallJSFunction(char *name, Args &&...args) {
  (PushArgument(args), ...);
  SetFunction(name);
  CallFunction();
}

int main() {
  CallJSFunction("console.log", 1, "Hello, world!");
  return 0;
}