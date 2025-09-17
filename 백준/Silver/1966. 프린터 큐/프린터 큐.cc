#include <iostream>
#include <queue>
#define pii pair<int,int>
using namespace std;

int t;
int n,m;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while(t--){
        queue<pii> mq;        //중요도, 몇번째문서
        priority_queue<int> pq;

        cin >> n >> m;

        for(int i = 0; i< n; i++){
            int x;
            cin >> x;
            mq.push({x,i});
            pq.push(x);
        }
        
        int order = 0;
        while(!mq.empty()){
            pii now = mq.front();
            mq.pop();
            if(now.first < pq.top()){
                mq.push(now);
            }else{
                order++;
                pq.pop();
                if(now.second == m){
                    cout << order <<'\n';
                    break;
                }
            }
        }
    }
}