#include <iostream>
#include <vector>
#include <queue>
#define pii pair<int,int>

using namespace std;

vector<int> parent[101];
int n,m;
int t1,t2;
queue<pii> mq;
bool visit[101];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    cin >> t1 >> t2;
    cin >> m;
    for(int i = 0; i < m; i++){
        int x,y;
        cin >> x >> y;
        parent[x].push_back(y);
        parent[y].push_back(x);
    }
    mq.push({t1,0});
    visit[t1] = true;
    while(!mq.empty()){
        int now = mq.front().first;
        int rel = mq.front().second;
        mq.pop();
        if(now == t2){
            cout << rel;
            return 0;
        }
        for(auto next : parent[now]){
            if(visit[next] == false){
                visit[next] = true;
                mq.push({next,rel+1});
            }
        }
    }
    cout << -1;
}