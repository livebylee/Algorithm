#include <iostream>

using namespace std;

int ttt[10];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(true){
        string s; 
        cin >> s;

        if(s== "end") break;

        int xcnt = 0;
        int ocnt = 0;

        for(int i = 1 ; i<= 9; i++){
            if(s[i-1] == 'X'){
                ttt[i] = 1;
                xcnt++;
            }
            else if(s[i-1] == 'O'){
                ttt[i] = 2;
                ocnt++;
            }
            else ttt[i] = 3; 
        }
        if((xcnt-ocnt)>1 || (xcnt < ocnt)){
            cout << "invalid" <<'\n';
            continue;
        } 
        int xbingo = 0;
        int obingo = 0;

        for(int i = 1; i <= 9; i+=3){ //가로
            if(ttt[i]==1 && ttt[i+1]==1 && ttt[i+2]== 1 ) xbingo++;
            else if(ttt[i]==2 && ttt[i+1]==2 && ttt[i+2]== 2) obingo++;
        }
        for(int i = 1; i <= 3; i++){ //세로
            if(ttt[i]==1 && ttt[i+3]==1 && ttt[i+6]== 1 ) xbingo++;
            else if(ttt[i]==2 && ttt[i+3]==2 && ttt[i+6]== 2) obingo++;
        }
        if(ttt[1]==1 && ttt[5]==1 && ttt[9]== 1 ) xbingo++;
        else if(ttt[1]==2 && ttt[5]==2 && ttt[9]== 2) obingo++;
        if(ttt[3]==1 && ttt[5]==1 && ttt[7]== 1 ) xbingo++;
        else if(ttt[3]==2 && ttt[5]==2 && ttt[7]== 2) obingo++;

        
        if((xbingo >=1 && obingo == 0 && xcnt > ocnt) || (obingo>=1 && xbingo == 0 && xcnt==ocnt) || (xbingo+obingo==0 && xcnt+ocnt==9)) cout << "valid" << '\n';
        else cout <<"invalid"<<'\n';
    }
}