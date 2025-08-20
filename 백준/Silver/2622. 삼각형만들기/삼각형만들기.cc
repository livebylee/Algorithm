#include <iostream>

using namespace std;

int n;
int cnt = 0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i = 1; i<= n/2; i++){
        for(int j = 1; j <= i; j++){
            int c = n - i -j;
            if(c > j || i >= j+c) continue;
            //cout << i << " " << j << " " << c <<'\n';
            cnt++;
        }
    }
    cout << cnt;
}