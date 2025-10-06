#include <iostream>

using namespace std;

int t,w;

int plum[1001];
int dp[1001][31];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t >> w;
    for(int i = 1; i<= t; i++){
        cin >> plum[i];
    }

    if(plum[1] == 1){
        dp[1][0] = 1;
    }else{
        dp[1][1] = 1;
    }

    for(int i =2; i <= t; i++){
        for(int move = 0; move <= w; move++){
            if(move == 0) dp[i][move] = dp[i-1][move] + ((plum[i] == 1) ? 1 : 0);
            else dp[i][move] = max(dp[i-1][move],dp[i-1][move-1]) + ((plum[i] == (move % 2)+1) ? 1 : 0);
        }
    }

    int maxplum = 0;
    for(int move = 0; move <=w; move++){
        maxplum = max(maxplum,dp[t][move]);
    }
    cout << maxplum;
}