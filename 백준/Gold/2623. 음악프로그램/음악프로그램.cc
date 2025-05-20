#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n,m;
int arr[1001];
vector<int> singer[1001];
queue<int> mq;
vector<int> ans;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i< m; i++){
        int x;
        cin >> x;
        int tmp[x];
        for(int j = 1; j <= x; j++){
            cin >> tmp[j];
            if(j!=1){
                singer[tmp[j-1]].push_back(tmp[j]);
                arr[tmp[j]]++;
            }
        }
    }
    for(int i = 0; i< n; i++){
        if(arr[i+1] == 0){
            mq.push(i+1);
        }
    }
    while(!mq.empty()){
        int now = mq.front();
        ans.push_back(now);
        mq.pop();
        for(auto next : singer[now]){
            arr[next]--;
            if(arr[next]==0){
                mq.push(next);
            }
        }
    }
    if(ans.size()!= n) cout << 0;
    else{
        for(auto x : ans){
            cout << x << "\n";
        }
    }
}