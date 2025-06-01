#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

int n;
queue<string> inq;
unordered_set<string> tmp;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0; i< n; i++){
        string s;
        cin >> s;
        inq.push(s);
    }
    int cnt = 0;
    for(int i = 0; i< n; i++){
        string s;
        cin >> s;
        if(inq.front() == s){
            inq.pop();
        }else{
            tmp.insert(s);
            cnt++;
        }
        while(tmp.find(inq.front()) != tmp.end()){
            tmp.erase(inq.front());
            inq.pop();
        }
    }
    cout << cnt;
}