#include <iostream>
#include <queue>
#define pii pair<int,int>

using namespace std;

int r,c;
int lake[1500][1500];  // 0 물 1 빙판 (백조도 물)
bool visit_water[1500][1500];
bool visit_swan[1500][1500];
queue<pii> water,water_next;
queue<pii> swan, swan_next;

int day = 0;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

pii swan1 = {-1,-1};
pii swan2 = {-1,-1};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> r >> c;
    for(int i = 0; i < r; i++){
        string s;
        cin >> s;
        for(int j = 0; j< c; j++){
            if(s[j]=='.'){
                lake[i][j] = 0;
                water.push({i,j});
                visit_water[i][j] = true;
            }else if(s[j]=='X'){
                lake[i][j] = 1;
            }else{ //백조
                if(swan1.first == -1) swan1 = {i,j};
                else swan2 = {i,j};
                visit_water[i][j] = true;
                water.push({i,j});
                lake[i][j] = 0;
            }
        }
    }

    swan.push(swan1);
    visit_swan[swan1.first][swan1.second] = true;

    while(true){
        while(!swan.empty()){
            pii curr = swan.front();
            swan.pop();
            if(curr == swan2){
                cout << day;
                return 0;
            }
            for(int dir = 0; dir < 4; dir++){
                int nx = curr.first + dx[dir];
                int ny = curr.second + dy[dir];
                if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
                if(visit_swan[nx][ny]) continue;
                visit_swan[nx][ny] = true;
                if(lake[nx][ny] == 1){
                    swan_next.push({nx,ny});
                }else{
                    swan.push({nx,ny});
                }
            }
        }

        while(!water.empty()){
            int x = water.front().first;
            int y = water.front().second;
            water.pop();
            for(int dir = 0 ; dir < 4; dir++){
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
                if(visit_water[nx][ny]) continue;
                visit_water[nx][ny] = true;
                if(lake[nx][ny] == 1){
                    lake[nx][ny] = 0; // 내일 녹아서 물
                    water_next.push({nx,ny});
                }else{
                    water.push({nx,ny});
                }
            }
        }

        swan.swap(swan_next);
        while(!swan_next.empty()) swan_next.pop();
        water.swap(water_next);
        while(!water_next.empty()) water_next.pop();

        day++;
    }
}
