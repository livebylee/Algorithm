#include <iostream>
#include <string>
#include <cstdio>
 
using namespace std;
 
int main() {
 
    int a,b;
 
    int cnt1;
    int cnt2;
 
    while(scanf("%d%d", &a, &b)!=EOF){
        cnt1=0;
        cnt2=0; 
 
        for(int i=a; i<=b; i++){
            cnt1++;
            int cnt=0;
            int arr[10]={0};
            string str = to_string(i); 
            for(int i=0; i<str.length(); i++){
                cnt = str[i]-'0';
                arr[cnt]++;
            }
            for(int i=0; i<10; i++){
                if(arr[i]>=2){
                    cnt2+=1;
                    break;
                }
            }
        }
        cout<<cnt1-cnt2<<"\n";
    }
    return 0;
}
