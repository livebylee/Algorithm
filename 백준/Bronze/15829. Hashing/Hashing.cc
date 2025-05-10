#include <iostream>

using namespace std;

int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n; 
    long long value = 0;
    long long cal = 1;
    for(int i = 0; i< n; i++){
        char c;
        cin >> c;
        int now = c-'a'+1;
        now = (now * cal) % 1234567891;
        cal = (cal * 31)  % 1234567891;
        value += now  % 1234567891;
    }
    cout << value  % 1234567891;
}