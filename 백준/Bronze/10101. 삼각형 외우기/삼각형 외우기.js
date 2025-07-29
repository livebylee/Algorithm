const input = require('fs').readFileSync('/dev/stdin').toString().split('\n');

const a = Number(input[0]);
const b = Number(input[1]);
const c = Number(input[2]);

if(a+b+c ===180){
    if(a===60 && b===60 && c===60) console.log("Equilateral");
    else if(a==b || b==c || a==c) console.log("Isosceles");
    else console.log("Scalene");
}else console.log("Error");

