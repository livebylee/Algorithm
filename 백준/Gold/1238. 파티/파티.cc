#include <iostream>
#include <vector>
#include <queue>

#define pii pair<int,int>

using namespace std;

int n,m,x;
vector<pii> adj[1001];
vector<pii> adj2[1001];
int time[1001];
int time2[1001];

void dijkstra(int start){
    for(int i = 1; i<=n ; i++) time[i] = 1e9;
    time[start] = 0;
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push({0,start});

    while(!pq.empty()){
        int cost = pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if(time[now] < cost) continue;
        
        for(auto next : adj[now]){
            int nextNode = next.first;
            int nextCost = cost + next.second;
            if(nextCost < time[nextNode]){
                time[nextNode] = nextCost;
                pq.push({nextCost,nextNode});
            }
        }
    }
}

void dijkstra2(int start){
    for(int i = 1; i<=n ; i++) time2[i] = 1e9;
    time2[start] = 0;
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push({0,start});

    while(!pq.empty()){
        int cost = pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if(time2[now] < cost) continue;
        
        for(auto next : adj2[now]){
            int nextNode = next.first;
            int nextCost = cost + next.second;
            if(nextCost < time2[nextNode]){
                time2[nextNode] = nextCost;
                pq.push({nextCost,nextNode});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> x;

    for(int i = 0; i< m; i++){
        int s,e,t;
        cin >> s >> e >> t;
        adj[s].push_back({e,t});
        adj2[e].push_back({s,t});
    }
    
    dijkstra(x);  // 파티장소 -> 집 
    dijkstra2(x); // 집 -> 파티장소

    int maxtime = 0;

    for(int i = 1; i <=n ; i++){
        maxtime = max(time[i] + time2[i],maxtime);
    }
    cout << maxtime;
}