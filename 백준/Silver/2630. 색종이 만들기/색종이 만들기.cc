#include <iostream>
#define pii pair<int,int>
using namespace std;

int n;
int paper[128][128];


pii find(int size,int row,int col,int white,int blue){
    int color = paper[row][col];
    for(int i = row; i < row+size; i++){
        for(int j = col; j < col+size; j++){
            if(color != paper[i][j] ){
                int w = find(size/2,row,col,white,blue).first + find(size/2,row+size/2,col,white,blue).first + find(size/2,row,col+size/2,white,blue).first + find(size/2,row+size/2,col+size/2,white,blue).first;
                int b = find(size/2,row,col,white,blue).second + find(size/2,row+size/2,col,white,blue).second + find(size/2,row,col+size/2,white,blue).second + find(size/2,row+size/2,col+size/2,white,blue).second;
                return {w,b};
            }
        }
    }
    if(color == 0) white += 1;
    else blue += 1;
    return {white,blue};
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i = 0; i< n; i++){
        for(int j = 0; j < n; j++){
            cin >> paper[i][j];
        }
    }

    pii ans = find(n,0,0,0,0);
    cout << ans.first <<'\n';
    cout << ans.second;
}