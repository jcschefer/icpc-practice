#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int x, y, x1, y1, x2, y2;
	cin >> x >> y >> x1>>y1>>x2>>y2;

	if (x > x1 && x < x2) {
		cout << fmin(fabs(y2-y), fabs(y1-y)) <<endl;
	} else if (y > y1 && y < y2) {
		cout << fmin(fabs(x2-x), fabs(x1-x)) << endl;
	} else {
		double ans=hypot(x-x1, y-y1);
 		ans = fmin(ans, hypot(x-x2, y-y2));
		ans = fmin(ans, hypot(x-x1, y-y2));
		ans = fmin(ans, hypot(x-x2, y-y1));
		cout << ans << endl;
	}

	return 0;
}
