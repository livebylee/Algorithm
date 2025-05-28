#include <iostream>

using namespace std;

int n,b,c;
int a[1000000];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0; i <n ; i++){
        cin >> a[i];
    }
    cin >> b >> c;
    long long cnt = 0;
    for(int i = 0; i <n ; i++){
        cnt++;
        a[i] -= b;
        if(a[i] <= 0) continue;
        cnt += (a[i] / c);
        if(a[i] % c != 0) cnt++;
    }
    cout << cnt;
}