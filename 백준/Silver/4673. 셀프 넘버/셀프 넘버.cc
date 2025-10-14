#include <iostream>

using namespace std;

const int maxnum = 10000;

bool arr[10001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i = 1; i <= maxnum; i++){
        int nown = i;
        int dn = i;
        while(nown > 0){
            dn += nown %10;
            nown /= 10;
        }
        if(maxnum >= dn){
            arr[dn] = true;
        }
    }

    for(int i = 1; i <= maxnum; i++){
        if(arr[i] == false){
            cout << i <<'\n';
        }
    }
}