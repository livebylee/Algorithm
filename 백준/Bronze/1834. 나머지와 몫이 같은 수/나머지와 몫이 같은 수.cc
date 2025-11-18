#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    long long num;
    long long result = 0;
    cin >> num;
    for (long long i = 1; i < num; i++)
        result += (num + 1) * i;
 
    cout << result;
 
    return 0;
}