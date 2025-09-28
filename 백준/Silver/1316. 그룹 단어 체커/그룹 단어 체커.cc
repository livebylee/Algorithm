#include<iostream>

using namespace std;

int n;
int ans;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0; i< n; i++){
        string s;
        cin >> s;
        int check[26];
        for(int j = 0; j< 26; j++){
            check[j] = 0;
        }
        for(int j = 0; j< s.length(); j++){
            if(j!= 0 && s[j] == s[j-1]){
                continue;
            }
            check[s[j]-'a']++;
        }
        for(int j = 0; j< s.length(); j++){
            if(check[s[j]-'a'] > 1){
                break;
            }
            if(j == s.length()-1) ans++;
        }
    }
    cout << ans;
}