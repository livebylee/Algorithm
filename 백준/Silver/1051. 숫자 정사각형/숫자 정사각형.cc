#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M, len = 0, lenMax = 1, number = 0;
    char arr[50][51];
    
    cin >> N >> M;
    for (int i = 0; i < N; i++){
        cin >> arr[i];
    }
    
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            for (int k = j + 1; k < M; k++){
                len = k - j; 
                number = arr[i][j];
                if (k - j > N - i) continue;
                else if (number == arr[i][k] && number == arr[i+len][k] && number == arr[i+len][j]){
                    lenMax = max(lenMax, len + 1);
                }
            }
        }
    }
    cout << lenMax * lenMax;

    return 0;
}

