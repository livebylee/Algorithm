#include <iostream>
#include <vector>
#include <cmath> // std::abs, std::round
#define pii pair<long long ,long long>

using namespace std;

int n;
vector<pii> point;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0; i< n; i++){
        long long x,y;
        cin >> x >> y;
        point.push_back({x,y});
    }
    point.push_back(point[0]);

    long double ans = 0;
    for(int i = 0; i< n; i++){
        ans += ((point[i].first * point[i+1].second) - (point[i+1].first * point[i].second));
    }
    ans = abs(ans) / 2.0;

    // 반올림해서 소수 첫째 자리까지 출력
    cout << fixed;
    cout.precision(1);
    cout << round(ans * 10) / 10.0 << "\n";
}