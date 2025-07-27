#include <iostream>
#include <map>

using namespace std;

struct Node{
    map<string, Node*> children;
};

Node* root = new Node();
int n;

void dfs(Node* curr,int depth){
    for(auto next : curr->children){
        for(int i = 0 ; i < depth; i++){
            cout <<"--";
        }
        cout << next.first << '\n';
        dfs(next.second,depth+1);
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    while(n--){
        int k;
        cin >> k;
        Node* curr = root;

        for(int i = 0; i< k; i++){
            string food;
            cin >> food;
            if(curr->children.find(food) == curr->children.end()){
                curr ->children[food] = new Node();
            }
            curr = curr -> children[food];
        }
    }
    int depth = 0;
    dfs(root,depth);
}