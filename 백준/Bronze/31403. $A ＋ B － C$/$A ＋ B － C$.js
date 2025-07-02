
const [a, b, c] = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');

console.log(Number(a) + Number(b) - Number(c));
console.log(a + b - c);