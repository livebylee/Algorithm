#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

#define pii pair<int,int>
using namespace std;

const int MAX_N = 40001;
const int MAX_K = 16; 

int n, m;
vector<pii> adj[MAX_N];
int depth[MAX_N];   // 루트로부터 해당 노드까지 깊이
pii parent[MAX_N][MAX_K]; // node의 2^k 번째 부모, 거기까지의 거리

void dfs(int curr){
    for(auto next : adj[curr]){
        if(depth[next.first] != -1) continue; // 이미 방문한 경우
        depth[next.first] = depth[curr] + 1;
        parent[next.first][0] = {curr, next.second};
        dfs(next.first);
    }
}

int lca(int u, int v){
    int d = 0;

    if(depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v];

    for(int i = 0; diff; i++){
        if(diff & 1){
            d += parent[u][i].second;
            u = parent[u][i].first;
        }
        diff >>= 1;
    }

    if(u == v) return d;

    for(int i = MAX_K - 1; i >= 0; i--){
        if(parent[u][i].first != -1 && parent[u][i].first != parent[v][i].first){
            d += parent[u][i].second + parent[v][i].second;
            u = parent[u][i].first;
            v = parent[v][i].first;
        }
    }

    d += parent[u][0].second + parent[v][0].second;
    return d;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i = 0; i < n - 1; i++){
        int u, v, dist;
        cin >> u >> v >> dist;
        adj[u].emplace_back(v, dist);
        adj[v].emplace_back(u, dist);
    }

    fill(depth, depth + n + 1, -1);
    for(int i = 0; i <= n; i++){
        for(int j = 0; j < MAX_K; j++){
            parent[i][j] = {-1, -1};
        }
    }

    depth[1] = 0;
    dfs(1);

    for(int k = 0; k < MAX_K - 1; k++){
        for(int i = 1; i <= n; i++){
            int mid = parent[i][k].first;
            if(mid != -1 && parent[mid][k].first != -1){
                int mid_parent = parent[mid][k].first;
                int dist_sum = parent[i][k].second + parent[mid][k].second;
                parent[i][k + 1] = {mid_parent, dist_sum};
            }
        }
    }

    cin >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        cout << lca(u, v) << "\n";
    }

    return 0;
}