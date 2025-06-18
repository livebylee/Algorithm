
const fs = require("fs");
const [input, n] = fs.readFileSync("/dev/stdin").toString().trim().split('\n');

console.log(input.charAt(n-1));