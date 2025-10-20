#include <iostream>
#include <math.h>

using namespace std;

double getDistance(double x1, double y1, double x2, double y2){
	return sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	double x1, x2, x3, x4, y1, y2, y3, y4;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
	cout.precision(10);

	double offset = 0.00;
	double min = 100000;
	double low = 0, high = 100,p,q;
	while (high - low >= 1e-6)
	{
		p = (2 * low + high) / 3;     // 1:2 구간
		q = (low + 2 * high) / 3;     // 2:1 구간

		double dist_p = getDistance(x1 + (x2 - x1) * (p / 100), y1 + (y2 - y1) * p / 100, x3 + (x4 - x3) * (p / 100), y3 + (y4 - y3) * (p / 100));
		double dist_q = getDistance(x1 + (x2 - x1) * (q / 100), y1 + (y2 - y1) * q / 100, x3 + (x4 - x3) * (q / 100), y3 + (y4 - y3) * (q / 100));
		if (dist_p > dist_q){
			low = p;
		}
		else{
			high = q;
		}
		min = std::min(min, std::min(dist_p, dist_q));
	}
	cout << min;
}