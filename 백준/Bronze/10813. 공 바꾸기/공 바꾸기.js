const fs = require('fs');

const input = fs.readFileSync('dev/stdin').toString().trim().split('\n');

const [n, m] = input[0].trim().split(' ').map(Number);
const basket = [];

for (let i = 0; i < n; i++) {
  basket.push(i + 1);
}

for (let i = 0; i < m; i++) {
  const [a, b] = input[i + 1].trim().split(' ').map(Number);
  let temp = basket[a - 1];
  basket[a - 1] = basket[b - 1];
  basket[b - 1] = temp;
}

console.log(basket.join(' '));