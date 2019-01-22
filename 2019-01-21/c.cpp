#include <iostream>
#include <climits>
using namespace std;


// 0 = add
// 1 = sub
// 2 = mul
// 3 = div

int result2(int one, int two, int l, int m, int r);
int eval(int op, int val, int val2);

int result(int one, int two, int three) {
	if (one == 2 || one == 3) {
		int l = eval(one, 4, 4);
		return result2(two, three, l, 4, 4);
	}
	if (two == 2 || two == 3) {
		int l = eval(two, 4, 4);
		return result2(one, three, 4, l, 4);
	}
	if (three == 2 || three == 3) {
		int l = eval(three, 4, 4);
		return result2(one, two, 4, 4, l);
	}
	
	int l = eval(one, 4, 4);
	return result2(two, three, l, 4, 4);
}

int result2(int one, int two, int l, int m, int r) {
	if (one == 2 || one == 3) {
		int t = eval(one, l, m);
		return eval(two, t, r);
	}
	if (two == 2 || two == 3) {
		int t = eval(two, m, r);
		return eval(one, l, t);
	}
	
	int t = eval(one, l, m);
	return eval(two, t, r);
}

int eval(int op, int val1, int val2) {
	int res = 0;
	if (op == 3 && val2 == 0) return INT_MAX;
	switch (op) {
		case 0: res = val1 + val2; break;
		case 1: res = val1 - val2; break;
		case 2: res = val1 * val2; break;
		case 3: res = val1 / val2; break;
	}

	return res;
}

string operand(int t) {
	string res = "";
	switch(t) {
		case 0: res = "+"; break;
		case 1: res = "-"; break;
		case 2: res = "*"; break;
		case 3: res = "/"; break;
		default: break;
	}

	return res;
}

int main() {
	int n; cin >> n;

	for (int t = 0; t < n; t++) {
		int target; cin >> target;
		int i, j, k;
		bool found = false;

		int ians, jans, kans;

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				for (int k = 0; k < 4; k++) {
					int ans = result(i, j, k);
					if (ans == target) {
						ians = i;
						jans = j;
						kans = k;
						found = true;
						break;
					}
				}
				if (found) break;
			}
			if (found) break;
		}

		if (found) {
			cout << "4 " << operand(ians) << " 4 " << operand(jans) << " 4 " << operand(kans) << " 4 = " << target << endl;
		} else {
			cout << "no solution" << endl;
		}
	}
}
