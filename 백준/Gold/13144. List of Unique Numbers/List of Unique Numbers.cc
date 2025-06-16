#include <iostream>
#include <vector>

using namespace std;

int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<bool> see(100001, false);
    int start = 0;
    long long result = 0;

    for (int end = 0; end < n; end++) {
        while (see[a[end]]) {
            see[a[start]] = false;
            start++;
        }
        see[a[end]] = true;
        result += (end - start + 1);
    }
    cout << result;
    return 0;
}