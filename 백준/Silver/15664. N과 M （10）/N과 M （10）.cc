#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int N,M;
int first[9];
int arr[9];
bool visit[9];
set<vector<int>> s; 

void bt(int num, int k) { 
    if(k==M) { 
        vector<int> v;
        for(auto i=0;i<M;i++){
            v.push_back(arr[i]);
        }
        s.insert(v); 
        v.clear(); 
    }else { 
        for(auto i=num; i<N;i++) {
            if(!visit[i]) {
                visit[i]=true; 
                arr[k]=first[i]; 
                bt(i+1, k+1);
                visit[i]=false; 
            }
        }
    }
}

int main() {
    cin >> N >> M;

    for(int i=0;i<N;i++){
        cin >> first[i];
    }
    sort(first,first+N); 

    bt(0, 0);

    for(auto vector:s) {
        for(auto temp:vector){
            cout << temp << " ";
        }
        cout << "\n";
    }
}
