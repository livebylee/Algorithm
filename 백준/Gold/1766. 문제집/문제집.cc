#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

vector<int> order[32001];
vector<int> adj[32001];
priority_queue<int> pq;

int N,M;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for(int i = 0; i< M;i++){
        int a,b;
        cin >> a >> b;
        order[b].push_back(a);
        adj[a].push_back(b);
    }

    for(int i = 1; i<=N;i++){
        if(order[i].size() == 0){
            pq.push(-i);
        }
    }

    while(!pq.empty()){
        int now = -(pq.top());
        pq.pop();
        cout << now <<" ";
        for(auto next : adj[now]){
            order[next].erase(remove(order[next].begin(),order[next].end(),now),order[next].end());
            if(order[next].size()==0){
                pq.push(-next);
            }
        }
    }
}