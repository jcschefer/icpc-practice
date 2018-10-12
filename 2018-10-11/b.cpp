#include<iostream>
using namespace std;

unsigned long sum(unsigned long m, int base) {
	unsigned long s = 0;
	while (m > 0) {
		s += m % base;
		m /= base;
	}

	return s;
}

int main() {
	int n, a, b;
	cin >> n >> a >> b;

	if (a == b) {
		cout << n + 1;
		return 0;
	}

	unsigned long m = n + 1;
	unsigned long asum = sum(m,a);
	unsigned long bsum = sum(m,b);
	while (asum != bsum) {
		unsigned long ashifts = 0;
		unsigned long tmpa = m;
		while ((tmpa +1) % a ==0) {
			tmpa /= a;
			ashifts +=(a-1);
		}

		asum += 1;
		asum -= ashifts;

		unsigned long bshifts = 0;
		unsigned long tmpb = m;
		while ((tmpb +1) % b ==0) {
			tmpb /= b;
			bshifts+= b-1;
		}

		bsum += 1;
		bsum -= bshifts;

		m++;
	}

	cout << m;
}
