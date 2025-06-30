const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');

for(const rawstr of input){
    const str = rawstr.trim();
    if(str === '*') break;

    let isSur = true;

    for(let d = 1; d < str.length; d++){
        const seen = new Set();
        for(let startIdx = 0; startIdx < str.length-d; startIdx++){
            const pair = str[startIdx] + str[startIdx+d];
            if(seen.has(pair)){
                isSur = false;
                break;
            }
            seen.add(pair);
        }
        if(isSur===false) break;
    }
    if(isSur) console.log(`${str} is surprising.`);
    else console.log(`${str} is NOT surprising.`);
}