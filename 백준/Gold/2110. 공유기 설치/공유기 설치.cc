#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,c;
vector<int> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> c;
    for(int i = 0; i< n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());

    int d = 0;
    for(int i = 0; i< n-1; i++){
        int gap = v[i+1] - v[i];
        d += gap;
    }
    d /= (c-1);
    int low = 1;
    int high = d;
    int result = 0;
    while(low <= high){
        int mid = (low+high)/2;
        int prev = v[0];
        int cnt = 1;
        for(int i = 1; i< n; i++){
            if(prev + mid <= v[i]){
                prev = v[i];
                cnt++;
            }
        }
        if(cnt >= c){
            result = mid;
            low = mid +1;
        }else{
            high = mid -1;
        }
    }
    cout << result ;
}
