#include <iostream>

using namespace std;

const int MOD = 10007;
string s;
int dp[1001][1001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;

    int n = s.length();

    for(int i = 0 ; i< n; i++){
        dp[i][i] = 1;
        dp[i][i+1] = (s[i] == s[i+1]) ? 3 : 2;
    }


    for(int len = 2; len< n; len++){
        for(int j = 0; j< n-len; j++){
            if(s[j] == s[j+len]){
                dp[j][j+len] = (dp[j+1][j+len] + dp[j][j+len-1] - dp[j+1][j+len-1] + dp[j+1][j+len-1] + 1 + MOD) % MOD;
            } else {
                dp[j][j+len] = (dp[j+1][j+len] + dp[j][j+len-1] - dp[j+1][j+len-1] + MOD )% MOD;
            }
        }
    }
    cout << dp[0][n-1];
}