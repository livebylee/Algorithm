#include <iostream>
#include <vector>
#include <stack>
#include <string>      
#include <algorithm>    

using namespace std;

int n;
vector<int> sign;
string max_str = ""; 
string min_str = ""; 

void dfs(stack<int> s, bool visit[10]) {
    if (s.size() == n + 1) {
        string num_str = "";
        stack<int> temp_s = s; 
        while (!temp_s.empty()) {
            num_str += to_string(temp_s.top());
            temp_s.pop();
        }

        reverse(num_str.begin(), num_str.end());

        if (min_str == "") {
            min_str = num_str;
        }
        if (max_str == "") {
            max_str = num_str;
        }
        else {
            if (num_str < min_str) min_str = num_str;
            if (num_str > max_str) max_str = num_str;
        }
        return;
    }

    int nowsign = s.size() - 1;
    if (sign[nowsign] == 0) { // <
        for (int i = s.top() + 1; i <= 9; i++) {
            if (!visit[i]) {
                s.push(i);
                visit[i] = true;
                dfs(s, visit);
                visit[i] = false;
                s.pop();
            }
        }
    } else { // >
        for (int i = 0; i < s.top(); i++) {
            if (!visit[i]) {
                s.push(i);
                visit[i] = true;
                dfs(s, visit);
                visit[i] = false;
                s.pop();
            }
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        if (c == '>') {
            sign.push_back(1); // > : 1
        } else {
            sign.push_back(0); // < : 0
        }
    }
    for (int i = 0; i <= 9; i++) {
        stack<int> s;
        bool visit[10]; 
        for (int j = 0; j < 10; j++) visit[j] = false; 
        s.push(i);
        visit[i] = true;
        dfs(s, visit);
    }
    cout << max_str << "\n";
    cout << min_str;
}