#include <iostream>
using namespace std;

int main() {
	int p;
	cin >> p;
	int n;
	for (int j = 0; j < p; j++) {
int s;
cin >>s;
		cin >> n;
		int sum = n*(n+1)/2;
		int sumodd= 0;
		for (int i = 0; i < n; i++) sumodd += 1+2*i;
		int sumeven = 2*sum;

		cout << j+1 << " " << sum << " "<< sumodd << " " << sumeven <<endl;
	}
}
