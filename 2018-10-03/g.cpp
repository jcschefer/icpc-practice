#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;

	double array[510];
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		cin >> array[i];
	}

	sort(array, array+n);

	double ans = 0.0;
	for (int i = n-1; i >= 0; i--) {
		ans += (n-i)*array[i];
	}
	cout.precision(4);
	cout << std::fixed << ans;
}
