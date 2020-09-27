#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

struct die {
	int top;
	int bottom;
	int front;
	int back;
	int left;
	int right;
};


struct hashD {
	ssize_t operator()(const die &lhs) const {
		return 17 + 31 * (lhs.top + lhs.bottom) + 53 * (lhs.front + lhs.back) + 71 * (lhs.left + lhs.right);
	}

	bool operator()(const die &lhs, const die &rhs) const {
		vector<int> l;
		l.push_back(lhs.top + lhs.bottom);
		l.push_back(lhs.front + lhs.back);
	}
};

int main() {
	int n; cin >> n;

	unordered_set<die, hashD> d;

	int top, bot, fro, bac, lef, rig;
	for (int i = 0; i < n; i++) {
		cin >> top >> bot >> fro >> bac >> lef >> rig;
		die temp;
		temp.top = top;
		temp.bottom = bot;
		temp.front = fro;
		temp.back = bac;
		temp.left = lef;
		temp.right = rig;
		d.insert(temp);
	}

	cout << d.size() << endl;
}
