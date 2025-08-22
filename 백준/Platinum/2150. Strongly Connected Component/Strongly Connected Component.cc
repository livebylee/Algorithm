#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int v,e;
int a,b;
vector<int> adj[10001];
vector<int> re_adj[10001];
bool visit[10001];
bool visit2[10001];
stack<int> st;
vector<int> scc[10001];

void dfs(int x){    // 원래 그래프 기반
    visit[x] = true;
    for(auto next : adj[x]){
        if(!visit[next]){
            dfs(next);
        }
    }
    st.push(x);
}

void dfs2(int x,int cnt){   // 간선 뒤집은 그래프 기반
    visit2[x] = true;
    scc[cnt].push_back(x);
    for(auto next : re_adj[x]){
        if(!visit2[next]){
            dfs2(next,cnt);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> v >> e;
    for(int i = 0; i< e; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        re_adj[b].push_back(a);
    }

    for(int i = 1; i<= v; i++){
        if(!visit[i]) dfs(i);
    }

    int cnt = 0;
    while(!st.empty()){
        int now = st.top();
        st.pop();
        if(!visit2[now]){
            dfs2(now,cnt);
            cnt++;
        }
    }
    cout << cnt <<'\n';

    for(int i = 0; i< cnt; i++){
        sort(scc[i].begin(),scc[i].end());
    }

    sort(scc,scc+cnt);
    for(int i = 0; i< cnt; i++){
        for(auto x : scc[i]){
            cout << x << " ";
        }
        cout << -1 <<'\n';
    }
}
