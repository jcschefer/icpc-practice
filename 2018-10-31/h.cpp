#include <iostream>
using namespace std;

int lowest(char* zoo, int n) {
	for (int i = n-1;i>=0;i--) {
		if(zoo[i]=='O') return i;
	}
	return -1;
}

int main() {
	int n;
	cin >>n;
	char zoo[65];
	int res = 0;

	for (int i =0;i<n;i++) cin >>zoo[i];

	while (1) {
		int l = lowest(zoo, n);
		//cout << l << endl;
		if (l == -1) break;

		for (int i = l; i < n; i++) zoo[i] = 'O';
		zoo[l] = 'Z';
		res++;
	}

	cout << res << endl;
}
