#include <iostream>
#define mod 1000000000
using namespace std;

int N;
long long dp[1000001];


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    dp[2] = 1;
    for(int i = 3; i<= N; i++){
        dp[i] = ((i-1) * (dp[i-1]+dp[i-2])) % mod;
    }
    cout << dp[N];
}