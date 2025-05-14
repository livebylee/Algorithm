#include <iostream>
#include <vector>

using namespace std;

int n,m;
int p[10];
vector<int> ans;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    int least = 99;
    int least2 = 99;
    int idx,idx2;
    for(int i = 0; i< n; i++){
        cin >> p[i];
        if(p[i] < least){
            least = p[i];
            idx = i;
        }
        if(p[i] < least2 && i != 0){
            least2 = p[i];
            idx2 = i;
        }
    }
    cin >> m;

    if(m < least2){
        cout << 0;
        return 0;
    }
    m -= least2; 
    ans.push_back(idx2);
    while(m >= least){
        ans.push_back(idx);
        m -= least;
    }
    for(int i = 0; i< ans.size(); i++){
        for(int j = n-1; j >=0 ; j--){
            if(m >= p[j] - p[ans[i]]){  //교체가능하면
                m -= (p[j] - p[ans[i]]);
                ans[i] = j;
                break;
            }
        }
    }
    for(auto x : ans){
        cout << x;
    }
}