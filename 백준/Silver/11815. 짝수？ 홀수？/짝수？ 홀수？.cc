#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        long long int num;
        cin >> num;

        long long sq = sqrt(num);
        if (sq* sq == num) {
            cout << 1 << " ";
        }
        else {
            cout << 0 << " ";
        }
    }
}