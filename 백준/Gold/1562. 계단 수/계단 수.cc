#include <iostream>

using namespace std;

const long long MOD = 1000000000LL;
int n;
int dp[101][10][1<<10];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    int fullMask = (1<<10) -1;  //다 1인거
    for(int i = 1; i<= 9; i++){
        dp[1][i][1<<i] = 1;   //초기화(기저)
    }
    
    for(int len = 1; len < n; len++){
        for(int digit = 0; digit <= 9; digit++){
            for(int mask = 0; mask <= fullMask; mask++){
                long long cur = dp[len][digit][mask];
                if(cur == 0) continue;
                if(digit > 0){
                    int nd = digit-1; 
                    int nmask = mask | (1 << nd);
                    dp[len+1][nd][nmask] = (dp[len+1][nd][nmask] + cur) % MOD;
                }
                if(digit < 9){
                    int nd = digit + 1;
                    int nmask = mask | (1 <<nd);
                    dp[len+1][nd][nmask] = (dp[len+1][nd][nmask] + cur) % MOD;
                }
            }
        }
    }
    long long ans = 0;
    for(int d= 0; d <= 9; d++){
        ans = (ans + dp[n][d][fullMask]) % MOD;
    }
    cout << ans << '\n';
    return 0;
}