const fs = require("fs");

const { dataset, kms, prices } = require("./dataset");

let theta0 = 0;
let theta1 = 0;
const M = dataset.length;

const estimate = (val) => theta0 + theta1 * val;

const LEARNING_RATE = 0.01;

const learn = () => {
  for (let i = 0; i < M; i++) {
    const km = kms[i];
    const price = prices[i];

    const guess = estimate(km);

    const error = guess - price;

    theta0 -= error * LEARNING_RATE;
    theta1 -= error * km * LEARNING_RATE;
  }
};

const main = () => {
  for (let i = 0; i < 750; i++) {
    learn();
  }
  fs.writeFileSync("./model", JSON.stringify([theta0, theta1]));
  console.log("Model trained!");
};

main();
