#include <iostream>
#include <stack>
#include <cmath> 

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    if (!(cin >> n)) return 0;

    stack<int> s;

    do {
        int remainder = n % (-2);
        n /= (-2);
        if (remainder < 0) {
            remainder =1;
            n ++;
        }
        s.push(remainder);
    } while (n != 0);

    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }

    return 0;
}