#include <iostream>
#include <vector>
#define pii pair<int,int>

using namespace std;

int n,k;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    vector<pii> robot(2*n+2);
    for(int i = 1; i<= 2*n; i++){
        cin >> robot[i].first;
        robot[i].second = 0;
    }

    int stage = 0;
    int in = 1;
    int out = n;
    int cnt = 0;
    while(cnt < k){
        stage++;
        pii tmp = robot[2*n];
        for(int i = 2*n; i>=1; i--){
            robot[i+1] = robot[i];
        }
        robot[1] = tmp;
        if(robot[out].second==1) robot[out].second = 0;

        for(int i = n-1; i>=1; i--){
            if(robot[i].second==1){
                if(robot[i+1].second==0 && robot[i+1].first >0){
                    robot[i].second = 0;
                    robot[i+1].second = 1;
                    robot[i+1].first--;
                    if(robot[i+1].first ==0) cnt++;
                    if(i+1==out) robot[i+1].second = 0;
                }
            }
        }
        if(robot[in].first > 0){
            robot[in].second = true;
            robot[in].first--;
            if(robot[in].first ==0) cnt++;
        }
    }
    cout << stage;
}