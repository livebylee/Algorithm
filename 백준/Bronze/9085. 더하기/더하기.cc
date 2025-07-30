#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	int c, n, num, sum = 0;
	cin >> c;
	for (int i = 0; i < c; i++) {
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> num;
			sum += num;
		}
		cout << sum << '\n';
		sum = 0;
	}

	return 0;
}