const input = require('fs').readFileSync('/dev/stdin').toString().trim().split("");

let starIdx = input.indexOf('*');
let sum = 0;

for (let i = 0; i < 13; i++) {
    if (i === starIdx) continue;

    let weight = (i % 2 === 0) ? 1 : 3;
    sum += parseInt(input[i]) * weight;
}

// 이제 0~9를 대입해서 체크
for (let x = 0; x <= 9; x++) {
    let weight = (starIdx % 2 === 0) ? 1 : 3;
    let total = sum + x * weight;

    if (total % 10 === 0) {
        console.log(x);
        break;
    }
}