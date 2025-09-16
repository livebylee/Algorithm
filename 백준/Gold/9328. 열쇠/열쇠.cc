#include <iostream>
#include <set>
#include <queue>
#include <vector>
#include <cctype>
#define pii pair<int,int>
using namespace std;

int t;
int h,w;
char board[101][101];
bool visit[101][101];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
vector<pii> door[26];   // 문 임시 대기열 (키 찾으면 진입)

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while(t--){
        cin >> h >> w;
        for(int i = 0; i< h; i++){
            string s;
            cin >> s;
            for(int j = 0; j< w; j++){
                board[i][j] = s[j];
            }
        }

        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                visit[i][j] = false;
        for (int i = 0; i < 26; i++) door[i].clear();

        string keys;
        set<char> mykey;
        cin >> keys;

        for(int i = 0; i< keys.length(); i++){
            if(keys[i] == '0') break;
            mykey.insert(keys[i]);
        }

        queue<pii> mq;
        int cnt = 0;

        auto unlock_doors = [&](char k){
            int idx = k -'a';
            for(pii pos : door[idx]){
                int x = pos.first;
                int y = pos.second;
                if(!visit[x][y]){
                    visit[x][y] = false;
                    mq.push({x,y});
                }
            }
            door[idx].clear();
        };

        for(int i = 0; i< h; i++){
            for(int j = 0; j< w; j++){
                if(i ==0 || j ==0 || i == h-1 || j== w-1){
                    char c = board[i][j];
                    if(c == '*') continue;

                    if(islower(c)){
                        if(mykey.insert(c).second){
                            unlock_doors(c);
                        }
                        if(!visit[i][j]){
                            mq.push({i,j});
                            visit[i][j] = true;                          
                        }
                    }else if(isupper(c)){
                        char need = tolower(c);
                        if(mykey.count(need)){
                            mq.push({i,j});
                            visit[i][j] = true;
                        }else{
                            door[c-'A'].push_back({i,j});
                        }
                    }else if(board[i][j] == '$'){
                        mq.push({i,j});
                        visit[i][j] = true;
                        cnt++;
                        board[i][j] = '.';
                    }else{
                        mq.push({i,j});
                        visit[i][j] = true;
                    }
                }
            }
        }

        while(!mq.empty()){
            pii now = mq.front();
            mq.pop();
            for(int i = 0; i< 4; i++){
                int nx = now.first + dx[i];
                int ny = now.second + dy[i];
                if(nx < 0 || ny < 0 || nx > h-1 || ny > w-1) continue;
                if(visit[nx][ny]) continue; 

                char next = board[nx][ny];
                if(next == '*') continue;

                if(next == '.'){
                    mq.push({nx,ny});
                    visit[nx][ny] = true;
                }else if(next == '$'){
                    cnt++;
                    mq.push({nx,ny});
                    visit[nx][ny] = true;
                    board[nx][ny] = '.';
                }else if(islower(next)){
                    if (mykey.insert(next).second) {
                        unlock_doors(next);
                    }
                    visit[nx][ny] = true;
                    mq.push({nx,ny});
                }else if(isupper(next)){
                    char need = tolower(board[nx][ny]);
                    if(mykey.find(need)!= mykey.end()){
                        mq.push({nx,ny});
                        visit[nx][ny] = true;
                    }else{
                        door[next-'A'].push_back({nx,ny});
                    }
                }
            }
        }
        cout << cnt << '\n';
    }
}