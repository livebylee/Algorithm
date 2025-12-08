#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.tie(NULL);

    int n;
    cin >> n;

    int a_score = 100, b_score = 100;

    for (int i = 0; i < n; ++i){
        int a, b;
        cin >> a >> b;

        if (a > b) {
            b_score -= a;
        }
        else if (a < b) {
            a_score -= b;
        }
    }
    cout << a_score << '\n' << b_score << '\n';
}