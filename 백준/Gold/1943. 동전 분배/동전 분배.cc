#include <algorithm>
#include <cstring>
#include <iostream>
#define pii pair<int,int>
using namespace std;

int N;
pii coin[101];  
bool dp[50001]; 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int tc = 0; tc < 3; tc++) {
        int sum = 0; 
        memset(dp, false, sizeof(dp));  
        dp[0] = true; 

        cin >> N;
        for (int i = 0; i < N; ++i) {
            cin >> coin[i].first >> coin[i].second; 
            sum += (coin[i].first * coin[i].second);
        }
        if (sum % 2 == 1) {  
            cout << "0\n";
            continue;
        }
        
        sort(coin, coin + N);
        int target = sum /2;

        for (int i = 0; i < N; i++) {
            for (int j = target; j >= coin[i].first; j--) {
                if (dp[j - coin[i].first]==true) {
                    for (int k = 0; k < coin[i].second; k++) {
                        if (j + k * coin[i].first > target) break;
                        dp[j + k * coin[i].first] = true;
                    }
                }
            }
        } 
        cout << dp[target] << "\n";
    }
    return 0;
}
