/** @type {HTMLElement}*/
let canvas;

/** @type {CanvasRenderingContext2D} */
let ctx;

$(() => {
  canvas = document.getElementById("canvas");
  ctx = canvas.getContext('2d');
});

function get_canvas_width() {
  return canvas.width;
}

function get_canvas_height() {
  return canvas.height;
}

function update_canvas_size() {
  if (canvas.clientWidth != canvas.width)
    canvas.width = canvas.clientWidth;
  if (canvas.clientHeight != canvas.height)
    canvas.height = canvas.clientHeight;
}

window.addEventListener('resize', update_canvas_size);


/**
 * Draw Rect on canvas
 * @param {number} x1 X coordinate of the first point
 * @param {number} y1 Y coordinate of the first point
 * @param {number} x2 X coordinate of the second point
 * @param {number} y2 Y coordinate of the second point
 * @param {*} color Fill color
 */
function draw_rect(x1, y1, x2, y2, _color) {
  update_canvas_size();
  ctx.fillStyle = _color.toString();
  ctx.fillRect(x1, y1, x2, y2);
}

/**
 * Put a pixel on canvas
 * @param {number} x X coordinate of the point
 * @param {number} y Y coordinate of the point
 * @param {number} color Fill color (RGB)
 */
function draw_pixel(x, y, _color) {
  update_canvas_size();

  let img = ctx.getImageData(x, y, 1, 1);
  img.data[0] = (_color >> 0x10) & 0xff;
  img.data[1] = (_color >> 0x08) & 0xff;
  img.data[2] = (_color >> 0x00) & 0xff;
  img.data[3] = 255;
  ctx.putImageData(img, x, y);
}

/**
 * Clear canvas
 */
function clear_canvas() {
  draw_rect(0, 0, canvas.width, canvas.height, "black");
}

function start_canvas_loop(time) {
  setInterval(() => {
    Module.ccall(
      'tick', // function name
      'void', // return type
      ['void'], // argument types
      [] // arguments
    );
  }, time);
}