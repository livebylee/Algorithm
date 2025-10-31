#include <iostream>
#include <vector>
#include <algorithm>
#define pii pair<int,int>

using namespace std;

int n,x,y,ans;
vector <pii> input;
vector <pii> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0; i< n; i++){
        cin >> x >> y;
        input.push_back({x,y});
    }
    sort(input.begin(),input.end());
    v.push_back(input[0]);

    for(int i = 0; i< n; i++){
        pii tmp = input[i];
        pii now = v[v.size()-1];
        if(tmp.first > now.second){
            v.push_back(tmp);
        }else if(tmp.second > now.second){
            now.second = tmp.second;
            v[v.size()-1] = now;
        }
    }
    
    for(auto line : v){
        ans += (line.second  - line.first );
    }
    cout << ans;
}