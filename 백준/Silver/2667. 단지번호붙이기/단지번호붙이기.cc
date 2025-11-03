#include <iostream>
#include <queue>
#define pii pair<int,int>
using namespace std;

int n;
int map[25][25];
bool visit[25][25];
queue<pii> q;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
priority_queue<int> pq;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0; i< n; i++){
        string s;
        cin >> s;
        for(int j = 0; j< n; j++){
            map[i][j] = s[j]-'0';
        }
    }

    for(int i = 0; i< n; i++){
        for(int j = 0; j< n; j++){
            if(visit[i][j] == true || map[i][j] == 0) continue;
            int cnt = 0;
            q.push({i,j});
            visit[i][j] = true;
            while(!q.empty()){
                pii now = q.front();
                q.pop();
                cnt++;
                for(int w = 0; w< 4; w++){
                    int nx = now.first + dx[w];
                    int ny = now.second + dy[w];
                    if(nx >= 0 && nx < n && ny >= 0 && ny < n && visit[nx][ny] == false && map[nx][ny] == 1){
                        visit[nx][ny] = true;
                        q.push({nx,ny});
                    }
                }        
            }
            pq.push(-cnt);
        }
    }
    cout << pq.size() <<'\n';
    while(!pq.empty()){
        cout << -pq.top() << "\n";
        pq.pop();
    }
}