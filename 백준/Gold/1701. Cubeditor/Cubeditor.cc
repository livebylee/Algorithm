#include <iostream>

using namespace std;

string s;
int dp[5001][5001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;
    
    int l = s.length();

    int max_len = 0;
    for(int i = 0; i< l; i++){
        for(int j = i+1; j< l; j++){
            if(s[i] == s[j]){
                if(i==0) dp[i][j] = 1;
                else dp[i][j] = dp[i-1][j-1] + 1;
                max_len = max(max_len,dp[i][j]);
            }
        }
    }
    cout << max_len;
}