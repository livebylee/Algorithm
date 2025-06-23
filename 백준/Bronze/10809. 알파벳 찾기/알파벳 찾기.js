let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split(' ');

let arr = [];
let result = '';

for (let i = 97; i <= 122; i++) {  //아스키코드 사용
  let alphabet = String.fromCharCode(i);

  for (let j = 0; j < input.length; j++) {
    arr.push(input[j].indexOf(alphabet));
  }
}
result = arr.join(' ');
console.log(result);