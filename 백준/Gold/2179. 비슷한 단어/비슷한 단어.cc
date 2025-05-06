#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
vector<pair<string,int>> v;
int cnt, maxCnt;
string s, t;
string tmp;
vector<pair<int, string>>ans;

int main() {
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		v[i] = { tmp,i };
	}
    sort(v.begin(), v.end());
    for (int i = 0; i < n - 1; i++) {
		cnt = 0;
        while(v[i].first[cnt] == v[i+1].first[cnt]){
            cnt++;
        }
        if (v[i].first == v[i + 1].first || cnt<maxCnt)
			continue;
        if (cnt > maxCnt) {
			ans.clear();
			maxCnt = cnt;
		}
        ans.push_back({v[i].second,v[i].first});
        ans.push_back({v[i+1].second,v[i+1].first});
    }
    sort(ans.begin(),ans.end());
    s = ans[0].second;
    for (int i = 1; i <= ans.size(); i++) {
        if (ans[i].second == s) continue;
        if (s.substr(0, maxCnt) != ans[i].second.substr(0, maxCnt))
            continue;
        t = ans[i].second; 
        break;
    }
    cout << s <<'\n' << t;
}
