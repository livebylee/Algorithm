#include <iostream>
#include <queue>
#define pii pair<int,int>

using namespace std;

int m,n;
int cnt; //전체 토마토 개수
int newcnt; //익은거 개수
int day;
int box[1000][1000];
queue<pii> mq;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
queue<pii> tt; //tomorrow tomato

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> m >> n;
    for(int i = 0; i< n; i++){
        for(int j = 0; j < m; j++){
            cin >> box[i][j];
            if(box[i][j] == 1){
                mq.push({i,j});
                newcnt++;
            }
            if(box[i][j] >= 0) cnt++;
        }
    }

    while(true){
        while(!mq.empty()){
            //cout << mq.size() <<" ";
            int x = mq.front().first;
            int y = mq.front().second;
            mq.pop();
            for(int i = 0; i< 4; i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m ) continue;
                if(box[nx][ny] == 0){
                    tt.push({nx,ny});
                    box[nx][ny] = 1;
                    newcnt++;
                }
            }
        }
        if(tt.empty()) break;
        day++;

        while(!tt.empty()){
            pii tmp = tt.front();
            tt.pop();
            mq.push(tmp);
        }
    }
    if(cnt != newcnt) cout << -1;
    else cout << day <<'\n';
}