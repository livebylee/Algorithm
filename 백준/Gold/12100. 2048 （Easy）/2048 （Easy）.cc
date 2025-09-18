#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,ans;
vector<vector<int>> board;

vector<int> move_row_left(const vector<int> &row, int N) {
    vector<int> newRow = row;

    newRow.erase(remove(newRow.begin(), newRow.end(), 0), newRow.end());    //vector에서 0삭제 문법,remove가 뒤로 밀고, erase가 끝부분 수정
    for (int i = 0; i < (int)newRow.size() - 1; i++) {
        if (newRow[i] == newRow[i+1]) {
            newRow[i] += newRow[i+1];   
            newRow[i+1] = 0;     
            i++;                 
        }
    }
    newRow.erase(remove(newRow.begin(), newRow.end(), 0), newRow.end());
    while ((int)newRow.size() < N) {
        newRow.push_back(0);
    }
    return newRow;
}

vector<vector<int>> transpose(const vector<vector<int>> &board){  //옆으로 돌리는거 왼방향이 위로 가도록
    vector<vector<int>> res(n,vector<int>(n));
    for(int i = 0; i< n; i++){
        for(int j= 0; j < n; j++){
            res[j][i] = board[i][j];
        }
    }
    return res;
}

vector<vector<int>> move(const vector<vector<int>> &board,int dir){  //dir 1 왼쪽 2 위 3 오른쪽 4 아래
    vector<vector<int>> newBoard = board;  
    if(dir == 1){
        for(int i = 0; i< n; i++){
            newBoard[i] = move_row_left(newBoard[i],n);
        }
    }else if(dir == 2){   //위
        newBoard = transpose(newBoard);
        for(int i = 0; i< n; i++){
            newBoard[i] = move_row_left(newBoard[i],n);
        }
        newBoard = transpose(newBoard);
    }else if(dir == 3){   //오른쪽
        for(int i = 0; i< n; i++){
            reverse(newBoard[i].begin(), newBoard[i].end());
            newBoard[i] = move_row_left(newBoard[i],n);
            reverse(newBoard[i].begin(), newBoard[i].end());
        }
    }else{   //아래
        newBoard = transpose(newBoard);
        for(int i = 0; i< n; i++){
            reverse(newBoard[i].begin(), newBoard[i].end());
            newBoard[i] = move_row_left(newBoard[i],n);
            reverse(newBoard[i].begin(), newBoard[i].end());
        }
        newBoard = transpose(newBoard);
    }
    return newBoard;
}

void backtrack(const vector<vector<int>> &board,int depth){
    if (depth == 5){
        int nowmax = board[0][0];
        for(int i = 0; i< n; i++){
            for(int j = 0; j< n; j++){
                nowmax = max(nowmax,board[i][j]);
            }
        }
        ans = max(ans,nowmax);
        return;
    }
    for(int dir = 1; dir <= 4; dir++){
        vector<vector<int>> newBoard = move(board,dir);
        backtrack(newBoard,depth+1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    board.resize(n);
    for(int i = 0; i< n; i++){
        for(int j = 0; j< n; j++){
            int x;
            cin >> x;
            board[i].push_back(x);
        }
    }
    backtrack(board,0);
    cout << ans;
}