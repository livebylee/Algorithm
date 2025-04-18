#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define pii pair<int,int>

using namespace std;

pii p[111111];
int n, m;

int find(int x) {
	if (p[x].first < 0) return x;
    int tmp = find(p[x].first);
    p[x].second += p[p[x].first].second;
	return p[x].first = tmp;
}

void merge(int a, int b,int w) {
	int na = find(a);
	int nb = find(b);

	if (na== nb) return;
    int newd = p[a].second+w;
    int orgd = p[b].second;
	p[nb].first = na;
	p[nb].second = newd-orgd;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true) {
        cin >> n >> m;
        if(n==0) break;

		for (int i = 1; i < n + 1; i++) {
			p[i].first = -1;
			p[i].second = 0;
		}
		while (m--) {
			char c;
			int a, b ,w;
			cin >> c;
			if (c == '!') {
				cin >> a >> b >> w;
				merge(a,b,w);
			}
			else {
				cin >> a >> b;
				if (find(a)==find(b)) {
					cout << p[b].second - p[a].second <<'\n';
				}
				else {
					cout << "UNKNOWN" << "\n";
				}
			}
		}
	}
}
