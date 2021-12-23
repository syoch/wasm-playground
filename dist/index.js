_log = console.log;
console.log = function () {
  $('#console').append('<p>' + arguments[0] + '</p>');
}