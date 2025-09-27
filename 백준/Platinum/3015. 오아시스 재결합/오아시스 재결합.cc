#include <iostream>
#include <stack>
#define pii pair<int,int>

using namespace std;

int n;
stack<pii> ms;
long long ans;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);     

    cin >> n;
    for(int i = 0; i< n; i++){
        int x;
        cin >> x;
        
        int same_cnt = 1;

        while (!ms.empty() && ms.top().first <= x){
            ans += ms.top().second;
            if(ms.top().first == x){
                same_cnt += ms.top().second;
            }
            ms.pop();
        }
        if(!ms.empty()) ans++;
        ms.push({x,same_cnt}); 
    }
    cout << ans;
}
