const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().split(' ');

let str = input.toString();
const result = str.charCodeAt(0);

console.log(result);
