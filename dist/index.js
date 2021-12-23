_log = console.log;
console.log = function () {
  $('#console').append(arguments[0] + '<br>');
}