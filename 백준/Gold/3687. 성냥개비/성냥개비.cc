#include <iostream>
#include <vector>

using namespace std;

int t;
int list[6] = {1,7,4,2,0,8};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while(t--){
        int n,m;
        cin >> n;
        m = n;
        vector<int> maxnum;
        long long minnum = 0;

        if(n%2 == 1){
            maxnum.push_back(7);
            n-=3;
        }
        while(n>0){
            maxnum.push_back(1);
            n -= 2;
        }

        if(m == 6){
            minnum = 6;
        }else if(m <= 7){
            minnum = list[m-2];
        }else{
            if(m % 7 == 0){  //첫번째 자리 0 안되는거 예외처리리
                minnum += 8;
                m -= 7;   
            }
            else if(m % 7 <= 2){
                minnum += 1;
                m -= 2;
            }
            else if(m % 7 <= 5){
                minnum += 2;
                m -= 5;
            }else if(m % 7 == 6){
                minnum += 6;
                m -= 6;
            }
            while(m>7){
                if(m % 7 == 0){
                    minnum *= 10; 
                    minnum += 8;
                    m -= 7;   
                }else{
                    minnum *= 10;
                    m -= 6;
                }
            }
            minnum *= 10;
            minnum += list[m-2];
        }
        cout << minnum << " " ;
        for(auto i : maxnum){
            cout << i;
        }
        cout <<'\n';
    }
}