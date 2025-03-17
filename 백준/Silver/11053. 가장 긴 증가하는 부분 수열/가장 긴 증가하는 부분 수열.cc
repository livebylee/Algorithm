#include <iostream>
#include <vector>
#include <queue>
#define pii pair<int,int>

using namespace std;

struct cmp{
    bool operator()(pii a, pii b){
        if (a.first == b.first) return a.second < b.second;
        return a.first > b.first;
    }
};
int N;
int visit[1000];
priority_queue<pii,vector<pii>, cmp>  A;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i< N; i++){
        int x;
        cin >> x;
        A.push(pii(x,i));
    }
    int maxlen  = 0;
    while (!A.empty()){
        int topidx = A.top().second;
        A.pop();
        int now = 0;
        for(int i = 0; i < topidx; i++){
            if(visit[i] > now) now = visit[i];
        }
        visit[topidx] = now+1;
        if (visit[topidx] > maxlen) maxlen = visit[topidx];
    }
    cout << maxlen;
}