#include <iostream>
#include <queue>

using namespace std;

int n,w,l;
queue<int> tq;
queue<int> mq;
int time;
int tmpw;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> w >> l;  // 트럭수 , 다리길이 , 최대하중
    for(int i = 0; i< n; i++){
        int truck;
        cin >> truck;
        tq.push(truck);
    }
    while(!tq.empty()){
        time++;
        if(mq.size() < w && tmpw + tq.front() <= l){
            int now = tq.front();
            tq.pop();
            mq.push(now);
            tmpw += now;
        }else if(mq.size() >= w ){
            tmpw -= mq.front();
            mq.pop();
            if(tmpw + tq.front() <= l){
                int now = tq.front();
                tq.pop();
                mq.push(now);
                tmpw += now;
            }else{
                mq.push(0);
            }
        }else{
            mq.push(0);
        }
    }
    time += w;
    cout << time;
}