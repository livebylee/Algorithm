#include <iostream>

using namespace std;

string s;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;

    int time = 0;
    for(auto x : s){
        if((x-'A')/3+2 < 7){
            time += (x-'A') / 3 +3;
        }else if((x-'A') >= 15 && (x-'A') <= 18){
            time += (7+1);
        }else if((x-'A') >=22){
            time += (9+1);
        }else{
            time += (8+1);
        }
    }
    cout << time;
}