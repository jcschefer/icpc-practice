#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
	int w, p;
	cin >> w >> p;
	vector<int> walls;
	walls.push_back(0);
	for (int i = 0 ; i < p; i++) {
		int wal; cin >> wal;
		walls.push_back(wal);
	}
	walls.push_back(w);

	set<int> seen;
	vector<int> widths;
	for (int i = 0; i < walls.size(); i++) {
		for (int j = i + 1; j < walls.size(); j++) {
			int t = walls[j] - walls[i];
			if (seen.find(t) == seen.end()) {
				widths.push_back(t);
				seen.insert(t);
			}
		}
	}

	sort(widths.begin(), widths.end());
	for (int i = 0; i < widths.size(); i++) cout << widths[i] << (i != widths.size() - 1 ? " " : "\n");
}
