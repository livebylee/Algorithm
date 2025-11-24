#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
vector<long long> lan;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> k >> n;
    long long maxans = 0;

    for(int i = 0; i < k; i++){
        long long in;
        cin >> in;
        lan.push_back(in);
        maxans = max(maxans, in);
    }

    long long low = 1, high = maxans, final = 0;

    while(low <= high){
        long long mid = (low + high) / 2;
        long long cnt = 0;

        for(auto l : lan) cnt += l / mid;
        
        if(cnt >= n){
            final = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << final;
}
