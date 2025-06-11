#include <iostream>
#include <vector>

using namespace std;

int k;
vector<int> v;
vector<int> tmp;

void backtrack(int now){
    if(tmp.size()==6){
        for(auto a : tmp){
            cout << a <<" ";
        }
        cout <<'\n';
        return;
    }
    for(int i = now; i< k; i++){
        tmp.push_back(v[i]);
        backtrack(i+1);
        tmp.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true){
        cin >> k;
        if(k==0) break;
        for(int i= 0; i < k; i++){
            int n;
            cin >> n;
            v.push_back(n);
        }
        backtrack(0);
        v.clear();
        tmp.clear();
        cout <<'\n';
    }
}