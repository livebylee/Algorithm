#include <iostream>
#include <vector>
#include <set>
using namespace std;

int n;
int adj[101];
bool visit[101];
set<int> s;

void dfs(int start_node, int now){
    if(start_node == now && visit[now] == true){
        for(int i = 1; i<= n; i++){
            if(visit[i] == true) s.insert(i);
        }
        return;
    }
    if(visit[now] == true ) return;
    visit[now] = true;
    dfs(start_node,adj[now]);
    visit[now] = false;

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 1; i<= n; i++){
        int x;
        cin >> x;
        adj[i] = x;
    }
    for(int i = 1; i<= n; i++){
        for(int j = 1; j<=n ; j++){
            visit[j] = false;
        }
        dfs(i,i);
    }
    cout << s.size() <<"\n";
    for(int i = 0; i < s.size() ; i++){
        cout << *next(s.begin(),i) <<'\n';
    }
}