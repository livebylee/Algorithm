#include <iostream>

using namespace std;

int n;
long long dp[1000001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n ;
    
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;

    for (int i = 3; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
    }
    cout <<dp[n];
}