#include <iostream>
#include <algorithm>
#include <string>
 
using namespace std;
 
int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    string s, a, b;
    cin >> s;
    bool flag = false;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ':') {
            flag = true;
            continue;
        } else if (!flag) a += s[i];
        else b += s[i];
    }
 
 
    int x, y, mod;
    x = stoi(a);
    y = stoi(b);
 
    mod = gcd(x, y);
    cout << x / mod << ':' << y / mod;
 
}