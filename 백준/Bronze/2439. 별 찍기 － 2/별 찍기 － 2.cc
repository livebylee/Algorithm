#include <iostream>
 
using namespace std;
 
int main() {
 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
    
	int N;
	cin >> N;
 
	for (int row = 1; row <= N; row++) {
		for (int i = 0; i < N - row; i++) {
			cout << ' ';
		}
		for (int i = 0; i < row; i++) {
			cout << '*';
		}
		cout << '\n';
	}
	return 0;
}