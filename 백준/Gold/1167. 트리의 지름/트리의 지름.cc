#include <iostream>
#include <vector>
#define pii pair<int,int>

using namespace std;

int n;
vector<pii> adj[100001];
long long visit[100001];
long long maxNode,maxValue;

void dfs(int x,long long dist){
    visit[x] = dist;
    for(auto next : adj[x]){
        if(visit[next.first]!=-1) continue;
        dist += next.second;
        dfs(next.first,dist);
        dist -= next.second;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 1; i<= n; i++){
        int a,b;
        cin >> a;
        cin >> b;
        while(b!=-1){
            int d;
            cin >> d;
            adj[a].push_back({b,d});
            adj[b].push_back({a,d});
            cin >> b;
        }
    }

    fill(visit,visit + 100001,-1);
    dfs(1,0);   // 루트 노드 기준으로 dfs 

    for(int i = 1; i <= n; i++){   // 가장 거리가 먼 노드 찾기
        if(maxValue < visit[i]){
            maxValue = visit[i];
            maxNode = i;
        }
    }

    fill(visit,visit + 100001,-1);
    dfs(maxNode,0);         // 그 노드로부터 다시 dfs

    for(int i = 1; i <= n; i++){
            if(maxValue < visit[i]){
            maxValue = visit[i];  // 다시 최대 거리 찾기
        }
    }
    cout << maxValue;
}