#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int N, M;
vector<vector<int>> adj;
int depth[100001];
int parent[100001][18];

void dfs(int curr) {
	for (auto next : adj[curr]) {
		if (depth[next] != -1) continue;
		depth[next] = depth[curr] + 1;
		parent[next][0] = curr;
		dfs(next);
	}
}

int lca(int u, int v) {
	if (depth[u] < depth[v]) {
		swap(u, v);  //depth[u] >= depth[v]로 두고,  (u가 더 아래) 
	}; 
	int diff = depth[u] - depth[v]; // 높이 차이
	int j = 0;
	while (diff) { //높이 맞춰주기
		if (diff % 2) {
			u = parent[u][j]; //아래에 있는거 올리기
		}
		j++;
		diff /= 2;
	}
	if (u == v) {
		return u;
	}          //올렸는데 같으면 그냥 걔를 리턴해야함
	else{	
		for (int i = 17; i >= 0; i--) {
			if (parent[u][i] == parent[v][i]) {
				continue;
			}
			else {
				u = parent[u][i];
				v = parent[v][i];
			}
		}
		return parent[u][0];
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	adj.resize(N + 1);

	for (int i = 0; i < N-1; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	for (int i=0; i < 100001; i++) {   //depth랑 parent 초기화
		depth[i] = -1;
		for (int j = 0; j < 18; j++) {
			parent[i][j] = -1;
		}
	}
	depth[1] = 0;  //루트노드 depth 0

	dfs(1); //루트 노드에 대하여 dfs 실행 (depth만들기 ,parent기저 생성)

	for (int k = 0; k < 18; k++) {  //parent 만들기
		for (int i = 1; i < 100001; i++) {
			int temp = parent[i][k];
			if (temp != -1) {
				parent[i][k + 1] = parent[temp][k];
			}
		}
	}

	cin >> M;
	
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		int ans = lca(a, b);
		cout << ans << "\n";
	}
}
