#include <iostream>
#include <set>

using namespace std;

string s;
set<string> myset;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;
    for(int i = 0; i< s.length(); i++){
        for(int j = 0; j< s.length()-i; j++){
            string sub = s.substr(j,i+1);
            myset.insert(sub);
        }
    }
    cout << myset.size();
}