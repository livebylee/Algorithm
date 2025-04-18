#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

#define pii pair<int,int>

using namespace std;

int n, l, r;
int A[51][51];
bool united[51][51];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> l >> r;
    for(int i =1 ;i<= n;i++){
        for(int j= 1; j<= n; j++){
            cin >> A[i][j];
        }
    }
    
    int day = 0;
    while(true){
        memset(united, false, sizeof(united));
        bool moved = false;
        for(int i =1; i<= n; i++){
            for(int j = 1; j<= n; j++){
                if(united[i][j]==true) continue;

                queue<pii> mq;
                vector<pii> unionl;
                mq.push(pii(i,j));
                united[i][j] = true;
                unionl.push_back(pii(i,j));
                int total = A[i][j];

                while(!mq.empty()){
                    int nowi = mq.front().first;
                    int nowj = mq.front().second;
                    mq.pop();
                    for (int d = 0; d < 4; d++) {
                        int nx = nowi + dx[d];
                        int ny = nowj + dy[d];
                        if (nx < 1 || ny < 1 || nx > n || ny > n) continue;
                        if (united[nx][ny]) continue;
                        int diff = abs(A[nowi][nowj] - A[nx][ny]);
                        if (diff >= l && diff <= r) {
                            united[nx][ny] = true;
                            mq.push({nx, ny});
                            unionl.push_back({nx, ny});
                            total += A[nx][ny];
                        }
                    }
                }
                if(unionl.size() > 1){
                    moved = true;
                    int avg = total / unionl.size();
                    for(auto s : unionl){
                        A[s.first][s.second] = avg;
                    }
                }
            }
        }
        if(moved == false){
            break;
        }
        day++;
    }
    cout << day;
}