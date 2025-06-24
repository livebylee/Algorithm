#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string n,m;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    reverse(n.begin(), n.end());
    reverse(m.begin(), m.end());

    cout << max(stoi(n),stoi(m));
}