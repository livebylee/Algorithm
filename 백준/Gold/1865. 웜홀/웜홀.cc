#include <iostream>
#include <vector>
#define pii pair<int,int>
using namespace std;

int tc;
int n,m,w;
const int INF = 999999999;
int dist[501];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> tc;
    while(tc--){
        bool minusCycle = false;

        cin >> n >> m >> w;
        vector<pii> adj[501];

        for(int i = 0; i< n; i++){   //모든 정점과 거리 0으로 연결된 가상의 0번 정점 추가
            adj[0].push_back(pii(i,0));
        }
        for(int i= 0; i < m; i++){
            int s,e,t;
            cin >> s >> e >> t;
            adj[s].push_back(pii(e,t));
            adj[e].push_back(pii(s,t));
        }
        for(int i = 0; i< w; i++){
            int s,e,t;
            cin >> s >> e >> t;
            adj[s].push_back(pii(e,-t));
            if(s==e) minusCycle = true;
        }
        fill(dist,dist+501,INF);
        dist[0] = 0;    // 그 0번 정점에서 스타트 : 모든 정점을 출발점처럼 탐색
        if(minusCycle == true){
            cout << "YES\n";
            continue;
        }
        for(int k = 0; k<= n; k++){       // 정점개수-1 번 + 마지막 1번 음수사이클 찾기
            for(int i = 0; i<= n; i++){  // 모든 간선 보기
                if(dist[i] == INF) continue;
                for(auto x : adj[i]){
                    int next = x.first;
                    int time = x.second;
                    if(dist[i] + time < dist[next]){
                        dist[next] = dist[i] + time;
                        if(k == n) minusCycle = true;
                    }
                }
            }
        }
        if(minusCycle == true) cout << "YES\n";
        else cout <<"NO\n";
    }
}