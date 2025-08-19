#include <iostream>
#include <vector>
#include <array>

using namespace std;

int n;
long long b;
array<array<int,5>,5> matrix;
array<array<int,5>,5> result;

array<array<int, 5>, 5> mul (const array<array<int, 5>, 5>& m1, const array<array<int, 5>, 5>& m2){
    array<array<int, 5>, 5> newm = {0};
    for(int row = 0; row < n; row++){
        for(int col = 0; col < n; col++){
            int value = 0;
            for(int i= 0 ; i <n; i++){
                value += m1[row][i]*m2[i][col];
            }
            newm[row][col] = value % 1000;
        }
    }
    return newm;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> b;

    for(int i = 0; i< n; i++){
        for(int j = 0; j <n; j++){
            cin >> matrix[i][j];
        }
        result[i][i] = 1; //항등행렬로 초기화
    }

    while(b > 0){
        if(b % 2 == 1){
            result = mul(result,matrix);
            b--;
        }
        matrix = mul(matrix,matrix);
        b /= 2;
    }

    for(int row = 0; row < n; row++){
        for(int col = 0; col < n; col++){
            cout << result[row][col] << " ";
        }
        cout << '\n';
    }
}