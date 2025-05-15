#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;
vector<int> boy;
vector<int> girl;
int dp[1001][1001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for(int i = 0; i< n; i++){
        int a;
        cin >> a;
        boy.push_back(a);
    }
    for(int i = 0; i< m ; i++){
        int a;
        cin >> a;
        girl.push_back(a);
    }
    sort(boy.begin(), boy.end());
    sort(girl.begin(), girl.end());
    
    for(int i = 1; i<= n ; i++){
        for(int j = 1; j <= m; j++){
            if(i==j){
                dp[i][j] = dp[i-1][j-1] + abs(boy[i-1]-girl[j-1]);
            }else if(i > j){
                dp[i][j] = min(dp[i-1][j],dp[i-1][j-1]+abs(boy[i-1]-girl[j-1]));
            }else{
                dp[i][j] = min(dp[i][j-1],dp[i-1][j-1]+abs(boy[i-1]-girl[j-1]));
            }
        }
    }
    cout << dp[n][m];
}