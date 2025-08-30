
#include <iostream>
#include <vector>
using namespace std;
 
int n, m, Left = 1, Right = 1;
vector<int> v;
 
int main()
{
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>m;
        v.push_back(m);
    }
 
    int temp = v[0];
    for(int i=0; i<v.size(); i++){
        if(temp<v[i]){
            temp = v[i];
            Left++;
        }
    }
 
    temp = v[v.size()-1];
    for(int i=v.size()-1; i>=0; i--){
        if(temp<v[i]){
            temp = v[i];
            Right++;
        }
    }
    cout<< Left << "\n";
    cout<< Right << "\n";
 
    return 0;
}
