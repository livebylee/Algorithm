#include <iostream>

using namespace std;

int t;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while(t--){
        int r;
        string s;
        cin >> r >> s;
        for(auto i : s){
            for(int j = 0; j< r; j++){
                cout << i;
            }
        }
        cout <<'\n';
    }
}