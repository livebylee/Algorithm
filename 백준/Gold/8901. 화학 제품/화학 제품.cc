#include <iostream>

using namespace std;

int t;
int ia,ib,ic;
int px,py,pz;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while(t--){
        cin >> ia >> ib >> ic;
        cin >> px >> py >> pz;

        long long maxans = 0;
        for(int i = 0; i <= min(ia,ib); i++){
            long long price = 0;
            price += i * px;
            int a = ia - i;
            int b = ib - i;
            int c = ic;

            if(py > pz){
                int ycnt = min(b,c);
                int zcnt = min(a,c-ycnt);
                price += ycnt * py + zcnt * pz;
            }else{
                int zcnt = min(c,a);
                int ycnt = min(b,c-zcnt);
                price += zcnt * pz + ycnt * py;
            }
            maxans = max(maxans,price);
        }
        cout << maxans << '\n';
    }
}
