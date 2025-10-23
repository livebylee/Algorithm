#include <iostream>

using namespace std;

int n,s;
int arr[22];

int cnt;

void backtrack(int idx, int sum){
    if(sum == s && idx != 0){
        cnt++;
    }
    for(int i = idx+1; i<= n; i++){
        backtrack(i,sum + arr[i]);
    }
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> s;
    for(int i = 1; i<= n; i++){
        cin >> arr[i];
    }
    backtrack(0,0);

    cout << cnt;
}