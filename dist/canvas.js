/** @type {HTMLElement}*/
let canvas;

/** @type {CanvasRenderingContext2D} */
let ctx;

$(() => {
  canvas = document.getElementById("canvas");
  ctx = canvas.getContext('2d');
});

function update_canvas_size() {
  canvas.width = canvas.clientWidth;
  canvas.height = canvas.clientHeight;
}

window.addEventListener('resize', update_canvas_size);


/**
 * Draw Rect on canvas
 * @param {number} a X coordinate of the first point
 * @param {number} b Y coordinate of the first point
 * @param {number} c X coordinate of the second point
 * @param {number} d Y coordinate of the second point
 * @param {*} color Fill color
 */
function draw_rect(a, b, c, d, _color) {
  update_canvas_size();
  ctx.fillStyle = _color.toString();
  ctx.fillRect(a, b, c, d);
}

/**
 * Clear canvas
 */
function clear_canvas() {
  draw_rect(0, 0, canvas.width, canvas.height, "black");
}

/**
 * Get Canvas size
 * @returns {number[]} [width, height]
 */
function get_canvas_size() {
  return [canvas.width, canvas.height];
}

function start_canvas_loop() {
  setInterval(() => {
    Module.ccall(
      'tick', // function name
      'void', // return type
      ['void'], // argument types
      [] // arguments
    );
  }, 50 / 3);
}