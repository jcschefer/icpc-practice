#include <iostream>

using namespace std;

int main() {
	int a = 15;
	a /= 10;
	cout << a << endl;
	for (int i = 0; i < 5; i++) {
		int k[5] = {0,0,0,0,0};
		k[i] = 1;
		for (int j = 0; j < 5; j++) {
			cout << k[j] << endl;
		}
	}
}
