#include <iostream>
#define MOD 1000000003
using namespace std;

int n,k;
long long combi[1001][1001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    if(k > n/2){
        cout << 0;
    }else if( k == n/2 && n % 2 == 0){
        cout << 2;
    }else{
        for(int i = 0; i<= n-k; i++){
            combi[i][0] = 1;
            combi[i][i] = 1;
        }
        for(int i =1; i<= n-k; i++){
            for(int j = 1; j<= k; j++){
                combi[i][j] = (combi[i-1][j-1] + combi[i-1][j]) % MOD;  
            }
        }
        cout << (combi[n-k-1][k-1] + combi[n-k][k]) % MOD;
    }
}