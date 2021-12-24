var wasm_args = [];
var wasm_func = "";

function wasm_call() {
  eval(wasm_func)(...wasm_args);
}

_log = console.log;
console.log = function () {
  $('#console').append([...arguments].join(" ") + '<br>');
}