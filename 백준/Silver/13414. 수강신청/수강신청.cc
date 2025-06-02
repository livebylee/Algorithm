#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<string,int> &a, pair<string ,int> &b){
    return a.second < b.second;
}
int k,l;
unordered_map<string,int> m;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> k >> l;
    for(int i = 0; i< l; i++){
        string s;
        cin >> s;
        if(m.find(s) != m.end()){
            m.erase(s);
        }
        m[s] = i;
    }
    vector<pair<string,int>> v(m.begin(),m.end());
    sort(v.begin(),v.end(),cmp);

    for(int i = 0; i< k; i++){
        if(v.size() == i) break;
        cout << v[i].first << '\n';
    }
}