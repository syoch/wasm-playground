/** @type {HTMLElement}*/
let canvas;

/** @type {CanvasRenderingContext2D} */
let ctx;

function update_canvas_size() {
  canvas.width = canvas.clientWidth;
  canvas.height = canvas.clientHeight;
}

$(() => {
  canvas = document.getElementById("canvas");
  ctx = canvas.getContext('2d');
});

/**
 * Draw Rect on canvas
 * @param {number} a X coordinate of the first point
 * @param {number} b Y coordinate of the first point
 * @param {number} c X coordinate of the second point
 * @param {number} d Y coordinate of the second point
 * @param {string} color Fill color
 */
function DrawRect(a, b, c, d, color) {
  update_canvas_size();
  ctx.fillStyle = color;
  ctx.fillRect(a, b, c, d);
}
