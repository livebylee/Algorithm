#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n;
vector<int> a;
priority_queue<int> pq;
int ans;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0; i< n; i++){
        int x;
        cin >> x;
        a.push_back(x);
    }
    for(int i = 0; i< n; i++){
        int x;
        cin >> x;
        pq.push(x);
    }
    sort(a.begin(),a.end());
    int cur = 0;
    while(!pq.empty()){
        ans += (pq.top() * a[cur]);
        pq.pop();
        cur++;
    }
    cout << ans;
}