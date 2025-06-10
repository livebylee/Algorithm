#include <iostream>

using namespace std;

string s;
bool ans = true;

void func(int start){
    if(start >= s.length()) return;
    //01
    if(start+1 < s.length() && s[start]=='0' && s[start+1] =='1'){
        func(start+2);
    }
    //100~1~
    else if(start+3 < s.length() && s[start]=='1' && s[start+1] == '0' && s[start+2]=='0'){
        start += 3;
        while(start < s.length() && s[start]=='0'){
            start++;
        }
        int onecnt = 0;
        while(start < s.length() && s[start]=='1'){
            start++;
            onecnt++;
        }
        if(onecnt==0){
            ans = false;
            return;
        }
        if(start < s.length()){
            if(start+2 < s.length() && onecnt > 1 && s[start] == '0' && s[start+1]=='0'){
                func(start-1);  //10이 이어져 나올경우 100~ 패턴의 가능성
            }else{
                func(start);
            }
        }
    }else{
        ans = false;
        return;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;
    
    func(0);
    if(ans == true) cout << "SUBMARINE";
    else cout <<"NOISE";
}