#include <iostream>
#include <queue>
#define pii pair<int,int>
#define ppi pair<pii,int>
using namespace std;


int t,l;
pii now;
pii goal;

int dx[8] = {1,2,2,1,-1,-2,-2,-1};
int dy[8] = {2,1,-1,-2,-2,-1,1,2};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;

    while (t--){
        cin >> l;
        cin >> now.first >> now.second;
        cin >> goal.first >> goal.second;

        queue<ppi> mq;
        bool board[l][l];
        for (int i = 0; i < l; i++){
            for (int j = 0; j < l; j++){
                board[i][j] = false;
            }
        }

        mq.push({now,0});
        while(!mq.empty()){
            pii curr = mq.front().first;
            int cnt = mq.front().second;
            board[curr.first][curr.second] = true;
            mq.pop();
            if(curr.first == goal.first && curr.second == goal.second){
                cout << cnt <<'\n';
                break;
            }
            for(int i = 0; i< 8; i++){
                int nx = curr.first + dx[i];
                int ny = curr.second + dy[i];
                if(nx < l && nx >=0 && ny < l && ny >=0 && board[nx][ny]==false){
                    board[nx][ny] = true;
                    mq.push({{nx,ny},cnt+1});
                }
            }
        }
    }
}