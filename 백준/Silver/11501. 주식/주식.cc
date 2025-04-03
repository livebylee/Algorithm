#include <iostream>

using namespace std;

int t;
int stock[1000000];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while(t--){
        int n;
        cin >> n;

        for(int i = 0; i<n ;i++){
            cin >> stock[i];
        }
        long long profit = 0;
        int max = 0;
        for(int i =n-1; i>=0; i--){
            if(max < stock[i]){
                max = stock[i];
            }else{
                profit += (max-stock[i]);
            }
        }
        cout << profit <<'\n';
    }
}