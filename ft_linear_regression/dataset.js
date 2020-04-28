const fs = require("fs");

const dataset = fs
  .readFileSync("./data.csv", "utf-8")
  .split("\n")
  .reduce((acc, val, i, arr) => {
    if (i === 0 || i === arr.length - 1) {
      return acc;
    }
    return acc.concat([val.split(",").map(Number)]);
  }, []);

const kms = dataset
  .map((el) => el[0])
  .map((x, _, arr) => {
    return (x - Math.min(...arr)) / (Math.max(...arr) - Math.min(...arr));
  });

const prices = dataset
  .map((el) => el[1])
  .map((x, _, arr) => {
    return (x - Math.min(...arr)) / (Math.max(...arr) - Math.min(...arr));
  });

module.exports = { dataset, kms, prices };
