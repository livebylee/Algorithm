#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n,k;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0; i< n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(),arr.end(),greater<int>());
    int mins = arr.back();

    if(arr[0] > k){
        cout << 0;
        return 0;
    }
    if(mins <= 0){
        cout << -1;
        return 0;
    }
    arr.pop_back();
    long long cnt = 0;
    for(int i = 0; i< arr.size() ;i++){
        cnt += ((k-arr[i]) / mins);
    }
    cout << cnt+1;
}