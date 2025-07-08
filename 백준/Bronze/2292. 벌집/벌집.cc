#include <iostream>

using namespace std;

int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    int step = 0;

    for(int sum = 2; sum <= n; step++){
        sum = sum + (6*step);
    }
    if(n==1) step = 1;
    cout << step;
}