#include <iostream>
#include <algorithm>

using namespace std;

int n;
long long arr[5001];
long long a,b,c;
long long ans = 3000000001;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0; i< n; i++){
        cin >> arr[i];
    }

    sort(arr,arr+n);

    for(int i = 0; i< n-2; i++){
        for(int j = i+1; j< n-1; j++){
            long long cur = arr[i] + arr[j];
            int start = j+1;
            int end = n-1;
            long long prevmin = 3000000001;
            while(start <= end){
                int mid = (start+end)/2;
                if(cur +arr[mid] < 0){
                    start = mid+1;
                }else if(cur + arr[mid] > 0){
                    end = mid -1;
                }else{
                    cout << arr[i] << " "<< arr[j] << " "<< arr[mid];
                    return 0;
                }
                long long nowmin = abs(cur + arr[mid]);
                if(ans > nowmin){
                    ans = nowmin;
                    a = arr[i];
                    b = arr[j];
                    c = arr[mid];
                }
                prevmin = nowmin;
            }
        }
    }
    cout << a <<" " << b <<" " << c;
}