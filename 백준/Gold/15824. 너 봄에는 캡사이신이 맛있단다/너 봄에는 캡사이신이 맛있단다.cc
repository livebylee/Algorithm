#include<iostream>
#include<vector>
#include<algorithm>
#define MOD 1000000007
using namespace std;

int n;
vector<int> arr;
long long sum;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n; 
    for(int i = 0; i< n; i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }
    sort(arr.begin(), arr.end());
    
    vector<long long> pow(n+1);
    pow[0] = 1;
    for(int i = 1; i<= n; i++){
        pow[i] = (pow[i-1] * 2) % MOD;
    }

    for (int i = 0; i < n; i++) {
        long long tmp = ( (-pow[n-i-1] + pow[i] + MOD) % MOD );
        sum = (sum + (arr[i] % MOD) * tmp) % MOD;
    }
    cout << sum % MOD;
}