#include<iostream>
#include <string>
using namespace std;

bool isPeriodic(string s, int k) {
	string curr = s.substr(0, k);
	int j = 0;
	while (j <	 s.size()) {
			if (curr != s.substr(j, k)) {

				//cout << curr<< " is not "<< s.substr(j, k)<<" "<< j<<" " << endl;
				return false;
			}
			if (k > 1) {
				curr = curr[k-1] + curr.substr(0,k-1);
			}

		j += k;
	}
	return true;
}

int main() {
	string s;
	cin >> s;

	for (int k = 1; k <= s.size(); k++) {
		if (s.size() % k != 0) {
			continue;
		}

		if (isPeriodic(s, k)) {
			cout << k;
			return 0;
		}
	}

	return 0;
}
