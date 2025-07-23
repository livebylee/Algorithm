const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().split(' ');

let r = parseInt(input[0]);
let s = parseInt(input[1]);
console.log(2*s-r);