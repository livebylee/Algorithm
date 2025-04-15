#include <iostream>
#include <queue>

using namespace std;

int n;
priority_queue<int> pqsmall;  //가장 큰 거 나옴
priority_queue<int, vector<int> , greater<int>> pqlarge;  //가장 작은거 나옴옴

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    int mid;
    cin >> mid;
    cout << mid <<'\n';

    for(int i = 1; i< n; i++){
        int x;
        cin >> x;
        if(x > mid){
            pqlarge.push(x);
            if(pqlarge.size() > pqsmall.size()+1){
                pqsmall.push(mid);
                mid = pqlarge.top();
                pqlarge.pop();
            }
        }else{
            pqsmall.push(x);
            if(pqlarge.size() < pqsmall.size()){
                pqlarge.push(mid);
                mid = pqsmall.top();
                pqsmall.pop();
            }
        }
        cout << mid <<'\n' ;
    }
}