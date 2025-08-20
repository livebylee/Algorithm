#include <iostream>
#include <cstring>
#include <algorithm>

#define pii pair<int,int>

using namespace std;


int n,k;
string s;
int max_ans = -1;
bool flag = false;
int dp[1000001][11]; //숫자,depth

int dfs(string str, int cnt){
    
    if(cnt == k){
        return stoi(str);
    }

    int num = stoi(str);
    int& ans = dp[num][cnt];
    if(ans != -1) return ans;

    for(int i = 0; i< str.size()-1; i++ ){
        for(int j = i+1; j < str.size(); j++){
            if (i == 0 && str[j] == '0') continue;
            swap(str[i],str[j]);
            ans = max(ans,dfs(str,cnt+1));
            swap(str[i],str[j]);
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    s = to_string(n);

    if(s.size() == 1 || (s.size() ==2 && s[1] =='0')){
        cout << -1;
        return 0;
    }

    memset(dp, -1, sizeof(dp));
    cout << dfs(s,0);
    return 0;

}