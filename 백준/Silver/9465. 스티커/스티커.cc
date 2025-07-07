#include <iostream>
#include <algorithm>

using namespace std;

int s[2][100001];
int t;
int n;
int dp[2][100001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> s[0][i];
        }
        for(int i = 1; i<= n; i++){
            cin >> s[1][i];
        }
        dp[0][1] = s[0][1];
        dp[1][1] = s[1][1];
        for(int i = 2; i <= n; i++){
            dp[0][i] = max(dp[1][i-1]+ s[0][i], dp[1][i-2]+ s[0][i]);
            dp[1][i] = max(dp[0][i-1]+ s[1][i], dp[0][i-2]+ s[1][i]);
        }
        cout << max(dp[0][n],dp[1][n]) <<"\n";
    }
}