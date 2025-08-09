#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int n;
string s;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    cin >> s;

    string best = s;
    sort(best.begin(), best.end(),greater<char>());  // 사전순으로 가장 큰 문자열

    int i = 0;           // best와 원본 비교해서 처음 다른 지점 찾기
    while(i < n && s[i]==best[i]) i++;

    if(i == n){  // 이미 best임
        cout << s;
        return 0;
    }

    string ans = s;
    for(int j = 1; j < n; j++){
        string tmp = s;
        reverse(tmp.begin()+ i, tmp.begin() + j + 1);
        if(tmp > ans) ans = move(tmp);
    }

    cout << ans;
}