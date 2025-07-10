#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n;
priority_queue<int, vector<int>, greater<int>> pq;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i = 0; i< n; i++){
        for(int j = 0; j< n; j++){
            int x;
            cin >> x;
            pq.push(x);
            if(pq.size() > n){
                pq.pop();
            }
        }
    }
    cout << pq.top();
}
