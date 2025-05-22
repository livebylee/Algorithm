#include <iostream>

using namespace std;

int num[2000];
int n,m;
int dp[2000][2000]; //s부터까지 팰린드롬인지

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0; i<n ; i++){
        cin >> num[i];
        dp[i][i] = 1; //자기자신부터 자기자신까지는 팰린드롬
    }
    for(int i= 1; i< n; i++){
        if(num[i-1]==num[i]){
            dp[i-1][i] = 1; //길이 2인 팰린드롬롬
        }
    }
    for(int len = 3; len <= n; len++){
        for(int i = 0; i<= n-len; i++){
            int j = i+len-1;
            if(num[i]== num[j] && dp[i+1][j-1]){
                dp[i][j] = 1;
            }
        }
    }
    cin >> m;
    for(int i = 0; i< m; i++){
        int s,e;
        cin >> s >> e;
        cout << dp[s-1][e-1] <<'\n';
    }
}