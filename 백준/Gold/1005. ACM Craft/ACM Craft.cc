#include <iostream>
#include <vector>
#include <queue>
#define pii pair<int,int>

using namespace std;

int t,n,k,w;
int d[1001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i = 0; i<n ; i++){
            cin >> d[i];
        }
        int arr[n+1] = {0,}; //위상
        vector<int> bd[n+1];
        for(int i = 0; i<k ; i++){
            int x,y;
            cin >> x >> y;
            arr[y]++;
            bd[x].push_back(y);
        }
        cin >> w;

        queue<pii> mq;
        int ans[n+1]={0,};
        for(int i = 1; i<= n ; i++){
            if(arr[i] == 0){
                mq.push({i,d[i-1]});
                ans[i] = d[i-1];
            }
        }
        while(!mq.empty()){
            int nowtime = mq.front().second;
            int nowi = mq.front().first;
            mq.pop();
            for(auto next : bd[nowi]){
                arr[next]--;
                ans[next] = max(ans[next], nowtime+d[next-1]);
                if(arr[next]==0){
                    mq.push({next,ans[next]});
                }
            }
        }
        cout << ans[w] <<'\n';
    }
}