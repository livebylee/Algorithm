#include <iostream>
#include <set>
#include <queue>

using namespace std;

int n,m;
set<int> enemy[1001];
set<int> adj[1001];
int parent[1001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    cin >> m;

    for(int i =0; i< m; i++){
        char fe;
        int p,q;
        cin >> fe >>p >> q;

        if(fe == 'E'){
            enemy[p].insert(q);
            enemy[q].insert(p);

        }else{
            adj[p].insert(q);
            adj[q].insert(p);
        }
    }

    for(int i = 1; i<= n; i++){
        for(auto next : enemy[i]){
            for(auto x : enemy[next]){
                adj[i].insert(x);
                adj[x].insert(i);
            }
        }
    }

    for(int i = 1; i<= n; i++){
        queue<int> q;
        if(parent[i] != 0) continue;
        parent[i] = i;
        q.push(i);

        while(!q.empty()){
            int now = q.front();
            q.pop();
            for(auto next : adj[now]){
                if(parent[next]==0){
                    parent[next] = i;
                    q.push(next);
                }
            }
        }
    }

    set<int> ans;

    for(int i = 1; i<= n; i++){
        ans.insert(parent[i]);
    }
    cout << ans.size();
}