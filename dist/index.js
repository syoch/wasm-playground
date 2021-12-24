var wasm_args = [];

console.log = function () {
  $('#console').append([...arguments].join(" ") + '<br>');
}