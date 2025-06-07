#include <iostream>
#include <vector>
#include <algorithm>

#define pii pair<string,int>

using namespace std;

int p,m;
vector<vector<pii>> room;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> p >> m;
    for(int i = 0; i<p; i++){
        int l;
        string n;
        cin >> l >> n;
        bool find = false;
        for(auto &r : room){
            if(r.size()>=m) continue;
            if(r[0].second+10 >= l  && r[0].second-10 <= l ){
                r.push_back({n,l});
                find=true;
                break;
            }
        }
        if(find == false){
            vector<pii> tmp;
            tmp.push_back({n,l});
            room.push_back(tmp);
        }
    }
    for(auto &r : room){
        sort(r.begin(),r.end());
        if(r.size() == m){
            cout << "Started!" <<'\n';
        }else{
            cout << "Waiting!" << '\n';
        }
        for(auto x : r){
            cout << x.second << " " <<  x.first <<'\n';
        }
    }
}