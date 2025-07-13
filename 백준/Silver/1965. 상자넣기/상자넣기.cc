#include <iostream>

using namespace std;

int n;
int arr[1000];
int dp[1000];
int maxbox = 1;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0; i< n; i++){
        cin >> arr[i]; 
        dp[i] = 1;
    }
    for(int i = 1; i< n; i++){
        for(int prev = i-1; prev >= 0; prev--){
            if(arr[prev] < arr[i]){
                dp[i] = max(dp[i],dp[prev]+1);
            }
        }
        maxbox = max(maxbox,dp[i]);
    }
    cout << maxbox;
}