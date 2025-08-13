#include <iostream>
#include <vector>
#include <queue>
#include <set>

#define pii pair<int,int>
using namespace std;

int n;
vector<int> adj[51];
int scoreArr[51];
int minScore = 100;  //임의로 큰 수
int candidateNum = 0;
queue<int> candidate;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    while(true){
        int u,v;
        cin >> u >> v;
        if(u == -1) break;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 1; i<= n; i++){
        queue<pii> mq;  // 회원번호, 깊이
        set<int> s;
        int score = 0;
        s.insert(i);
        mq.push({i,0});
        while(!mq.empty() && s.size() < n){
            int curr = mq.front().first;
            int depth = mq.front().second;
            score = max(score,depth);
            mq.pop();
            s.insert(curr);
            for(auto x : adj[curr]){
                if(s.count(x)) continue;
                mq.push({x,depth+1});
            }
        }
        scoreArr[i] = score;
        if(minScore > score){
            minScore = score;
            while(!candidate.empty()) candidate.pop();
            candidate.push(i);
        }else if(minScore == score){
            candidate.push(i);
        }
    }
    
    cout << minScore <<" " << candidate.size() <<'\n';
    while(!candidate.empty()){
        cout << candidate.front() <<" ";
        candidate.pop();
    }
}