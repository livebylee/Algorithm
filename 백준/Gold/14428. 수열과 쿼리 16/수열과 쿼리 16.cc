#include <iostream>
#include <climits> //INT_MAX
#define MAX (1<<17)
#define pii pair<int,int>
using namespace std;

int n,m;
pii seg[2*MAX];

pii minpair(pii a, pii b){
    if(a.first < b.first) return a;
    else if(a.first > b.first) return b;
    return a.second < b.second ? a : b;
}
void update(int idx, int value){
    idx += MAX;
    seg[idx] = {value,idx-MAX};
    while(idx >1){
        idx /= 2;
        seg[idx] = minpair(seg[idx*2],seg[idx*2+1]);
    }
}
pii minfind(int left,int right){
    left += MAX;
    right += MAX;
    pii result = {(int)1e9+1, n};
    while(left <= right){
        if(left%2 == 1)result = minpair(result,seg[left++]);
        if(right%2==0)result = minpair(result,seg[right--]);
        left /= 2;
        right /= 2;
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < 2 * MAX; i++) {
        seg[i] = {INT_MAX, INT_MAX}; 
    }

    for(int i = 0; i< n; i++){
        cin >> seg[i+MAX].first;
        seg[i+MAX].second = i;
    }
    for(int i = MAX-1 ; i > 0; i--){ //초기화
        seg[i] = minpair(seg[i*2],seg[i*2+1]);
    }
    cin >> m;
    while(m--){
        int num,i,j;
        cin >> num >> i>> j;
        if(num==1){
            update(i-1,j);
        }else{
            cout << minfind(i-1,j-1).second+1 <<'\n';
        }
    }
}