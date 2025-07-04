const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');

const n = input[0];
const arr = input[1].trim().split(' ');
const result = input[2].trim().split(' ');

const arrStr = arr.join('');
const reverseStr = arr.slice().reverse().join('');
const resultStr = result.join('');

const double = arrStr + arrStr;
const reversedouble = reverseStr + reverseStr;

if(double.includes(resultStr) || reversedouble.includes(resultStr)){
    console.log('good puzzle');
}else console.log('bad puzzle');
