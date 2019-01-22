#include <iostream>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		if (n == -1) break;
		int last=0;
		int tot = 0;
		for (int i = 0; i < n; i++) {
			int speed, elap;
			cin >> speed >> elap;

			tot += speed * (elap - last);
			last = elap;
		}

		cout << tot << " miles" << endl;
	}
}
