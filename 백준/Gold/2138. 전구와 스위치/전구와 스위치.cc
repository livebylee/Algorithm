#include <iostream>
#include <algorithm>

using namespace std;

int n;
int light[100000];
int light2[100000];
int ans[100000];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0; i< n; i++){
        char x;
        cin >> x;
        light[i] = x -'0';
        light2[i] = x- '0';
    }
    for(int i = 0; i< n; i++){
        char x;
        cin >> x;
        ans[i] = x -'0';
    }
    int finalcnt = 1000000000;

    light[0] ^= 1;
    light[1] ^= 1;
    int cnt1 = 1; //처음거 누른거
    int cnt2 = 0; //처음거 안 누른거

    for(int i = 1; i< n-1; i++){  //스위치
        if(light[i-1] != ans[i-1]){
            light[i-1] ^= 1;
            light[i] ^= 1;
            light[i+1] ^= 1;
            cnt1++;
        }
        if(light2[i-1] != ans[i-1]){
            light2[i-1] ^= 1;
            light2[i] ^= 1;
            light2[i+1] ^= 1;
            cnt2++;
        }
    }
    if(light[n-2] != ans[n-2]){
        light[n-2] ^= 1;
        light[n-1] ^= 1;
        cnt1++;
    }
    if(light2[n-2] != ans[n-2]){
        light2[n-2] ^= 1;
        light2[n-1] ^= 1;
        cnt2++;
    }
    if(light[n-1] == ans[n-1]){
        finalcnt = min(cnt1,finalcnt);
    }
    if(light2[n-1] == ans[n-1]){
        finalcnt = min(cnt2,finalcnt);
    }
    if(finalcnt == 1000000000) cout << -1;
    else cout << finalcnt;
}