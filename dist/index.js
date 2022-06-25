function make_console_hook(name) {
  return function () {
    $('#console').append(name + ": " + [...arguments].join(" ") + '<br>');
  }
}

console.log = make_console_hook("log");
console.warn = make_console_hook("warn");
console.error = make_console_hook("error");
