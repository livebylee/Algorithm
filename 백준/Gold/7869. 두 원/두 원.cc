#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
using namespace std;

const long double PI = acos(-1);

int main() {
    long double x1, y1, r1, x2, y2, r2;
    long double tmp;
    
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    if (r1 < r2) { 
        tmp = x1, x1 = x2, x2 = tmp;
        tmp = y1, y1 = y2, y2 = tmp;
        tmp = r1, r1 = r2, r2 = tmp;
    }
    long double cDist = (y2 - y1)*(y2-y1) + (x2 - x1)*(x2-x1); 
    long double cDistR = sqrt(cDist); 
    long double smallSize,largeSize;
    
    cout << fixed;
    cout.precision(3);
    if (cDistR > r1 + r2) { 
        cout << 0.000f;
    }
    else if (cDist  <= (r1 - r2)*(r1-r2)) {
        cout << PI * r2 * r2;
    }
    else{
        long double bigCosT = (r1 * r1 + cDistR*cDistR - r2 * r2) / (2 * r1 * cDistR);
        long double bigTheta = acos(bigCosT);
        long double bigSinT = sin(bigTheta);
        long double distH = 2*r1 * bigSinT;
        long double smallCosT = (r2 * r2 + cDistR * cDistR - r1 * r1) / (2 * r2 * cDistR);
        long double smallTheta = acos(smallCosT);
        cout << (r1 * r1 * bigTheta) + (r2 * r2 * smallTheta) - (distH * cDistR / 2);
    }
    return 0;
}