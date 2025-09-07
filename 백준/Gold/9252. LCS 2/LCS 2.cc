#include <iostream>
#define pis pair<int,string>
using namespace std;

string s1;
string s2;
int check[1001][1001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s1;
    cin >> s2;

    for(int i = 1; i <= s1.length(); i++){
        for(int j = 1; j <= s2.length(); j++){
            if(s1[i-1] == s2[j-1])
                check[i][j] = check[i-1][j-1] + 1;
            else
                check[i][j] = max(check[i-1][j], check[i][j-1]);
        }
    }
    cout << check[s1.length()][s2.length()] <<'\n';

    if(check[s1.length()][s2.length()]!= 0){  //역추적
        string lcs ="";
        int i = s1.length();
        int j = s2.length();
        while(i > 0 && j > 0){
            if(s1[i-1] == s2[j-1]){
                lcs = s1[i-1] + lcs;
                i--;
                j--;
            }
            else if(check[i-1][j] > check[i][j-1]) i--;
            else j--;
        }
        cout << lcs;
    }
}