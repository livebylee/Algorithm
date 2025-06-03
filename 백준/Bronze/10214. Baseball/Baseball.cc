#include <iostream>

using namespace std;

int t;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while(t--){
        int y,k = 0;
        for(int i = 0; i< 9; i++){
            int s1,s2;
            cin >> s1 >> s2;
            y+=s1;
            k+=s2;
        }
        if(y>k) cout << "Yonsei\n";
        else if(y<k) cout <<"Korea\n";
        else cout << "Draw\n";
    }
}