#include <iostream>
#include <math.h>

using namespace std;

int t,n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t; 
    while(t--){
        cin >> n;
        int result = 0;
        for(int i = 1; i<= sqrt(n); i++){
            if(i*i == n){
                result = 1;
                break;
            }
        }
        cout << result <<'\n';
    }
}