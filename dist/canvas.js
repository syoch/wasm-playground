/** @type {HTMLElement}*/
let canvas;

$(() => {
  canvas = document.getElementById("canvas");
});

function update_canvas_size() {
  if (canvas.clientWidth != canvas.width)
    canvas.width = canvas.clientWidth;
  if (canvas.clientHeight != canvas.height)
    canvas.height = canvas.clientHeight;
}

window.addEventListener('resize', update_canvas_size);