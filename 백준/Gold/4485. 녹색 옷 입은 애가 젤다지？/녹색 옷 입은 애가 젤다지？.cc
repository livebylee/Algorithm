#include <iostream>
#include <tuple>
#include <queue>
#include <cstring>

using namespace std;

int cave[125][125];
int n;
int dx[4] = {-1,0,1,0}; //위 오른쪽 아래 왼쪽
int dy[4] = {0,1,0,-1};
int dist[125][125];
bool visit[125][125];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int problem = 0;
    while(true){
        problem++;
        cin >> n;

        if(n==0) break;

        for(int i = 0; i<n ; i++){
            for(int j = 0; j <n ; j++){
                cin >> cave[i][j];
            }
        }
        memset(dist,0x3f,sizeof(dist));
        memset(visit,false,sizeof(visit));
        priority_queue<tuple<int,int,int>> mq;

        dist[0][0] = cave[0][0];
        mq.push({-cave[0][0],0,0});

        while(!mq.empty()){
            int x = get<1>(mq.top());
            int y = get<2>(mq.top());
            int cost = 0 - get<0>(mq.top());
            mq.pop();

            if(visit[x][y]) continue;
            visit[x][y] = true; //큐에서 뺄때 방문처리

            for(int i = 0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx >= 0 && nx < n && ny >= 0 &&ny <n){
                    int newcost = cost+ cave[nx][ny];
                    if(dist[nx][ny] > newcost){
                        dist[nx][ny] = newcost;
                        mq.push({-newcost,nx,ny});
                    }
                }
            }
        }
        cout << "Problem " <<problem <<": "<< dist[n-1][n-1] <<'\n';
    }
}