#include <iostream>
#include <algorithm>
#define pii pair<int,int>

using namespace std;

int c,n;
pii city[21];
int dp[1100];
int ans = 1e9;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> c >> n;
    for(int i = 0; i < n; i++){
        cin >> city[i].first >> city[i].second;
    }

    for(int i =1; i<= c+100; i++){
        dp[i] = 1000000000;
    }

    for(int i = 0; i< n; i++){
        int cost = city[i].first;
        int people = city[i].second;
        for(int j = people; j <= c+100; j++){
            dp[j] = min(dp[j],dp[j-people]+cost);
        }
    }

    for (int i = c; i <= c + 100; i++) {
        ans = min(ans, dp[i]);
    }

    cout << ans;

}