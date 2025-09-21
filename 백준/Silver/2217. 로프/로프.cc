#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> ropes;
int max_w;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0; i< n; i++){
        int x;
        cin >> x;
        ropes.push_back(x);
    }
    sort(ropes.begin(),ropes.end(),greater<int>());

    for(int i = 0; i< n; i++){
        int curr = ropes[i];
        max_w = max(max_w,curr * (i+1));
    }
    cout << max_w;
}