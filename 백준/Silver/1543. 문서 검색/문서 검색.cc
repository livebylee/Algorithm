#include <iostream>

using namespace std;

string input;
string word;
int cnt;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    getline(cin,input);
    getline(cin, word);

    int i = 0;
    while(i + word.length() <= input.length()){
        for(int j = 0; j< word.length(); j++){
            if(input[i+j] != word[j]) break;
            if(j == word.length()-1){
                cnt++;
                i += (word.length()-1);
            }  
        }
        i++;
    }
    cout << cnt;
}