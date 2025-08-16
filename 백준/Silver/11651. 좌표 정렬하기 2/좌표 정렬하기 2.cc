#include <iostream>
#include <algorithm>
#include <vector>
#define pii pair<int,int>

using namespace std;

vector<pii> v;

int main(void){

    int n, a, b;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a >> b;
        v.push_back({b, a});
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++){
        printf("%d %d\n", v[i].second, v[i].first);
    }
}