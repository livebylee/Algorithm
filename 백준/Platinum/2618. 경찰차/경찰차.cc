#include <iostream>
#include <algorithm>
#include <cstring>
#define pii pair<int,int>

using namespace std;

int N, W;
pii  arr[1001];
int dp[1001][1001];
int path[1001][1001];

int dis(pii a, pii b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

int find(int x, int y) {
	int now = max(x, y) + 1; //이번 사건
	if (now > W) return 0; //사건들 다 봤으면 끝
	pii A, B; //경찰차 1번 2번 위치
	if (x == 0) A = pii(1, 1);  //사건 간 적없으면 초기상태
	else A = arr[x]; //직전 사건 위치
	if (y == 0) B = pii(N, N);
	else B = arr[y];

	int ret = dp[x][y];
	if (dp[x][y] != -1) return ret;  //이미 온적있으면 그대로 반환
	int first = dis(A, arr[now]) + find(now, y);
	int second = dis(B, arr[now]) + find(x, now);

	if (first < second) path[x][y] = 1; //1번 움직임
	else path[x][y] = 2; //2번 움직임
	dp[x][y] = min(first, second);
	return min(first, second);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	memset(dp, -1, sizeof(dp));

	cin >> N;
	cin >> W;
	for (int i = 1; i < W+1; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	cout << find(0, 0) << '\n';
	
	int x = 0;
	int y = 0;
	while (max(x, y) < W) {
		cout << path[x][y] << '\n';
		if (path[x][y] == 1) x = max(x, y) + 1;
		else y = max(x, y) + 1;
	}
}