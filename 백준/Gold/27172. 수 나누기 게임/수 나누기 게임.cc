#include <iostream>

using namespace std;

int n;
int a[100001];
bool is[1000001];
int score[1000001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0; i< n ; i++){
        cin >> a[i];
        is[a[i]] = true;
    }

    for(int i = 1; i< 1000001; i++){
        if(is[i]==false) continue;
        for(int j = i*2; j< 1000001; j+=i){
            if(is[j]== true){
                score[i]++;
                score[j]--;
            }
        }
    }
    for(int i = 0; i< n; i++){
        cout << score[a[i]] <<" ";
    }
}