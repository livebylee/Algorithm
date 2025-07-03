const input = require('fs').readFileSync('/dev/stdin').toString().trim();
//const input = require('fs').readFileSync('input.txt').toString().trim();

const stack = [];
let tmp = 1; //곱셈 계산 용
let result = 0;

for(let i = 0 ; i < input.length; i++){
    const now = input[i];

    if(now === '('){
        stack.push(now);
        tmp *= 2; 
    }else if(now === '['){
        stack.push(now);
        tmp *= 3;
    }else if(now ===')'){
        if(stack[stack.length-1]==='('){
            stack.pop();
            if(input[i-1]=='(') result += tmp;
            tmp /= 2;
        }else{
            stack.push(now);
        }
    }else if(now === ']'){
        if(stack[stack.length-1]==='['){
            stack.pop();
            if(input[i-1]=='[') result += tmp;
            tmp /= 3;
        }else{
            stack.push(now);
        }
    }
}
if(stack.length !==0 ) console.log(0);
else console.log(result);
