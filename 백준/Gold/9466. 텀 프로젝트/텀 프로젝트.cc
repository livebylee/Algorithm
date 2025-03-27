#include <iostream>
#include <cstring>

using namespace std;

int T;
int num[100001];
bool visit[100001];
bool done[100001];
int cnt;

void dfs(int start){
    visit[start] = true;
    int next = num[start];
    if(!visit[next]){ //방문 안했으면 방문
        dfs(next);
    }else if(done[next]==false){//사이클
        for(int i = next; i != start; i = num[i]){
            cnt++;
        }
        cnt++; //자기자신
    }
    done[start] = true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while(T--){
        int n;
        cin >> n;
        memset(visit,false,sizeof(visit));
        memset(done,false,sizeof(done));
        for(int i = 1; i <= n; i++){
            cin >> num[i];
        }
        cnt = 0;
        for(int i = 1; i <= n; i++){
            if(visit[i] == false){
                dfs(i);
            }
        }
        cout << n-cnt << '\n';
    }
}