#pragma once
#include <emscripten.h>

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