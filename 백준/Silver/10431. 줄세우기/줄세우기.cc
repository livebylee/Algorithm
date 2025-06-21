#include <iostream>

using namespace std;

int p;
int stu[20];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> p;
    for(int i = 1; i<= p ; i++){
        int t;
        int ans = 0;
        cin >> t;
        for(int i = 0; i< 20; i++) cin >> stu[i];
        for(int i = 0; i< 20; i++){
            for(int j = i; j <20; j++){
                if(stu[i] > stu[j]) ans++;
            }
        }
        cout << i << " " << ans <<'\n';
    }
}