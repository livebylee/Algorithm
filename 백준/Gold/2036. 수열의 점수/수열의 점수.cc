#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<long long> v;
long long sum = 0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0; i< n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());

    int idx = 0; 
    while(idx+1 < v.size() && v[idx+1] <= 0){  // 음수 파트
        sum += (v[idx] * v[idx+1]);
        idx += 2;
    }
    while(idx < v.size() && v[idx] <= 1){  // 하나 남은 음수 , 0, 1 처리
        sum += v[idx];
        idx++;
    }

    int idx2 = v.size()-1;
    while(idx2 > idx){  // 양수파트
        sum += (v[idx2] * v[idx2-1]);
        idx2 -= 2;
    }
    if(idx2 == idx){
        sum += v[idx2];  // 하나 남은 양수
    }
    cout << sum;
}