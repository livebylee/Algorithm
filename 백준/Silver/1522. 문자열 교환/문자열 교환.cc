#include <iostream>
#include <algorithm>
using namespace std;

string s;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> s;
    int acnt = 0;
    for(int i = 0; i< s.length(); i++){
        if(s[i] == 'a'){
            acnt++;
        }
    }
    int minans =100000;
    for(int i = 0; i< s.length(); i++){
        int cnt = 0;
        for(int j = 0; j< acnt; j++){
            int now = (i+j) % s.length();
            if(s[now] == 'b'){
                cnt++;
            }
        }
        minans = min(minans,cnt);
    }
    cout << minans;
}