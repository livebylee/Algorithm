#include <iostream>
#include <stack>
#define pii pair<int,int>

using namespace std;

int n;
stack<pii> s;
stack<pii> s2;
int bd[100001];
int cnt[100001];
int near[100001] = {99999999};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> bd[i];
    }
    fill(near, near + 100001, 99999999);
    for(int i = 1; i <= n; i++){
        int now = bd[i];
        while(!s.empty() && s.top().first <= now){
            s.pop();
        }
        cnt[i] = s.size();
        if(cnt[i]!=0){
            near[i] = s.top().second;
        }
        s.push({now,i});
    }
    for(int i = n; i > 0; i--){
        int now = bd[i];
        while(!s2.empty() && s2.top().first <= now){
            s2.pop();
        }
        cnt[i] += s2.size();
        if(s2.size()!=0){
            if((i-near[i]) > (s2.top().second - i) || near[i]==99999999){
                near[i] = s2.top().second;
            }
        }
        s2.push({now,i});
    }
    for(int i = 1 ; i<= n ; i++){
        cout << cnt[i];
        if(cnt[i]!=0){
            cout <<" " << near[i];
        }
        cout <<'\n';
    }
}