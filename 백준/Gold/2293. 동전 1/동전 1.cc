#include <iostream>
#include <cstring>

using namespace std;

int n,k;
int coin_arr[101];
long long dp[10001] = {1};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    for(int i = 0; i< n; i++){
        cin >> coin_arr[i];
    }
    for(int i = 0; i< n; i++){
        for(int j = coin_arr[i]; j <= k; j++){
            dp[j] += dp[j-coin_arr[i]];
        }
    }
    cout << dp[k];
} 