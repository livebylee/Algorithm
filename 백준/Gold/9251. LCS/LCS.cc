#include <iostream>

using namespace std;

string str1;
string str2;
int check[1001][1001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> str1;
    cin >> str2;
    
    int lcs =0;
    for(int i = 1; i<= str1.length();i++){
        for(int j = 1; j<=str2.length();j++){
            if(str1[i-1] == str2[j-1]){
                check[i][j] = check[i-1][j-1] + 1;
            }else{
                check[i][j] = max(check[i-1][j],check[i][j-1]);
            }
        }
    }
    cout << check[str1.length()][str2.length()];
}