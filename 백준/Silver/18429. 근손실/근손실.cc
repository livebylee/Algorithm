#include <iostream>

using namespace std;

int n,k;
int kit[8];
bool visit[8];
int ans = 0;

void backtrack(int cnt,int now){
    if(cnt==n){
        ans++;
        return;
    }
    for(int i= 0 ; i< n; i++){
        if(visit[i] == true) continue;
        if(now-k+kit[i] >= 500){ //가능
            visit[i] = true;
            backtrack(cnt+1, now-k+kit[i]);
            visit[i] = false;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    for(int i = 0; i< n; i++){
        cin >> kit[i];
    }

    backtrack(0,500);
    cout << ans;
}