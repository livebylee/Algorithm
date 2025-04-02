#include <iostream>

using namespace std;

int h,w;
int block[500];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> h >> w;
    for(int i = 0; i < w; i++){
        cin >> block[i];
    }

    int water = 0;
    for(int floor = 1; floor <= h; floor++){
        int now = 0;
        bool start = false;
        for(int i = 0; i < w; i++){
            if(block[i] >= floor){
                if(start==true){
                    water += now;
                }
                start = true;
                now = 0; 
            }else{
                now++;
            }
        }
    }
    cout << water;
}