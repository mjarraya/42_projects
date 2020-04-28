function gradientDescentBatch(slope, yIntercept, data, learningRate = 0.01) {
  const { kms: normalizedKms, prices: normalizedPrices, M } = data;

  let yInterceptSum = 0;
  let slopeSum = 0;

  for (let i = 0; i < M; i++) {
    const x = normalizedKms[i];
    const y = normalizedPrices[i];

    const guess = slope * x + yIntercept;
    const error = guess - y;
    yInterceptSum += error;
    slopeSum += error * x;
  }
  yIntercept -= (learningRate / M) * yInterceptSum;
  slope -= (learningRate / M) * slopeSum;

  return { slope, yIntercept };
}

function gradientDescentStochastic(
  slope,
  yIntercept,
  data,
  learningRate = 0.01
) {
  const { kms: normalizedKms, prices: normalizedPrices, M } = data;

  for (let i = 0; i < M; i++) {
    const x = normalizedKms[i];
    const y = normalizedPrices[i];

    const guess = slope * x + yIntercept;
    const error = y - guess;

    slope = slope + error * x * learningRate;
    yIntercept = yIntercept + error * learningRate;
  }

  return { slope, yIntercept };
}

function normalize(x, _, arr) {
  return (x - Math.min(...arr)) / (Math.max(...arr) - Math.min(...arr));
}

try {
  module.exports = exports = {
    gradientDescentBatch,
    gradientDescentStochastic,
    normalize,
  };
} catch (e) {}
