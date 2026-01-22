#include <iostream>

using namespace std;

int n;
int a[10];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    while(n > 0){
        a[n%10]++;
        n /= 10;
    }

    int ans = (a[6] + a[9] +1 ) / 2 ;
    
    for(int i = 0; i< 9; i++){
        if(i== 6) continue;
        ans = max(ans,a[i]);
    }
    cout << ans;

}