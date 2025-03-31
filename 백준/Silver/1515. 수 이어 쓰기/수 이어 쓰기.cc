#include <iostream>
#include <string>
#include <queue>

using namespace std;

string s;
queue<int> mq;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;
    int prev = 0;
    for(auto num : s){
        int n = num-'0';
        mq.push(n);
    }
    int now = 1;
    while(!mq.empty()){
        string nowstring = to_string(now);
        for(auto c : nowstring){
            int n = c-'0';
            if(n == mq.front()){
                mq.pop();
            }
            if(mq.empty()) break;
        }
        now++;
    }
    cout << now-1;
}