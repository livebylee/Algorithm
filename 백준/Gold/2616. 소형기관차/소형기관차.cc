#include <iostream>

using namespace std;

int n,len;
int s[50001];
int dp[4][50001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    int tmp;
    for(int i = 1; i <= n ; i++){
        cin >> tmp;
        s[i] = s[i-1] + tmp; //누적합 
    }
    cin >> len;

    for(int i = 1; i < 4; i++){ //객차 i번이
        for(int j = len * i;  j <=n ;j++){
            int ps = s[j] - s[j-len];
            dp[i][j] = max(dp[i][j-1],dp[i-1][j-len] + ps); // j-1개까지 i개 열차, j-len에서 i-1개 열차 + 현재구간 추가
        }
    }
    cout << dp[3][n] << '\n';
    return 0;
}