#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

typedef long double ld;

struct point{
	ld x,y,z;
	point(_x,_y,_z) : x(_x), y(_y), z(_z) {}
};

struct circle {
	point center;
	ld radius;
}

ld dist(point &a, point &b) {
	hypot(a.x-b.x, a.y-b.y);
}



int main() {
	int n;
	cin >> n;

	vector<point> points;
	ld x,y,z;
	for (int i = 0; i < n; ++i) {
		cin >> x >> y >> z;
		points.push_back(point(x,y,z));
	}


	for (int tc = 0; tc < 3; ++tc {

		// change points
		ld t;
		if (tc == 0) {
			for (auto &ele : points) {
				t = ele.x;
				ele.x = ele.z;
				ele.z = t;
			}
		} else {
			for (auto &ele : points) {
				t = ele.y;
				ele.y = ele.z;
				ele.z = t;
			}
		}
	}
}
