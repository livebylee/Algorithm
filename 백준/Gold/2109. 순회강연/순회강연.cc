#include <iostream>
#include <vector>
#include <queue>

#define pii pair<int,int>

using namespace std;

struct cmp{
    bool operator()(pii a, pii b){
        if(a.first == b.first){
            return a.second < b.second;
        }
        return a.first < b.first;
    }
};

priority_queue<pii, vector<pii>, cmp> pq;

int n;
bool visit[10001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i = 0; i< n; i++){
        int x, y;
        cin >> x >> y;
        pq.push({x,y});
    }
    int ans = 0;

    while(!pq.empty()){
        pii now = pq.top();
        pq.pop();
        while(visit[now.second] == true && now.second >= 0){
            now.second--;
        }
        if(now.second > 0){
            visit[now.second] = true;
            ans+= now.first;
        }
    }
    cout << ans;
}