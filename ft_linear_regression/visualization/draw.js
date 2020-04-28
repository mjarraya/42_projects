let yIntercept = 0; // or b, or theta0
let slope = 0; // or m, or theta1
let learningRate = 0.01;

const M = data.length;

const kms = data.map((el) => el[0]);
const normalizedKms = kms.map(normalize);

const prices = data.map((el) => el[1]);
const normalizedPrices = prices.map(normalize);

const minX = Math.min(...normalizedKms);
const maxX = Math.max(...normalizedKms);
const minY = Math.min(...normalizedPrices);
const maxY = Math.max(...normalizedPrices);

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

  for (let i = 0; i < M; i++) {
    const x = normalizedKms[i] * width;
    const y = height - normalizedPrices[i] * height;

    const displayX = kms[i];
    const displayY = prices[i];

    point(x, y);
    text(`${displayX}, ${displayY}`, x, y);
  }
  strokeWeight(1);
}

function gradientDescent() {
  const batch = document.getElementById("batch").checked;

  const fn = batch ? gradientDescentBatch : gradientDescentStochastic;

  ({ slope, yIntercept } = fn(
    slope,
    yIntercept,
    {
      kms: normalizedKms,
      prices: normalizedPrices,
      M,
    },
    learningRate
  ));
  i++;
  document.querySelector("span.theta0").innerText = yIntercept.toFixed(5);
  document.querySelector("span.theta1").innerText = slope.toFixed(5);
  document.querySelector("span.counter").innerText = i;
}

function drawLine() {
  let x1 = minX;
  let y1 = slope * x1 + yIntercept;
  let x2 = maxX;
  let y2 = slope * x2 + yIntercept;

  x1 = map(x1, minX, maxX, 0, width);
  x2 = map(x2, minX, maxX, 0, width);
  y1 = map(y1, minY, maxY, height, 0);
  y2 = map(y2, minY, maxY, height, 0);

  line(x1, y1, x2, y2);
}

let i = 0;
document.getElementById("batch").onchange = function () {
  yIntercept = 0;
  slope = 0;
  i = 0;
};

document.getElementById("rate").onchange = function (e) {
  yIntercept = 0;
  slope = 0;
  i = 0;
  learningRate = Number(e.target.value);
  document.querySelector("span.rate").innerText = learningRate;
};
