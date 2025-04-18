#include <iostream>
#include <vector>
#include <algorithm>

#define pii pair<int,int>

using namespace std;

int n, m, l, k;
vector<pii> star;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> l >> k;

    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        star.push_back({x, y});
    }

    int maxs = 0;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            int x1 = star[i].first;
            int y1 = star[j].second;
            int x2 = x1 + l;
            int y2 = y1 + l;

            int cnt = 0;
            for (int s = 0; s < k; s++) {
                int sx = star[s].first;
                int sy = star[s].second;
                if (sx >= x1 && sx <= x2 && sy >= y1 && sy <= y2) {
                    cnt++;
                }
            }
            maxs = max(maxs, cnt);
        }
    }
    cout << k - maxs << '\n';
}