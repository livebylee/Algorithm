#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int t[15];
int p[15];
int ans = 0;

void dfs(int start, int sum){    
    if(start>N) return;
    ans = max(ans, sum);
    for(int i = start; i<N; i++){
        dfs(i+t[i], sum+p[i]);
    }
}

int main(){
    
    cin >> N;
    for(int i = 0; i<N; i++){
        cin >> t[i] >> p[i];
    }
    dfs(0,0);
    cout << ans;
    return 0;
}