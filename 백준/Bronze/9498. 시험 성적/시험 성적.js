const input = require('fs').readFileSync('/dev/stdin').toString();

const score = Number(input);

let result;

if(90 <= score  && score <= 100){
    result = 'A';
} else if(80 <= score && score <= 89){
    result = 'B';
} else if (70 <= score  && score <= 79){
    result = 'C';
} else if (60 <= score && score <= 69){
    result = 'D';
} else {
    result = 'F';
}

console.log(result);

