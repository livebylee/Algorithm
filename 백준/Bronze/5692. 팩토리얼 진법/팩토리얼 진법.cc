#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while (true) {
		int num;
		cin >> num;

		if (num == 0) {
			break;
		}
		int res = 0;
		int mul = 1;
		int cnt = 1;

		while (num != 0) {
			res += (num % 10) * mul;
			num /= 10;
			cnt++;
			mul *= cnt;
		}

		cout << res << "\n";
	}
}