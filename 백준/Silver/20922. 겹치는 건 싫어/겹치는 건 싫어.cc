#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n,k;
int ele[200001];
queue<int> mq;
int len;
int maxlen;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    for(int i = 0; i< n;i++){
        int x; 
        cin >> x;
        mq.push(x);
        ele[x]++;
        len++;
        while(ele[x] > k){
            ele[mq.front()]--;
            mq.pop();
            len--;
        }
        maxlen = max(maxlen, len);
    }
    cout << maxlen;
}