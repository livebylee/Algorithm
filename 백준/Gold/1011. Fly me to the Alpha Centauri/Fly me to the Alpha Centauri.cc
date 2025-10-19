#include <iostream>
using namespace std;

int t;
int x,y;
long long dp[100000];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    int idx = 1;
    for(int i = 1; i<=50000; i++){
        dp[idx] = dp[idx-1] + i;
        idx++;
        dp[idx] = dp[idx-1] + i;
        idx++;
    }
    while(t--){
        cin >> x >> y;
        int goal = y-x;
        int move  = 1;
        while(goal > dp[move]){
            move++;
        }
        cout << move <<"\n";
    }
}