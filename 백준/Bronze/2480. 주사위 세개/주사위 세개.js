const input = require('fs').readFileSync('/dev/stdin').toString().split(' ').map(Number).sort();

const [a,b,c] = input;
let ans;

if (a === b && b === c) {
    ans = 10000 + a * 1000;
} else if (a === b || b === c) {
    if (a === b) {
        ans = 1000 + a * 100;
    } else if (b === c) {
        ans = 1000 + b * 100;
    }
} else if (a !== b && b !== c) { 
    ans = c * 100; // 오름차순 정렬 c가 제일 큼
}
console.log(ans);