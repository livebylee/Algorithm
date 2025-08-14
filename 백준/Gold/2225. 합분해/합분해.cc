#include <iostream>
#define MOD 1000000000
using namespace std;

int n,k;
int dp[201][201];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    for(int i = 0; i<=200; i++){
        dp[0][i] = 1;
        dp[i][1] = 1;
    }
    for(int i = 1; i<=200; i++){   // j개의 수의 합이 i
        for(int j = 1; j <= 200; j++){
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) %MOD;
        }
    }

    cout << dp[n][k];
}
