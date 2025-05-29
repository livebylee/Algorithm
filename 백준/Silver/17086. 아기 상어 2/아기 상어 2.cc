#include <iostream>
#include <queue>
#define pii pair<int,int>

using namespace std;

int n, m;
int space[50][50];
int dist[50][50];
bool visit[50][50];
queue<pii> mq;
int x[8] = {-1,0,1,1,1,0,-1,-1};
int y[8] = {-1,-1,-1,0,1,1,1,0};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i< n; i++){
        for(int j = 0; j< m; j++){
            cin >> space[i][j];
            if(space[i][j]==0) continue;
            mq.push({i,j});
            dist[i][j] = 0;
            visit[i][j] = true;
        }
    }
    while(!mq.empty()){
        int x0 = mq.front().first;
        int y0 = mq.front().second;
        mq.pop();
        for(int d = 0; d< 8; d++){
            int nx = x0 + x[d];
            int ny = y0 + y[d];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && visit[nx][ny]==false){
                dist[nx][ny] = dist[x0][y0] + 1; //bfs라 무조건 최단거리 저장됨됨
                visit[nx][ny] = true;
                mq.push({nx,ny});
            }
        }
    }
    int ans = 0;
    for(int i = 0; i< n; i++){
        for(int j = 0; j< m; j++){
            ans = max(ans,dist[i][j]);
        }
    }
    cout << ans;
}