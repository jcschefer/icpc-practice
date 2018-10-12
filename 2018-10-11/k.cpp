#include <iostream>
#include <vector>

using namespace std;


int main() {
	int lastval;
	vector<int> values;
	char zigging = -1;
	int changes = 0;

	int length;
	cin >> length;

	// trivial solution
	if (length == 1) {
		cout << 1;
		return 0;
	}

	// read to array
	for (int i = 0; i < length; i++) {
		int val;
		cin >> val;
		values.push_back(val);
	}

	// getting initial direction
	int i;
	for (i = 1; i < length; i++) {
		if (values[i] > values[i-1]) {
			zigging = 1;
			break;
		}
		else if (values[i] < values[i-1]) {
			zigging = 0;
			break;
		}
	}
	if (zigging == -1) {
		cout << 1;
		return 0;
	}
	for (; i < length; i++) {
		if (zigging && values[i] < values[i-1]) {
			changes++;
			zigging = 0;
		}
		else if (!zigging && values[i] > values[i-1]) {
			changes++;
			zigging = 1;
		}
	}

	cout << changes + 2;
}
