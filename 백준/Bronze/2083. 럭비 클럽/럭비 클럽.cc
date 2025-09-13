#include <iostream>

using namespace std;

string name;
int age,weight;
string res;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(true){
        cin >> name >> age >> weight;
        if(name =="#") break;
        if(age > 17 || weight >= 80){
            res = "Senior";
        }else res = "Junior";
        cout << name << " " << res <<'\n';
    }
}