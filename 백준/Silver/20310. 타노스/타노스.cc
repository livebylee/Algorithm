#include <iostream>

using namespace std;

string s;
int zerocnt;
int onecnt;
bool arr[501];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;

    int len = s.length();

    for(int i = 0; i< len; i++){
        if(s[i] == '0') zerocnt++;
        else onecnt++;
        arr[i] = true;
    }

    zerocnt /= 2;
    onecnt /= 2;

    for(int i = len-1; i>= 0; i--){
        if(s[i] == '0'){
            zerocnt--;
            arr[i] = false;
        }
        if(zerocnt == 0) break;
    }

    for(int i = 0; i < len; i++){
        if(s[i] == '1'){
            onecnt--;
            arr[i] = false;
        }
        if(onecnt == 0) break;
    }

    for(int i = 0; i< len; i++){
        if(arr[i]) cout << s[i];
    }
}