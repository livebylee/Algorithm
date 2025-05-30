#include <iostream>
#include <stack>
using namespace std;

int n;
stack<int> mq;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    int cnt = 0;
    for(int i = 0; i< n; i++){
        int x,y;
        cin >> x >> y;

        while (!mq.empty() && y < mq.top()) {
            mq.pop();
        }
        if(mq.empty() || y > mq.top()){
            if(y!=0){
                mq.push(y);
                cnt++;
            }
        }
    }
    cout << cnt;
}