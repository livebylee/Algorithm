const fs = require('fs');
const input = fs.readFileSync("/dev/stdin").toString().trim();

const [W, H] = input.split(" ").map(Number);

const s = W * H / 2;
console.log(s.toFixed(1));    
