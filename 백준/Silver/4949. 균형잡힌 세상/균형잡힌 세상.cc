#include <iostream>
#include <stack>

using namespace std;

string line;
 
bool check(string line)
{
  stack<char> stk;
 
  for (char c : line){
    if (c == '(' || c == '['){
      stk.push(c);
    }
    else if (c == ')'){
      if (!stk.empty() && stk.top() == '(') stk.pop();
      else return false;
    }
    else if (c == ']'){
      if (!stk.empty() && stk.top() == '[') stk.pop();
      else return false;
    }
  }
  return stk.empty();
}
 
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
 
  while (true){
    getline(cin, line);
    if (line == ".") return 0;
 
    if (check(line)) cout << "yes\n";
    else cout << "no\n";
  }
}
