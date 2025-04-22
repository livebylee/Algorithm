#include <iostream>
#include <vector>

#define pii pair<int,int>

using namespace std;

int n,d;
vector<pii> highway[10001];
int dist[10001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> d;
    for(int i = 0; i< n ;i++){
        int start,end,dis;
        cin >> start >> end >> dis;
        if(end-start > dis && end <= d){
            highway[start].push_back(pii(end,dis));
        }
    }
    fill(dist,dist+10001,1e9);
    dist[0] = 0;
    for(int i = 0 ; i <= d; i++){
        if(i >0){
            dist[i] = min(dist[i],dist[i-1]+1);
        }
        for(auto p : highway[i]){  //해당 위치에서의 고속도로
            int next = p.first;
            int nowdist = p.second;
            dist[next] = min(dist[next],dist[i]+nowdist); //도착위치까지의 최단거리 업데이트트
        }
    }
    cout << dist[d];
}