#include <iostream>
using namespace std;
long long a,b,c;

long long pow(long long b){
    if(b == 0) return 1;
    if(b == 1) return a % c;
    long long n = pow(b/2)  % c;
    if(b % 2 == 0) return (n*n) % c;
    else return (((n*n)%c)*(a % c))% c;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> b >> c;
    cout << pow(b);
}