#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;
typedef pair<string, string> ss;

#define DDD 1
#define DEBUG if(DDD)

vector<ss> names;
bool check(int i) {
	unordered_set<string> used;
	string n;
	int from_sec;
	for (auto &ele : names) {
		from_sec = min(i - 1, (int) ele.second.size());
		n = ele.second.substr(0, from_sec);
		n += ele.first.substr(0, i - from_sec);
		DEBUG cout << n << endl;
		if (used.find(n) != used.end()) {
			return false;
		} else {
			used.insert(n);
		}
	}

	return true;
}

int main() {
	int n;
	cin >> n;
	names.resize(n);
	string f, l;
	for (int i = 0; i < n; i++) {
		cin >> f >> l;
		names[i] = ss(f,l);
	}
	
	int i = 2;
	while (!check(i)) i++;

	cout << i;
}
