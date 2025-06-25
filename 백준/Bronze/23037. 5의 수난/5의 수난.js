const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim();

let Sum = 0;
for(let i = 0 ; i < input.length; i++){
    Sum += Number(input[i]) ** 5
}

console.log(Sum);