#include <iostream>
#include <map>

using namespace std;

int N,M;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    map<string,string> m;
    string a,b;

    cin >> N >> M;

    for(int i=0;i<N;i++){
        cin >> a >> b;
        m[a] = b;
    }

    for(int i=0;i<M;i++){
        cin >> a;
        cout << m[a] << '\n';
    }

    return 0;
}