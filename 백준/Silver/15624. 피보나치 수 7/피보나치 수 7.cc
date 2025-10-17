#include <iostream>
#include <stdio.h>

using namespace std;

int dp[1000001];

int main(void){
    int n;
    scanf("%d", &n);
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;
    }
    printf("%d\n", dp[n]);

    return 0;
}