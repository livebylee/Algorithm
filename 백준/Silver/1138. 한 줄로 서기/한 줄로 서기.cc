#include <iostream>
#include <queue>

using namespace std;

int cnt[11];
priority_queue<int,vector<int>,greater<int>> q;
vector<int> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> cnt[i];
        if(cnt[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int cur = q.top();
        q.pop();
        v.push_back(cur);
        for(int i = 0; i< cur; i++){
            cnt[i]--;
            if(cnt[i] == 0) q.push(i);
        }
    }

    for(auto x : v) cout << x+1 <<" ";

}