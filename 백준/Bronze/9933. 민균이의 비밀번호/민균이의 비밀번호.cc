#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<string> words(N);
    set<string> wordSet;

    for(int i = 0; i < N; i++) {
        cin >> words[i];
        wordSet.insert(words[i]);
    }

    for(int i = 0; i < N; i++) {
        string rev = words[i];
        reverse(rev.begin(), rev.end());
        if(wordSet.count(rev)) {
            // 비밀번호 발견
            int len = words[i].size();
            char mid = words[i][len / 2];
            cout << len << " " << mid << "\n";
            break;
        }
    }

    return 0;
}