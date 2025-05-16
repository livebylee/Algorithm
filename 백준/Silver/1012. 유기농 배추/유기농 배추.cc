#include <iostream>
#include <queue>

using namespace std;

int t,m,n,k;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int ground[50][50];
bool visit[50][50];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while(t--){
        cin >> m >> n >> k;

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++) {
                ground[i][j] = 0;
                visit[i][j] = false;
            }
        }
        
        for(int i = 0; i< k ; i++){
            int x,y;
            cin >> x >> y;
            ground[x][y] =1;
        }

        int cnt = 0;
        for(int i = 0; i< m; i++){
            for(int j = 0; j < n; j++){
                if(visit[i][j]==true || ground[i][j]==0) continue;
                cnt++;
                queue<pair<int, int>> mq;
                mq.push({i,j});
                while(!mq.empty()) {
                    pair<int,int> curr = mq.front(); mq.pop();
                    int ci = curr.first;
                    int cj = curr.second;

                    for (int w = 0; w < 4; w++) {
                        int nowi = ci + dx[w];
                        int nowj = cj + dy[w];
                        if (nowi < m && nowi >=0 && nowj < n && nowj >=0 && !visit[nowi][nowj] && ground[nowi][nowj]==1) {
                            visit[nowi][nowj] = true;
                            mq.push({nowi, nowj});
                        }
                    }
                }
            }
        }
        cout << cnt <<'\n';
    }
}
