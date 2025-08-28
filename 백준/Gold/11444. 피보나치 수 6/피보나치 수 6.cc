#include <iostream>
#include <map>  
#define MOD 1000000007
using namespace std;

map<long,long> m;
long long n;

long long fib(long long x){
    if(m[x]) return m[x];

    long long result;
    if(x%2 == 0) result = (fib(x/2)*(fib(x/2+1)+fib(x/2-1))) % MOD;
    else {
        long long a = fib((x+1)/2);
        long long b = fib((x-1)/2);
        result = (a*a + b*b) % MOD;
    }
    return m[x] = result % MOD;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    
    m[0] = 0;
    m[1] = 1;
    m[2] = 1;
    cout << fib(n);
}