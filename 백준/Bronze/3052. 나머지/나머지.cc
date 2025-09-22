#include <iostream>
#include <set>
using namespace std;

set<int> myset;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i = 1; i<= 10; i++){
        int n;
        cin >> n;
        myset.insert(n%42);
    }
    cout << myset.size();
}