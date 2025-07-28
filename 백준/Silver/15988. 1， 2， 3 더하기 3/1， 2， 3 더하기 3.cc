#include <iostream>
#define MOD 1000000009

using namespace std;

int t,n;
long long dp[1000001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t; 

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for(int i = 4; i < 1000001; i++){
        dp[i] = (dp[i-1] + dp[i-2] + dp[i-3]) % MOD;
    }
    while(t--){
        cin >> n;
        cout << dp[n] <<'\n';
    }
}