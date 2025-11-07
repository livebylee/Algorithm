#include <iostream>
#include <vector>
#include <queue>

#define pii pair<int,int>

using namespace std;

int n,m;
int a,b,c;
vector<pii> adj[50001];
priority_queue<pii,vector<pii>,greater<pii>> pq;
int dist[50001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for(int i = 0; i< m; i++){
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    for(int i = 0; i<= n; i++){
        dist[i] = 1e9;
    }
    
    pq.push({0,1}); //거리, 현재 노드
    dist[1] = 0;
    while(!pq.empty()){
        int curr = pq.top().second;
        int cost = pq.top().first;
        //cout << curr << " " << cost <<"\n";
        pq.pop();
        if(cost > dist[curr]) continue;
        for(auto next : adj[curr]){
            if(dist[next.first] > cost + next.second ){
                dist[next.first] = cost + next.second;
                if(next.first == n || next.first == 1) continue;
                pq.push({dist[next.first],next.first});
            }
        }
    }
    cout << dist[n];
}