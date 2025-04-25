#include <iostream>
#include <algorithm>

using namespace std;

int n,m;
char org[50][50];
int result = 64; //답
char wb[8][8] = {
    'W','B','W','B','W','B','W','B',
    'B','W','B','W','B','W','B','W',
    'W','B','W','B','W','B','W','B',
    'B','W','B','W','B','W','B','W',
    'W','B','W','B','W','B','W','B',
    'B','W','B','W','B','W','B','W',
    'W','B','W','B','W','B','W','B',
    'B','W','B','W','B','W','B','W',
};
char bw[8][8] = {
    'B','W','B','W','B','W','B','W',
    'W','B','W','B','W','B','W','B',
    'B','W','B','W','B','W','B','W',
    'W','B','W','B','W','B','W','B',
    'B','W','B','W','B','W','B','W',
    'W','B','W','B','W','B','W','B',
    'B','W','B','W','B','W','B','W',
    'W','B','W','B','W','B','W','B',
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for(int i= 0; i< n; i++){
        for(int j =0 ;j< m ;j++){
            cin >> org[i][j];
        }
    }
    for(int i = 0; i<= n-8; i++){
        for(int j = 0; j<= m-8; j++){
            int cnt1 =0;
            int cnt2 =0;
            for(int x =0; x<8; x++){
                for(int y =0; y <8; y++){
                    if(org[i+x][j+y] != wb[x][y]){
                        cnt1++;
                    }
                    if(org[i+x][j+y] != bw[x][y]){
                        cnt2++;
                    }
                }
            }
            result = min(result,min(cnt1,cnt2));
        }
    }
    cout << result;
}