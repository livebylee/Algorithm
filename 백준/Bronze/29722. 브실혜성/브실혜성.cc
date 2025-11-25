#include <iostream>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string today;
    int N;
    cin >> today >> N;

    int yyyy = stoi(today.substr(0, 4));
    int mm = stoi(today.substr(5, 2));
    int dd = stoi(today.substr(8, 2));

    long long totalDays = yyyy * 360 + mm * 30 + dd;
    totalDays += N;

    yyyy = totalDays / 360;
    totalDays %= 360;
    mm = totalDays / 30;
    dd = totalDays % 30;


    if (dd == 0){
        dd = 30;
        mm -= 1;
    }
    if (mm == 0){
        mm = 12;
        yyyy -= 1;
    }

    cout << yyyy << "-";
    if(mm < 10) cout << "0";
    cout << mm << "-";
    if(dd < 10) cout << "0";
    cout << dd;

    return 0;
}