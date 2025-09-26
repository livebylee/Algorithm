#include <iostream>
 
using namespace std;
 
int A,B,C;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	cin >> A >> B >> C;
	int min = 60 * A + B;   // 시 -> 분
	min += C;
 
	int hour = (min / 60) % 24;
	int minute = min % 60;
 
	cout << hour << " " << minute;
	return 0;
}