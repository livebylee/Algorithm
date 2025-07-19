const input = require('fs').readFileSync('/dev/stdin').toString();

const n = Number(input);
let output = '';
for(let i = 1; i <= n; i++){
    output = '*'.repeat(i);
    console.log(output);
}

