#include <iostream>
#include <string>
using namespace std;

string get(const string& from, int l, int r, int c) {
	int ind = c * l + r;
	if (ind >= from.size()) return "*";
	else return from.substr(ind, 1);
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		int l = 1;
		while (l * l < s.size()) l++;
		
		for (int r = 0; r< l; r++) {
			for (int c = l-1; c >= 0; c--) {
			//for (int c = 0; c < l;c++) {
				string t = get(s, l, r, c);
				if (t != "*") cout << t;
			}
		}
		cout << endl;

	}
}
