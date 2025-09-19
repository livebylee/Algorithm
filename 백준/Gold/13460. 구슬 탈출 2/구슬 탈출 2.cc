#include <iostream>
#include <vector>
#include <queue>
#define pii pair<int,int>

using namespace std;

struct State {
    int rx, ry, bx, by, depth;
};

int N, M;
vector<string> board;
bool visited[10][10][10][10];  //rx, ry, bx, by
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

pii moveBall(int x, int y, int dir, int &cnt) {
    cnt = 0;
    while (true) {
        if (board[x+dx[dir]][y+dy[dir]] == '#') break;
        x += dx[dir];
        y += dy[dir];
        cnt++;
        if (board[x][y] == 'O') break;
    }
    return {x,y};
}

int bfs(int rx, int ry, int bx, int by) {
    queue<State> q;
    q.push({rx, ry, bx, by, 0});
    visited[rx][ry][bx][by] = true;

    while (!q.empty()) {
        State s = q.front();
        q.pop();
        auto [rx, ry, bx, by, depth] = s;
        if (depth >= 10) continue;

        for (int dir=0; dir<4; dir++) {
            int rc, bc;
            auto [nrx, nry] = moveBall(rx, ry, dir, rc);
            auto [nbx, nby] = moveBall(bx, by, dir, bc);

            if (board[nbx][nby] == 'O') continue; // 파란 구슬 빠지면 실패
            if (board[nrx][nry] == 'O') return depth+1; // 빨간 구슬만 빠지면 성공

            // 겹치면 조정
            if (nrx == nbx && nry == nby) {
                if (rc > bc) {
                    nrx -= dx[dir];
                    nry -= dy[dir];
                } else {
                    nbx -= dx[dir];
                    nby -= dy[dir];
                }
            }
            if (!visited[nrx][nry][nbx][nby]) {
                visited[nrx][nry][nbx][nby] = true;
                q.push({nrx, nry, nbx, nby, depth+1});
            }
        }
    }
    return -1;
}

int main() {
    cin >> N >> M;
    board.resize(N);
    int rx, ry, bx, by;
    for (int i=0; i<N; i++) {
        cin >> board[i];
        for (int j=0; j<M; j++) {
            if (board[i][j] == 'R'){ 
                rx=i; ry=j;
            }else if (board[i][j] == 'B'){ 
                bx=i; by=j;
            }
        }
    }
    cout << bfs(rx, ry, bx, by) << "\n";
}
