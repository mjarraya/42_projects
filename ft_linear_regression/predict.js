const readline = require("readline");
const fs = require("fs");
const { dataset } = require("./dataset");
const verify = (answer, rl) => {
  if (Number.isNaN(Number.parseInt(answer, 10))) {
    console.log("Numbers only!");
    process.exit();
  }
};

const readModel = () => {
  try {
    fs.accessSync("./model");
    // console.log("Existing model found");
    const model = JSON.parse(fs.readFileSync("./model", "utf-8"));
    return model;
  } catch (err) {
    // console.log("Creating model");
    fs.writeFileSync("./model", JSON.stringify([0, 0]));
    return [0, 0];
  }
};

const main = () => {
  const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
  });

  rl.question("What is the mileage of the car ? (in km)\n", (answer) => {
    verify(answer, rl);
    console.log(`The car's mileage is: ${answer}km`);

    const [theta0, theta1] = readModel();
    // theta1: m
    // theta0: b

    const prices = dataset.map((el) => el[1]);
    const kms = dataset.map((el) => el[0]);

    answer =
      (answer - Math.min(...kms)) / (Math.max(...kms) - Math.min(...kms));

    let estimate = theta0 + theta1 * answer;
    console.log(estimate);
    estimate =
      estimate * (Math.max(...prices) - Math.min(...prices)) +
      Math.min(...prices);
    console.log(estimate);
    console.log(`Estimated price is ${estimate}`);
    rl.close();
  });
};

main();
