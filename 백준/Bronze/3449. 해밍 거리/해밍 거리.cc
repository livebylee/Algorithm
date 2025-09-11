#include <iostream>

using namespace std;

int main() {
	string n1;
	string n2;
	int t;
	cin >> t;
	
	for(int i=0; i<t; i++){
		cin >> n1 >> n2;
		int cnt = 0;
		for(int j=0; j<n1.length(); j++){
			if(n1[j] != n2[j]) cnt++;
		}
		cout << "Hamming distance is " << cnt << "." << endl;
	}
    return 0;
}