#include <iostream>

using namespace std;

int a[100001],b[100001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n; 
    for(int i = 0; i< n ; i++){
        cin >> a[i];
    }
    int ans = -100000000; 
    for(int i = 0; i <n ; i++){
        b[i] = max(a[i],b[i-1]+a[i]);
        ans = max(ans,b[i]);
    }
    cout << ans;
}