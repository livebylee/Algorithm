#include <iostream>
#define MAX (1 << 17)

using namespace std;

int seg1[2*MAX];
int seg2[2*MAX];
int n,m;
const int INF = 1000000001;

int findMAX(int idx,int start,int end, int a, int b){
    if(start > b || end < a) return 0;
    if(start >= a && end <= b) return seg1[idx];
    int mid = (start+end) / 2;
    return max(findMAX(2*idx,start,mid,a,b),findMAX(2*idx+1,mid+1,end,a,b));
}

int findMIN(int idx,int start, int end, int a, int b){
    if(b < start || end < a) return INF;
    if(a <= start && end <= b) return seg2[idx];
    int mid = (start+end) / 2;
    return min(findMIN(2*idx,start,mid,a,b),findMIN(2*idx+1,mid+1,end,a,b));
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    fill(seg2, seg2 + 2*MAX, INF);
    for(int i = 0; i< n; i++){
        cin >> seg1[MAX+i];
        seg2[MAX+i] = seg1[MAX+i];
    }

    for(int i = MAX-1; i > 0; i--){
        seg1[i] = max(seg1[i*2],seg1[i*2+1]);
        seg2[i] = min(seg2[i*2],seg2[i*2+1]);
    }

    for(int i = 0; i< m ;i++){
        int a,b;
        cin >> a >> b;
        int ansmin = findMIN(1,0,MAX-1,a-1,b-1);
        int ansmax = findMAX(1,0,MAX-1,a-1,b-1);
        cout << ansmin <<" " << ansmax <<"\n";

    }
}

