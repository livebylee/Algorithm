#include <iostream>

using namespace std;

int m[6] = {500,100,50,10,5,1};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int x;
    cin >> x;

    x = 1000-x;
    int cnt = 0;
    for(int i = 0; i < 6; i++){
        while(x >= m[i]){
            x -= m[i];
            cnt++;
        }
    }
    cout << cnt;
}