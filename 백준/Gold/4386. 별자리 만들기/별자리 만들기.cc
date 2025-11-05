#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#define pii pair<float,float>
#define pip pair<float,pii>
using namespace std;

int n;
float ans;
vector<pii> star;
priority_queue<pip,vector<pip>,greater<pip>> pq;
int parent[101];

int find(int a){
    if(parent[a] == a) return a;
    return parent[a] = find(parent[a]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i = 0; i< n; i++){
        parent[i] = i;
    }

    for(int i = 0; i< n; i++){
        float x,y;
        cin >> x >> y;
        star.push_back({x,y});
    }

    for(int i = 0; i< n; i++){
        for(int j = i+1; j< n; j++){
            float x = star[i].first - star[j].first;
            float y = star[i].second - star[j].second;
            float d = sqrt(x*x + y*y);
            pq.push({d,{i,j}});
        }
    }

    while(!pq.empty()){
        pip now =pq.top();
        int a = now.second.first;
        int b = now.second.second;
        pq.pop();
        int parent_a = find(a);
        int parent_b = find(b);
        if(parent_a == parent_b) continue;
        parent[parent_a] = parent_b;
        ans += now.first;
    }
    
    cout.precision(3);
    cout << ans;
}