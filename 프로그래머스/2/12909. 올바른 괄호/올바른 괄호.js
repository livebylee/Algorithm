function solution(s){
    var answer = true;
    let tmp = 0;
    for (const char of s) {
        if(char =='('){
            tmp ++;
        }else{
            if(tmp <= 0) return answer = false;
            tmp --;
        }
    }
    if(tmp !== 0) answer = false;

    return answer;
}