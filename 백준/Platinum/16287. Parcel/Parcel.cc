#include <iostream>
#include <vector>

using namespace std;

int w,n;
int a[5001];
int w1[400001]; //idx 작은거
int w2[400001]; //idx 큰거

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> w >> n;
    for(int i = 0; i< n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j< n; j++){ //탐색
            int sum = a[i]+a[j];
            if(w1[sum]==0){ //현재 sum이 처음 만들어진 조합이면
                w1[sum] = i; //idx 저장
                w2[sum] = j;
            }
        }
    }
    for(int i = 0; i< n-1; i++){
        for(int j = i+1; j< n; j++){
            int target = w - (a[i]+a[j]);
            if(target > 0 && target < 400000 && w1[target]!= 0 && w1[target] != i && w1[target] != j && w2[target] != i && w2[target] != j ){
                cout << "YES" <<'\n';
                return 0;
            }
        }
    }
    cout << "NO" <<'\n';
}