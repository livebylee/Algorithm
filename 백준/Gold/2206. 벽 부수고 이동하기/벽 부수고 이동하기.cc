#include <iostream>
#include <queue>
#define pii pair<int,int>
#define ppi pair<pii,int>

using namespace std;
int N,M;
int map[1000][1000][2];
queue<ppi> myq;

int dy[4] = {-1,1,0,0}; 
int dx[4] = {0,0,-1,1};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i<N;i++){
        string s;
        cin >> s;
        for(int j = 0; j< M; j++){
            map[i][j][0] = s[j]-'0';
        }
    }

    myq.push(ppi(pii(0,0),0));

    while(!myq.empty()){
        pii now = myq.front().first;
        int broken = myq.front().second;
        myq.pop();

        if(now.first== N-1 && now.second == M-1){
            cout << map[N-1][M-1][broken] +1;
            return 0;
        }
        for(int i = 0; i< 4;i++){
            int nx = now.first + dy[i];
            int ny = now.second + dx[i];
            if(nx >= 0 && ny >= 0 && nx < N && ny < M ){
                if(map[nx][ny][0] == 1){
                    if(broken == 0 && map[nx][ny][1] == 0){
                        map[nx][ny][broken+1] = map[now.first][now.second][broken]+1;
                        myq.push(ppi(pii(nx,ny),1));
                    }
                }
                else if(map[nx][ny][0] == 0){
                    if(broken == 1 && map[nx][ny][1] != 0){  //벽 부순상태에서 방문했었으면 패스
                        continue;
                    }
                    map[nx][ny][broken] = map[now.first][now.second][broken] +1;
                    myq.push(ppi(pii(nx,ny),broken));
                }
            }
        }
    }
    cout << -1;
}