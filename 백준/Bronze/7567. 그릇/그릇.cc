#include <iostream>

using namespace std;

int main(){
    int h = 10;
    string a;
    cin >> a;
    for(int i = 1; i < a.size(); i++){
        (a[i] == a[i-1]) ? h+=5 : h+=10;
    }
    cout << h;
}
