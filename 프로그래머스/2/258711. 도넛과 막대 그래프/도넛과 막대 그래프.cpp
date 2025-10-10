#include <string>
#include <vector>


using namespace std;

vector<int> adj[1000000];
int in[1000000];
int out[1000000];


vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer;
    for(auto x : edges){
        adj[x[0]].push_back(x[1]);
        in[x[1]]++;
        out[x[0]]++;
    }
    
    int donut = 0;
    int stick = 0;
    int eight = 0;
    int total = 0;
    
    for(int i = 1; i<1000000; i++){
        if(in[i] == 0 && out[i] > 1){
            answer.push_back(i);
            total = out[i];
        }else if(in[i] >= 2 && out[i] == 2){
            eight++;
        }else if(out[i] == 0 && in[i] > 0){
            stick++;
        }
    }
    donut = total - eight - stick;
    answer.push_back(donut);
    answer.push_back(stick);
    answer.push_back(eight);
    return answer;
}