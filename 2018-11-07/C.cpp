#include <iostream>

using namespace std;

int main() {
	int l;
	int h;
	cin >> l;
	cin >> h;

	int combinations = 0;
	for (int i = l; i < h + 1; i++) {
		bool zoo[10] = {0,0,0,0,0,0,0,0,0,0};

		int z = i;
		int a = z % 10;
		zoo[a] = 1;
		z /= 10;
		int b = z % 10;
		zoo[b] = 1;
		z/= 10;
		int c = z % 10;
		zoo[c] = 1;
		z/=10;
		int d = z%10;
		zoo[d] = 1;
		z/=10;
		int e = z%10;
		zoo[e] = 1;
		z/=10;
		int f = z;
		zoo[f] = 1;

		int hitcount = 0;
		for (int goo = 0; goo < 10; goo++) {
			if (zoo[goo]) hitcount++;
		}
		if (a == 0 || b==0||c==0||d==0||e==0||f==0) continue;

		if (i%a==0 && i%b==0 && i%c==0 && i%d==0 && i%e==0 && i%f==0 && hitcount == 6) combinations++;
	}

	cout << combinations << endl;
}
