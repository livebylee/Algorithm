#include <iostream>
#include <stack>
#define pii pair<int,int>

using namespace std;

int n;
stack<pii> ms;
int score;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0; i< n; i++){
        int hw,a,t;
        cin >> hw;
        if(hw){
            cin >> a >> t;
            ms.push({a,t});
        }
        if(ms.empty()) continue;
        ms.top().second--;
        if(ms.top().second == 0){
            score += ms.top().first;
            ms.pop();
        }
    }
    cout << score;
}