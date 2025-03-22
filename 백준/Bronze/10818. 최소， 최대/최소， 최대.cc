#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;
int MIN = 1000001;
int MAX = -1000001;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for(int i = 0; i< N; i++){
        int x;
        cin >> x;
        MIN = min(MIN,x);
        MAX = max(MAX,x);
    }
    cout << MIN << " " << MAX; 
}