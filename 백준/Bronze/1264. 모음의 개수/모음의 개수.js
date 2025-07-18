const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const mo = ['a','e','i','o','u'];

for(let line of input){
    if(line.trim() === '#') break;
    let count = 0;
    for(let char of line.toLowerCase()){
        if(mo.includes(char)) count++;
    }
    console.log(count);
}