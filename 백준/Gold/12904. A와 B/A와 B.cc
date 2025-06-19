#include <iostream>

using namespace std;

string s,t;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;
    cin >> t;

    while(s.length() < t.length()){
        if(t[t.length()-1] == 'A'){
            t = t.substr(0,t.length()-1);
        }else{
            t = t.substr(0,t.length()-1);
            string tmp = "";
            for(int i = t.length()-1; i >= 0; i--){
                tmp += t[i];
            }
            t = tmp;
        }
    }
    if(s==t){
        cout << 1;
    }else{
        cout << 0;
    }
}