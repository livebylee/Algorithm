#include <iostream>
#include <algorithm>
#include <queue>
#define pii pair<int,int>

using namespace std;

int a,b,c,t;
bool visit[1001][1001];

int bfs(){
    queue<pii> mq;
    mq.push(pii(a,b));
    visit[a][b] = true;

    while(!mq.empty()){
        int ca = mq.front().first;
        int cb = mq.front(). second;
        int cc = t - ca - cb;
        mq.pop();
        if(ca == cb && ca == cc){
            return 1;
        }
        int f[3] = {ca,ca,cb};
        int s[3] = {cb,cc,cc};
        for(int i = 0; i<3 ;i++){
            int na = f[i];
            int nb = s[i];
            if(na < nb){
                nb = nb - na;
                na += na;
            }else if(na > nb){
                na = na - nb;
                nb += nb;
            }else{
                continue;
            }
            int nc = t- na -nb;
            int aa = min(min(na,nb),nc);
            int bb = max(max(na,nb),nc);
            if(visit[aa][bb] == false){
                visit[aa][bb] = true;
                mq.push(pii(aa,bb));
            }
        }
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> b >> c;
    t = a+b+c;

    int maxn = max(max(a,b),c);
    int minn = min(min(a,b),c);
    a = maxn;
    b = minn;
    c = t - a -b;

    if(t % 3 != 0){
        cout << 0;
        return 0;
    }else{
        cout << bfs();
    }
}