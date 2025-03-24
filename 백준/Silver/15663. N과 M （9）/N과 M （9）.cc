#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N,M;
vector<int> arr,result;
bool visit[10];

void backtrack(int cnt){
    if(cnt == M){
        for(int i = 0; i<M;i++){
            cout << result[i] <<" ";
        }
        cout <<"\n";
        return;
    }
    int prev = -1;
    for(int i = 0; i< N; i++){
        if(visit[i] == true || prev == arr[i]) continue;
        visit[i] = true;
        result.push_back(arr[i]);
        prev = arr[i];
        backtrack(cnt+1);
        visit[i] = false;
        result.pop_back();
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < N;i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }
    sort(arr.begin(),arr.end());
    backtrack(0);
}