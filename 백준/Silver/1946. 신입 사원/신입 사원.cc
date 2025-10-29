#include <iostream>

using namespace std;

int t;
int grade[100001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;

    while(t--){
        int n,a,b;
        int cnt = 1;
        cin >> n;
        for(int i = 1; i<= n; i++){
            cin >> a >> b;
            grade[a] = b;
        }
        int ming = grade[1];
        for(int i = 2; i<= n; i++){
            if(grade[i] < ming){
                ming = grade[i];
                cnt++;
            }
        }
        cout << cnt <<'\n';
    }
}