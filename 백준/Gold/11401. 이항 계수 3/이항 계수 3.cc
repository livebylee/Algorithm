#include <iostream>
#define MOD 1000000007

using namespace std;

long long N,K,ans;

long long power(long long a, long long n){
    long long result = 1;
    while(n){
        if(n % 2 == 1){
            result = (result * a) % MOD;
        }
        a = (a * a) % MOD;
        n /= 2;
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    if(K==0 || K== N) ans = 1;
    else if(K==1 || K == N-1) ans = N;
    else{
        long long A = 1;
        long long B = 1;
        for(int i = 1; i <= K; i++){
            B = (B * i) % MOD;
            A = (A * (N+1-i)) % MOD;
        }
        long long presult = power(B, MOD - 2) % MOD;
        ans = ((A % MOD) * (presult % MOD)) % MOD;
    }
    cout << ans;
}