#include <iostream>
using namespace std;

int main() {
	int tc = 1;
	double x, y; int r;

	while (cin >> x) {
		cin >> y >> r;

		double za = 0, zb = 0;
		double ca = x, cb = y;
		double magsq = 0;
		int i;
		for (i = 0; i < r; i++) {
			double tempa = za, tempb = zb;
			za = tempa * tempa - tempb * tempb + ca;
			zb = 2 * tempa * tempb + cb;

			magsq = za * za + zb * zb;

			if (magsq > 4) break;
		}

		if (magsq > 4) cout << "Case " << tc << ": OUT" << endl; 
		else cout << "Case " << tc << ": IN" << endl;

		tc++;
	}
}
