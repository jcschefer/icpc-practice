#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main() {
	vi possible;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++) {
				possible.push_back(i + j * 10 + k * 100 + k * 1000 + j * 10000 + i * 100000);
			}
		}
	}

	int n; cin >> n;

	int p;
	while (n--) {
		cin >> p;
		ii best = ii(abs(p - possible[0]), possible[0]);
		for (auto &e : possible) {
			if (abs(p-e) < best.first) {
				best = ii(abs(p-e), e);
			}
		}

		cout << best.second << endl;
	}
}
