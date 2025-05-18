#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> r;
vector<int> l;
int n,m;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for(int i = 0; i< n; i++){
        int x;
        cin >> x;
        if(x>0){
            r.push_back(x);
        }else{
            l.push_back(-x);
        }
    }
    sort(r.begin(),r.end());
    sort(l.begin(),l.end());
    int ans = 0;
    int maxr = 0;
    int maxl = 0;
    if(r.size()!=0){
        for(int i = r.size()-1; i >= 0; i -= m){
            ans += (2 * r[i]);
        }
        maxr = r[r.size()-1];
    }
    if(l.size()!=0){
        for(int i = l.size()-1; i >= 0; i -= m){
            ans += (2 * l[i]);
        }
        maxl = l[l.size()-1];
    }
    ans -= max(maxr,maxl);
    cout << ans;
}