#include <iostream>

using namespace std;

int n,m;
int fix[41];
int dp[41];
int ans = 1;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    cin >> m;

    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i <= n-m; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    int curr = 1;
    for(int i = 0; i< m; i++){
        cin >> fix[i];
        ans *= dp[fix[i] - curr];
        curr = fix[i]+1;
    }
    ans *= dp[n - curr + 1];
    cout << ans;
}