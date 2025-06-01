#include <iostream>
#include <vector>
#define MAX 1000001

using namespace std;

int n,m;
vector<int> st;
int pre[MAX];
int nex[MAX];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i< n; i++){
        int x;
        cin >> x;
        st.push_back(x); 
    }
    for(int i = 0; i< n; i++){
        int now = st[i];
        if(i==0){
            pre[now] = st[n-1];
            nex[now] = st[1];
        }else if(i == n-1){
            pre[now] = st[n-2];
            nex[now] = st[0];
        }else{
            pre[now] = st[i-1];
            nex[now] = st[i+1];
        }
    }
    while(m--){
        string cmd;
        cin >> cmd;
        int i,j;
        if(cmd=="BN"){
            cin >> i >> j;
            cout << nex[i] <<'\n';
            pre[j] = i;
            nex[j] = nex[i];
            pre[nex[i]] = j;
            nex[i] = j;
        }else if(cmd=="BP"){
            cin >> i >> j;
            cout << pre[i] <<'\n';
            pre[j] = pre[i];
            nex[j] = i;
            nex[pre[i]] = j;
            pre[i] = j;
        }else if(cmd=="CN"){
            cin >> i;
            cout << nex[i] <<'\n';
            int tmp = nex[nex[i]];
            pre[tmp] = i;
            nex[i] = tmp;
        }else{
            cin >> i;
            cout << pre[i] <<'\n';
            int tmp = pre[pre[i]];
            nex[tmp] = i;
            pre[i] = tmp;
        }
    }
}