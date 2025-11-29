#include<iostream>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    int check_row = 0;
    int check_col = 0;
    
    char arr[N][M];
    bool row[50] = {false};
    bool col[50] = {false};
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 'X') {
                row[i] = true;
                col[j] = true;
            }
        }
    }

    for(int i = 0; i < N; i++) {
        if(!row[i]) {
            check_row++;
        }
    }

    for(int j = 0; j < M; j++) {
        if(!col[j]) {
            check_col++;
        }
    }

    int answer = max(check_row, check_col);
    cout << answer << endl;

    return 0;
}