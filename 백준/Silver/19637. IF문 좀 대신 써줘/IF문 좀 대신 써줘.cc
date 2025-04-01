#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#define pis pair<int,string>

using namespace std;
int n,m;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    vector<pis> name;
    set<int> s;

    for(int i = 0; i<n; i++){
        string names;
        int namef;
        cin >> names >> namef;
        int nsize = s.size();
        s.insert(namef);
        if(nsize != s.size()){
            name.push_back(pis(namef,names));
        }
    }
    sort(name.begin(),name.end());
    for(int i = 0; i<m; i++){
        int x;
        cin >> x;
        int left = 0;
        int right = name.size()-1;
        int result =right;
        while(left <= right){
            int mid = (left+right) /2;
            if(name[mid].first >= x){
                right = mid -1;
                result = mid;
            }else{
                left = mid +1;
            }
        }
        cout << name[result].second << '\n';
    }
}