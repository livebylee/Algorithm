#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> dp;
const int INF = 1e9;
int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    dp.push_back(-INF);
    for(int i = 0; i< n; i++){
        int x;
        cin >> x;
        if(dp.back() < x) dp.push_back(x);
        else{
            auto it = lower_bound(dp.begin(),dp.end(),x);  //이진탐색으로 자리찾기
           *it = x; 
        }
    }
    cout << dp.size()-1;
}