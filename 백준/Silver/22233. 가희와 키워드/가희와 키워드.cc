#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int n,m;
unordered_set<string> us;
string s;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i< n; i++){
        cin >> s;
        us.insert(s);
    }
    while(m--){
        cin >> s;
        string ns ="";
        for(int i = 0; i< s.length(); i++){
            if(s[i]!=','){
                ns += s[i];
            }else{
                if(us.find(ns) != us.end()){ //us에 ns가 있으면
                    us.erase(ns);
                }
                ns = "";
            }
        }
        if(us.find(ns) != us.end()){ //us에 ns가 있으면
            us.erase(ns);
        }
        cout << us.size() <<'\n';
    }
}