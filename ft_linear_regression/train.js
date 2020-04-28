const fs = require("fs");

const { dataset } = require("./dataset");
const {
  normalize,
  gradientDescentStochastic,
  gradientDescentBatch,
} = require("./lib");

const learn = (theta0, theta1, data, batch) => {
  const { kms, prices, M } = data;

  const fn = batch ? gradientDescentBatch : gradientDescentStochastic;

  ({ yIntercept: theta0, slope: theta1 } = fn(theta1, theta0, {
    kms,
    prices,
    M,
  }));
  return { theta0, theta1 };
};

const main = () => {
  const batch = process.argv.slice(2).includes("--batch");

  const kms = dataset.map((el) => el[0]).map(normalize);
  const prices = dataset.map((el) => el[1]).map(normalize);

  let theta0 = 0;
  let theta1 = 0;
  const M = dataset.length;

  const iterations = batch ? 10000 : 750;

  for (let i = 0; i < iterations; i++) {
    ({ theta0, theta1 } = learn(theta0, theta1, { kms, prices, M }, batch));
  }

  fs.writeFileSync("./model", JSON.stringify([theta0, theta1]));

  console.log(
    `Model trained!\ntheta0: ${theta0.toFixed(5)}, theta1: ${theta1.toFixed(5)}`
  );
};

main();
