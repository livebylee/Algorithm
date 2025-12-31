#include <iostream>

using namespace std;

long long dp[31];
int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    dp[2] = 3;
    dp[4] = 11;

    
    if(n%2 ==1){
        cout << 0;
        return 0;
    }

    for(int i = 6; i <= n; i+=2){
        dp[i] = dp[i-2] * 4 - dp[i-4];
    }
    cout << dp[n];
}
