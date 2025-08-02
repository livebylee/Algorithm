const input = require('fs').readFileSync('/dev/stdin').toString().split('\n');

let i = 0;
let answer = "";

while (i <= input.length - 1) {
    let a = parseInt(input[i].split(' ')[0]);
    let b = parseInt(input[i].split(' ')[1]);
    
    if (a !== 0 || b !== 0) {
        answer += `${a + b}` +'\n';
    } else break;
    i++;
}
console.log(answer);