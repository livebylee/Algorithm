#include <iostream>
#include <stack>
#define pii pair<int,int>

using namespace std;

int n,k;
string number;
int arr[500000];
stack<int> mystack;
stack<int> ans;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    cin >> number;

    int cnt = 0;

    for(int i = 0 ; i< n; i++){
        arr[i] = number[i] -'0';
        while(!mystack.empty()&& mystack.top() < arr[i] && cnt < k){
            mystack.pop();
            cnt++;
        }
        mystack.push(arr[i]);
    }

    while(cnt < k){
        cnt++;
        mystack.pop();
    }
    while (!mystack.empty()){
        ans.push(mystack.top());
        mystack.pop();
    }
    while(!ans.empty()){
        cout << ans.top();
        ans.pop();
    }
}
