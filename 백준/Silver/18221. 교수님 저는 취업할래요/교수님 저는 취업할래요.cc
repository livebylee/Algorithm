#include <iostream>
#include <vector>
#include <utility>
#include <climits>
#include <cmath>

using namespace std;

vector<vector<int>> board;
pair<int, int> prof, sung;
int n;

bool CountingStudents(int ys, int ye, int xs, int xe, bool sameLine) {
    int count = 0;
    if (sameLine) {
        if (xs == xe) { // 같은 행
            for (int j = ys; j <= ye; j++) {
                if (board[xs][j] == 1) count++;
            }
        } else { // 같은 열
            for (int i = xs; i <= xe; i++) {
                if (board[i][ys] == 1) count++;
            }
        }
    } else {
        for (int i = xs; i <= xe; i++) { // 행 
            for (int j = ys; j <= ye; j++) { // 열 
                if (board[i][j] == 1) {
                    count++;
                }
            }
        }
    }
    return count >= 3;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    board.resize(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if (board[i][j] == 5) prof = {i, j};
            if (board[i][j] == 2) sung = {i, j};
        }
    }

    int dist = pow(abs(sung.first - prof.first), 2) + pow(abs(sung.second - prof.second), 2);

    if (dist >= 25) {
        int xs = min(prof.first, sung.first);
        int xe = max(prof.first, sung.first);
        int ys = min(prof.second, sung.second);
        int ye = max(prof.second, sung.second);

        bool sameLine = false;
        if (prof.first == sung.first || prof.second == sung.second) {
            sameLine = true;
        }
        if (CountingStudents(ys, ye, xs, xe, sameLine)) {
            cout << 1 << '\n';
            return 0;
        } else {
            cout << 0 << '\n';
            return 0;
        }
    } else {
        cout << 0 << '\n';
        return 0;
    }
    return 0;
}