#include <iostream>

using namespace std;

int a[7];
int ans = 0;
int res[7];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i = 1; i< 7; i++){
        cin >> a[i];
    }

    ans += a[6];
    ans += a[5];
    res[1] += (11 * a[5]);

    ans += a[4];
    res[2] += (5 * a[4]);

    ans += (a[3] / 4 + 1);
    int res3 = a[3] % 4;

    if(res3 == 1){
        res[2] += 5;
        res[1] += 7;
    }else if(res3 == 2){
        res[2] +=3;
        res[1] += 6;
    }else if(res3 == 3){
        res[2] += 1;
        res[1] += 5;
    }else ans -= 1;

    if(a[2] <= res[2]){
        res[2] -= a[2];
        res[1] += (res[2] * 4);
    }else{
        ans += ((a[2] - res[2])/9);
        if((a[2] - res[2]) % 9 !=0){
            ans += 1;
            res[1] += (36 - (((a[2] - res[2]) % 9)*4));
        }
    } 

    if(a[1] > res[1]){
        a[1] -= res[1];
        ans += (a[1] / 36);
        if(a[1] % 36 != 0) ans++;
    }

    cout << ans;
}