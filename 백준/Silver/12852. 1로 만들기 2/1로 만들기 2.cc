#include <iostream>

using namespace std;

int n;
int dp[1000001];
int road[1000001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    road[1] = 1;

    for(int i =2; i<=n; i++){
        dp[i] = dp[i-1] +1;
        road[i] = i-1; //기본 3번 연산
        if(i % 2 == 0 && dp[i/2] + 1 < dp[i]){
            dp[i] = dp[i/2]+1;
            road[i] = i/2;
        }
        if(i % 3 == 0 && dp[i/3] + 1 < dp[i]){
            dp[i] = dp[i/3]+1;
            road[i] = i/3;
        }
    }
    cout << dp[n] <<'\n';
    while(n!=1){
        cout << n <<" ";
        n = road[n]; //그 전 n으로 역추적
    }
    cout << 1;
}