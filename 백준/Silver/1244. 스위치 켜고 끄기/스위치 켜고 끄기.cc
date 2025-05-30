#include <iostream>

using namespace std;

int n,k;
int s[101];

void boy(int num){
    for(int i = num; i<= n; i+= num){
        int res= (s[i] == 1) ? 0 : 1;
        s[i] = res;
    }
}

void girl(int num){
    int res= (s[num] == 1) ? 0 : 1;
    s[num] = res;
    for(int i= 1; num+i <= n && num - i >0 ; i++){
        if(s[num+i] != s[num-i]){
            break;
        }
        res= (s[num+i] == 1) ? 0 : 1;
        s[num+i] = res;
        s[num-i] = res;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    
    for(int i =1; i<= n; i++){
        cin >> s[i];
    }

    cin >> k;
    for(int i = 0; i< k; i++){
        int sex, num;
        cin >> sex >> num;
        if(sex == 1) boy(num);
        else girl(num);
    }
    for(int i = 1; i<= n; i++){
        cout << s[i] <<" ";
        if(i % 20 == 0) cout <<'\n';
    }
}