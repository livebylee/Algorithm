#include <iostream>

using namespace std;

int n;
int board[10][10];
bool diag1[20], diag2[20]; //대각선별로 이미 비숏 있는지 체크크
int blackmax, whitemax;

void backtrack(int cnt,int idx,int color){  //1차원의 idx로 탐지
    if(idx == n *n){
        if(color==0) blackmax = max(blackmax,cnt);
        else whitemax = max(whitemax,cnt);
        return;
    }
    int i = idx / n;
    int j = idx % n;

    if((i+j) % 2 != color){  //색 안 맞는거 패스스
        backtrack(cnt,idx+1,color);
        return;
    }

    if(board[i][j] == 1 && diag1[i+j]==false && diag2[i-j+n-1]==false){
        diag1[i+j] = true;
        diag2[i-j+n-1] = true;
        backtrack(cnt+1, idx+1, color);  //비숍 놓고 다음거
        diag1[i+j] = false;
        diag2[i-j+n-1] = false;
    }
    backtrack(cnt,idx+1,color);  //비숍 안 놓고 다음거거
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0; i< n; i++){
        for(int j = 0; j< n; j++){
            cin >> board[i][j];
        }
    }
    
    backtrack(0,0,0);
    backtrack(0,0,1);

    cout << blackmax+whitemax;
}