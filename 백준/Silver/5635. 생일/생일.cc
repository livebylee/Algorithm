#include <iostream>
#include <vector>
#include <algorithm>
#define pii pair<int,int>
#define pis pair<int,string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;

    cin >> n;

    vector<pair<pii, pis>> v(n);

    for (int i = 0; i < n; i++){
        cin >> v[i].second.second >> v[i].second.first >> v[i].first.second >> v[i].first.first;
    }
    sort(v.begin(), v.end());

    cout << v[n - 1].second.second << '\n' << v[0].second.second << '\n';

    return 0;
}