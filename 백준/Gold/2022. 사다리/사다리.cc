#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

double X, Y, C;


double calculate_sum_of_reciprocal_heights(double w) {
    double hx = sqrt(X * X - w * w);
    
    double hy = sqrt(Y * Y - w * w);

    return 1.0 / hx + 1.0 / hy;
}

void solve() {
    if (!(cin >> X >> Y >> C)) return;

    double low = 0.0;

    double high = min(X, Y); 
    
    double target = 1.0 / C;

    for (int i = 0; i < 100; ++i) {
        double mid = (low + high) / 2.0;
        
        if (mid <= 0) {
            low = 0.0;
            break;
        }

        double current_sum = calculate_sum_of_reciprocal_heights(mid);

        if (current_sum > target) {
            high = mid; 
        } 
        else {
            low = mid; 
        }
    }
    cout << fixed << setprecision(3) << low << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}