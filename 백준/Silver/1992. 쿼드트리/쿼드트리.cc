#include <iostream>
#include <cstring>

using namespace std;

int n;
int board[64][64];

string quadtree(int size,int x, int y){
    int first = board[x][y];
    bool same = true;

    for(int i = x ; i< x+size; i++){
        for(int j = y ; j < y+size ; j++){
            if(board[i][j] != first){
                same = false;
                break;
            }
        }
        if(same == false) break;
    }
    if(same==true) return to_string(first);

    string ans = "(";
    int newsize = size/2;
    ans += quadtree(newsize,x,y);
    ans += quadtree(newsize,x,y+newsize);
    ans += quadtree(newsize,x+newsize,y);
    ans += quadtree(newsize,x+newsize,y+newsize);
    ans += ")";
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0; i< n; i++){
        for(int j = 0; j< n; j++){
            char c;
            cin >> c;
            board[i][j]= c-'0';
        }
    }
    cout << quadtree(n,0,0);
}

