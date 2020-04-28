let m = 0;
let b = 0;

function setup() {
  createCanvas(600, 400);
}

function draw() {
  background(200);

  drawPoints();
  drawLine();
  gradientDescent();
}

function drawPoints() {
  strokeWeight(5);

  const prices = dataset.map((el) => el[1]);
  const kms = dataset.map((el) => el[0]);

  for (let i = 0; i < data.kms.length; i++) {
    const x = data.kms[i] * width;
    const y = height - data.prices[i] * height;

    const displayX =
      data.kms[i] * (Math.max(...kms) - Math.min(...kms)) + Math.min(...kms);
    const displayY =
      data.prices[i] * (Math.max(...prices) - Math.min(...prices)) +
      Math.min(...prices);

    point(x, y);
    text(`${displayX}, ${displayY}`, x, y);
  }
  strokeWeight(1);
}

function gradientDescent() {
  const learningRate = 0.01;

  for (let i = 0; i < data.kms.length; i++) {
    const x = data.kms[i];
    const y = data.prices[i];

    const guess = m * x + b;
    const error = y - guess;

    m = m + error * x * learningRate;
    b = b + error * learningRate;
  }

  const spans = document.getElementsByTagName("span");
  spans[0].innerText = b.toFixed(5);
  spans[1].innerText = m.toFixed(5);
}

var minX = Math.min(...data.kms);
var maxX = Math.max(...data.kms);
var minY = Math.min(...data.prices);
var maxY = Math.max(...data.prices);

function drawLine() {
  // Draw a line between any two points (use min and max x)
  let x1 = minX;
  let y1 = m * x1 + b;
  let x2 = maxX;
  let y2 = m * x2 + b;

  // Map points to pixel space
  x1 = map(x1, minX, maxX, 0, width);
  x2 = map(x2, minX, maxX, 0, width);
  y1 = map(y1, minY, maxY, height, 0);
  y2 = map(y2, minY, maxY, height, 0);

  line(x1, y1, x2, y2);
}
