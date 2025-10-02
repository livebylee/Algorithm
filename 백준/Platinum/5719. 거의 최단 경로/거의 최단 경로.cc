#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define pii pair<int,int>

using namespace std;

struct cmp {
    bool operator()(pii &a, pii &b) {
        return a.first > b.first;
    }
};

int n, m;
int s, d;
priority_queue<pii, vector<pii>, cmp> pq;
int dist[501];
vector<int> parent[501];
vector<pii> adj[501];
bool visit[501];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        cin >> s >> d;

        for (int i = 0; i < n; i++) {
            dist[i] = 1e9;
            adj[i].clear();
            parent[i].clear();
            visit[i] = false;
        }
        while (!pq.empty()) pq.pop();

        for (int i = 0; i < m; i++) {
            int u, v, p;
            cin >> u >> v >> p;
            adj[u].push_back({v, p}); 
        }
        
        dist[s] = 0;
        pq.push({0, s});

        while (!pq.empty()) {
            int cost = pq.top().first;
            int now = pq.top().second;
            pq.pop();

            if (cost > dist[now]) continue;

            for (auto next : adj[now]) {
                if (dist[next.first] >= cost + next.second) {
                    if (dist[next.first] > cost + next.second) {
                        parent[next.first].clear();
                        parent[next.first].push_back(now);
                        dist[next.first] = cost + next.second;
                        pq.push({dist[next.first], next.first});
                    } else {
                        // 중복 삽입 방지
                        if (find(parent[next.first].begin(), parent[next.first].end(), now) 
                            == parent[next.first].end()) {
                            parent[next.first].push_back(now);
                        }
                    }
                }
            }
        }
        if (dist[d] == 1e9) {
            cout << -1 << '\n';
            continue;
        }

        // 최단 경로 간선 제거 (역추적 BFS)
        queue<int> q;
        q.push(d);
        visit[d] = true;

        while (!q.empty()) {
            int now = q.front();
            q.pop();

            for (auto prev : parent[now]) {
                if (!visit[prev]) {
                    visit[prev] = true;
                    q.push(prev);
                }
                adj[prev].erase(remove_if(adj[prev].begin(), adj[prev].end(),
                                          [now](pii edge) { return edge.first == now; }),
                                adj[prev].end());
            }
        }
        for (int i = 0; i < n; i++) dist[i] = 1e9;
        while (!pq.empty()) pq.pop();

        dist[s] = 0;
        pq.push({0, s});

        while (!pq.empty()) {
            int cost = pq.top().first;
            int now = pq.top().second;
            pq.pop();
            if (cost > dist[now]) continue;

            for (auto next : adj[now]) {
                if (dist[next.first] > cost + next.second) {
                    dist[next.first] = cost + next.second;
                    pq.push({dist[next.first], next.first});
                }
            }
        }
        if (dist[d] == 1e9) cout << -1 << '\n';
        else cout << dist[d] << "\n";
    }
}