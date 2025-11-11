#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#define pii pair<int,int>

using namespace std;

int n;
bool alph[26];
vector<pii> key;

int main(){

    cin >> n;
    getchar();
    for(int i = 0; i< n; i++){
        string fullline;
        getline(cin,fullline);
        istringstream iss(fullline);
        vector<string> words;
        string word;
        while(iss >> word){
            words.push_back(word);
        }
        for(int k = 0; k< words.size(); k++){
            int now_word = words[k][0] - 'A';
            if(alph[now_word%32] == false){
                alph[now_word%32] = true;
                key.push_back({k,0});
                break;
            }
        }
        if(key.size() != i+1){ //키 못 찾았으면
            bool isfind = false;
            for(int k = 0; k < words.size(); k++){
                string now_word = words[k];
                for(int j = 1; j < now_word.length(); j++){
                    int intpos = now_word[j] -'A';
                    if(alph[intpos%32]==false){
                        alph[intpos%32] = true;
                        key.push_back({k,j});
                        isfind = true;
                        break;
                    }
                }
                if(isfind == true)break;
            }
            if(isfind== false){
                key.push_back({-1,-1});
                for(auto w : words){
                    cout << w <<" ";
                }
                cout << '\n';
                continue;
            }
        }
        int wordpos = key[i].first;
        int alphpos = key[i].second;
        for(int k = 0; k < words.size(); k++ ){
            string nowword = words[k];
            if(wordpos != k){
                cout << nowword << " ";
                continue;
            }
            for(int j = 0; j< nowword.length(); j++ ){
                if(j != alphpos){
                    cout << nowword[j];
                    continue;
                }else{
                    cout << "[" << nowword[j] << "]";
                }
            }
            cout <<" ";
        }
        cout <<'\n';
    }
}