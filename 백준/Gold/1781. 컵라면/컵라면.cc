#include <iostream>
#include <queue>
#include <algorithm>
#define pii pair<int,int>

using namespace std;

int n;
priority_queue<int,vector<int>,greater<int>> pq;
long long maxramen;
vector<pii> problem;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0; i< n; i++){
        int deadline,ramen;
        cin >> deadline >> ramen;
        problem.push_back({deadline,ramen});
    }
    sort(problem.begin(),problem.end());
    for(auto x : problem){
        pq.push(x.second);
        if(pq.size() > x.first){
            pq.pop();
        }
    }
    while(!pq.empty()){
        maxramen += pq.top();
        pq.pop();
    }
    cout << maxramen <<'\n';
}