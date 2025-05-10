#include <iostream>

using namespace std;

long long x,y,w,s;
long long ans;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> x >> y >> w >> s;
    if(2*w <= s){
        ans =  w * (x+y);
    }else if( w <= s){
        int common = min(x,y);
        ans = common * s + (max(x,y) - common) * w;
    }else{
        if(abs(x-y) % 2 == 0) ans = max(x,y) * s;
        else ans = (max(x,y) - 1) * s + w;
    }
    cout << ans;
}