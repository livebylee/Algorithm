#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t;
vector<int> alph[26];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while(t--){
        int k;
        string s;
        cin >> s;
        cin >> k;
        
        int minl = 100000;
        int maxl = 0;

        for(int i = 0; i < 26; i++) alph[i].clear();
        for(int i = 0; i < s.length(); i++){
            int now = s[i]-'a';
            alph[now].push_back(i);
        }
        for(int i = 0; i < 26; i++){
            if(alph[i].size() >= k){
                for(int j = 0; j<= alph[i].size()-k; j++){
                    minl = min(minl,alph[i][j+k-1]-alph[i][j]+1);
                    maxl = max(maxl,alph[i][j+k-1]-alph[i][j]+1);
                }
            }
        }
        if(minl == 100000 || maxl == 0){
            cout << -1 <<'\n';
            continue;
        }
        cout << minl <<" " << maxl <<"\n";
    }
}