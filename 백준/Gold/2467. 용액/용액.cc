#include <iostream>
#include <vector>

using namespace std;

int n;
int anslow,anshigh;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    vector<int> s(n);
    for(int i = 0; i< n ; i++){
        cin >> s[i];
    }
    int low = 0;
    int high = n-1;
    long long minabs = 3000000000;
    while(low < high){
        if (minabs > abs(s[low]+s[high])){
            minabs = abs(s[low]+s[high]);
            anslow = low;
            anshigh = high;
        }
        if(s[low]+s[high] < 0){
            low++;
        }else if(s[low]+s[high]==0){
            break;
        }else{
            high--;
        }
    }
    cout << s[anslow] <<" " <<s[anshigh];
}