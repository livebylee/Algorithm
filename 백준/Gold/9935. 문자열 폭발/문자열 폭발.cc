#include <iostream>
#include <vector>

using namespace std;

string s;
string key;
vector<char> stk;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;
    cin >> key;

    for(auto now : s){
        stk.push_back(now);
        int i = 1;
        while(stk[stk.size()-i]==key[key.size()-i]){
            if(i == key.size()){ //폭발 문자열 발견
                while(i--){
                    stk.pop_back();
                }
                break;
            }
            i++;
        }
    }
    if(stk.size() == 0){
        cout << "FRULA";
        return 0;
    }
    for(auto c : stk){
        cout << c;
    }
}