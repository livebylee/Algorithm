#include <iostream>

using namespace std;
 
int p[20];
int n;

int go(int l, int r) {
    int x = 1;
    for (int i = l; i < r + 1; i++) {
        x *= p[i];
    }
    return x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    cin >> n;
    for (int i = 1; i < n + 1; i++) {
        cin >> p[i];
    }
    int ans = 0, val = 0;
    int cnt[10]; 
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                val = go(1, i) + go(i+1, j) + go(j+1, k)+go(k+1, n);
                ans = (ans > val) ? ans : val;
            }
        }
    }
    cout << ans;
}