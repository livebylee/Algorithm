#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define pii pair<int,int>

using namespace std;

int n,d;
vector<pii> road;
priority_queue<int,vector<int>,greater<int>> sq;
int ans = 0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0; i< n; i++){
        int s,e;
        cin >> s >> e;

        if(s > e) swap(s,e);

        road.push_back({s,e});
    }
    cin >> d;

    sort(road.begin(),road.end(),[](auto &a, auto &b){
        return a.second < b.second;
    });

    for(auto &x : road){
        int s = x.first;
        int e = x.second;
        if(e-s > d) continue;
        
        sq.push(s);

        while(!sq.empty() && sq.top() < e-d){
            sq.pop();
        }
        ans = max(ans,(int)sq.size());
    }
    cout << ans;
}

