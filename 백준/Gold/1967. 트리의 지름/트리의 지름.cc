#include <iostream>
#include <vector>
#define pii pair<int,int>

using namespace std;

int n;
vector<pii> adj[10001];
int visit[10001];
int maxNode,maxValue;

void dfs(int x,int dist){
    visit[x] = dist;
    for(auto next : adj[x]){
        if(visit[next.first]!=-1) continue;
        dist += next.second;
        dfs(next.first,dist);
        dist -= next.second;
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0; i< n-1; i++){
        int a,b,d;
        cin >> a >> b >> d;
        adj[a].push_back({b,d});
        adj[b].push_back({a,d});
    }

    fill(visit,visit + 10001,-1);
    dfs(1,0);   // 루트 노드 기준으로 dfs 

    for(int i = 1; i <= n; i++){   // 가장 거리가 먼 노드 찾기
        if(maxValue < visit[i]){
            maxValue = visit[i];
            maxNode = i;
        }
    }

    fill(visit,visit + 10001,-1);
    dfs(maxNode,0);         // 그 노드로부터 다시 dfs

    maxValue = 0;
    for(int i = 1; i <= n; i++){
        maxValue = max(maxValue,visit[i]); // 다시 최대 거리 찾기
    }
    cout << maxValue;
}