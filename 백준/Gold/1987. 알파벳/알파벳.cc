#include <iostream>

using namespace std;

int r,c;
bool visit[26];
char board[20][20];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int ans = 0;

void dfs(int x, int y, int cnt){
    ans = max(ans,cnt);
    for(int dir = 0 ; dir <4 ;dir++){
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(nx >= 0 && nx < r && ny >= 0 && ny < c){
            int idx = board[nx][ny] -'A';
            if(visit[idx] == false){
                visit[idx] = true;
                dfs(nx,ny,cnt+1);
                visit[idx] = false;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r >> c;

    for(int i = 0 ; i<r ; i++){
        for(int j = 0; j<c; j++){
            cin >> board[i][j]; 
        }
    }
    visit[board[0][0]-'A'] = true;
    dfs(0,0,1);
    cout << ans << "\n";
}