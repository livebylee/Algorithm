#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    double a , b;
    cin >> a >> b;
    float x = a/b;
    cout << fixed;
    cout.precision(9);
    cout << a / b;
}