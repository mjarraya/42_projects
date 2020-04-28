const readline = require("readline");
const fs = require("fs");
const { dataset } = require("./dataset");
const { normalize } = require("./lib");

const verify = (answer, rl) => {
  if (Number.isNaN(parseInt(answer, 10))) {
    console.log("Numbers only!");
    process.exit();
  }
  if (answer < 0) {
    console.log("Kms cannot be negative");
    process.exit();
  }
};

const readModel = () => {
  try {
    fs.accessSync("./model");
    const model = JSON.parse(fs.readFileSync("./model", "utf-8"));
    return model;
  } catch (err) {
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
    // theta0: b, or yIntercept
    // theta1: m, or slope

    const prices = dataset.map((el) => el[1]);
    const kms = dataset.map((el) => el[0]);

    answer = normalize(answer, null, kms);

    let estimate = theta0 + theta1 * answer;
    estimate = Math.max(
      0,
      estimate * (Math.max(...prices) - Math.min(...prices)) +
        Math.min(...prices)
    );

    console.log(`Estimated price is ${parseInt(estimate, 10)}`);
    rl.close();
  });
};

main();
