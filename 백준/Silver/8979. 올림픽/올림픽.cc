#include <iostream>
#include <algorithm>

using namespace std;

struct medal{
    int name;
    int gold;
    int silver;
    int copper;
};

bool cmp(medal a, medal b){
    if(a.gold == b.gold){
        if(a.silver == b.silver){
            return a.copper > b.copper;
        }
        return a.silver > b.silver;
    }
    return a.gold > b.gold;
}
int n,k;
medal nation[1000];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    for(int i = 0 ; i < n; i++){
        cin >> nation[i].name >> nation[i].gold >> nation[i].silver >> nation[i].copper;
    }
    sort(nation, nation+n,cmp);
    int ranking = 1;

    for(int i = 0;  i < n; i++){
        medal now = nation[i];
        if(i != 0){
            medal prev = nation[i-1];
            if(prev.gold != now.gold || prev.silver != now.silver || prev.copper != now.copper){
                ranking++;
            }
        }
        if(now.name == k){
            cout << ranking;
            break;
        }
    }
}