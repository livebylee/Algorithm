#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define pii pair<int,int>

using namespace std;

int n,k;
priority_queue<int,vector<int>,greater<int>> bag;
priority_queue<int> tmpbag;
vector<pii> jewel;   //무게, 가치

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    for(int i = 0; i < n; i++){
        int m , v;
        cin >> m >> v;
        jewel.push_back(pii(m,v));
    }
    for(int i = 0; i < k; i++){
        int c;
        cin >> c;
        bag.push(c);
    }
    sort(jewel.begin(),jewel.end());

    long long ans = 0;
    int start = 0;
    while(!bag.empty()){
        int nowbag = bag.top();
        bag.pop();
        while(start < jewel.size() && jewel[start].first <= nowbag){
            tmpbag.push(jewel[start].second); //가치를 pq에 넣음
            start++;
        }
        if(!tmpbag.empty()){
            ans += tmpbag.top();
            tmpbag.pop();
        }
    }
    cout << ans;
}