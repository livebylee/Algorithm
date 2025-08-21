#include <iostream>
#include <queue>

using namespace std;

int t,k;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while(t--){
        cin >> k;
        priority_queue<long long,vector<long long>,greater<long long>> pq;
        for(int i = 0; i< k; i++){
            int x;
            cin >> x;
            pq.push(x);
        }
        long long cost = 0;
        while(pq.size() > 1){
            long long k1 = pq.top();
            pq.pop();
            long long k2 = pq.top();
            pq.pop();
            pq.push(k1+k2);
            cost += (k1+k2);
        }
        cout << cost <<'\n';
    }
}