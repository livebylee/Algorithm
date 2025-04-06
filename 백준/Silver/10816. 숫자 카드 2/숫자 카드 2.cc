#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int n,m;
map<int,int> arr;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0 ;i < n; i++){
        int x;
        cin >> x;
        arr[x]++;
    }
    cin >> m;
    for(int i = 0; i< m; i++){
        int x;
        cin >> x;
        cout << arr[x] << " ";
    }
}