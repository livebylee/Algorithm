#include <iostream>

using namespace std;

bool arr[31];

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
    cout.tie(NULL);
    
    for(int i = 0; i< 28; i++){
        int x;
        cin >> x;
        arr[x] = true;
    }
    for(int i = 1; i<= 30; i++){
        if(arr[i] == false){
            cout << i << '\n';
        }
    }

}