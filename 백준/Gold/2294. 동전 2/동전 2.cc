#include <iostream>
#include <algorithm>

using namespace std;

int n,k;
int a[100001];
int coin[100];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    for(int i = 0; i< n; i++){
        cin >> coin[i];
        a[coin[i]] = 1;
    }
    for(int i = 0; i< k; i++){
        if(a[i]!=0){
            for(int j = 0; j<n ; j++){
                if(i+coin[j] > k) continue;
                if(a[i+coin[j]]==0){
                    a[i+coin[j]] = a[i]+1;
                }else{
                    a[i+coin[j]] = min(a[i]+1,a[i+coin[j]]);
                }
            }
        }
    }
    if(a[k] == 0) cout << -1;
    else cout << a[k];
}