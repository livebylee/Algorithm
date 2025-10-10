#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
vector<int> adj[3001];
bool visit[3001];
bool isCycle[3001];
int parent[3001];
queue<int> mq;
int dist[3001];

bool dfs(int x,int prev){
    visit[x] = true;
    parent[x] = prev;
    for(auto next : adj[x]){
        if(next==prev) continue;
        if(visit[next] == false){
            if(dfs(next,x)) return true;
        }else{ // 사이클 발견!
            int cur = x;
            isCycle[cur] = true;   
            while(cur != next){
                cur = parent[cur];
                isCycle[cur] = true;
            }
            return true;
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0; i< n; i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1,0);

    for(int i = 1; i<= n; i++){
        if(isCycle[i]){
            dist[i] = 0;
            mq.push(i);
        }else{
            dist[i] =-1;
        }
    }
    while(!mq.empty()){
        int now = mq.front();
        mq.pop();
        for(auto next : adj[now]){
            if(dist[next] == -1){
                dist[next] = dist[now] + 1;
                mq.push(next);
            }
        }
    }

    for(int i = 1; i<=n; i++){
        cout << dist[i] <<" ";
    }
}