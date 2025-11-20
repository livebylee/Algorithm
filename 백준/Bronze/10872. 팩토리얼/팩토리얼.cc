#include <iostream>
using namespace std;
 
int main() {
	int N; 
	cin >> N;
 
	int facN = 1; 
	for (int i = 1; i <= N; i++)
	{
		facN *= i;
	}
 
	cout << facN << '\n';
	return 0;
}