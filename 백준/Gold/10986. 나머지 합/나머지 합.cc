#include <iostream>

using namespace std;

int n,m;
long long cnt;
long long arr[1000];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    
    long long s = 0;
    arr[0]++;
    for(int i = 0; i< n; i++){
        int x;
        cin >> x;
        s += x;
        int cur_mod = s % m;
        arr[cur_mod]++; 
    }
    for(int i = 0; i< m; i++){
        if(arr[i] >= 2){
            cnt += (arr[i] * (arr[i] -1) / 2);
        }
    }
    cout << cnt;
}