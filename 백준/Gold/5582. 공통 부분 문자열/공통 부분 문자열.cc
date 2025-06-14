#include <iostream>
#include <string>

using namespace std;

string s;
string t;

int dp[4000][4000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> s;
	cin >> t;

	int max = 0;
	for (int i = 0; i < s.length(); i++) {
		for (int j = 0; j < t.length(); j++) {
			if (s[i] == t[j]) {
				if (i == 0 || j == 0) dp[i][j] = 1;
				else dp[i][j] = dp[i - 1][j - 1] + 1;
				if (max < dp[i][j]) max = dp[i][j];
			}
		}
	}
	cout << max;
}