#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int cnt = 0;
    int now = n;

    do {
        cnt++;
        int first = now / 10;
        int second = now % 10;
        now = (second * 10) + ((first + second) % 10);
    } while (now != n);

    cout << cnt;
}