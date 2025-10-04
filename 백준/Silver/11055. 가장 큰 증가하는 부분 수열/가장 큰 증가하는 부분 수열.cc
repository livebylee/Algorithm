#include <iostream>

using namespace std;

int n;
int a[1001];
int dp[1001];
int ans;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0; i< n; i++){
        cin >> a[i];
        dp[i] = a[i];
    }
    ans = dp[0];
    for(int i = 1; i< n; i++){
        for(int j = 0; j< i; j++){
            if(a[j] < a[i]){
                dp[i] = max(dp[i], dp[j]+a[i]);
            }
        }
        ans = max(ans,dp[i]);
    }
    cout << ans;
}