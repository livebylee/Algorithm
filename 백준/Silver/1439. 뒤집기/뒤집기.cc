#include <iostream>

using namespace std;

string s;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;
    char prev = s[0];
    int cnt = 0;
    for(int i = 1; i< s.length(); i++){
        char now = s[i]; 
        if(prev != now) cnt++;
        prev = now;
    }
    cout << (cnt+1)/2;
}