const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const [N, M] = input[0].split(' ').map(Number);
const A = input.slice(1, 1 + N).map(Number);
const queries = input.slice(1 + N).map(Number);

const B = [...A].sort((a, b) => a - b);

const indexMap = new Map();
for (let i = 0; i < B.length; i++) {
    if (!indexMap.has(B[i])) {
        indexMap.set(B[i], i);
    }
}

const result = queries.map(d => indexMap.has(d) ? indexMap.get(d) : -1);
console.log(result.join('\n'));
