#include <iostream>
#include<cmath>
using namespace std;


double choose(int n, int k) {
	double prob = 1.0;
	for (int j = 1; j <= k; j++) {
		prob *= 1.0 * (n + 1 - j) / j;
	}

	return prob;
}

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int n, w, v1, v2;
		cin >> n;
		cin >> v1;
		cin >> v2;
		cin >> w;

		double predict = v1 + 0.5*(n-v1-v2);
		double threshold = n*w/100 + 1;
		//cout << predict << " "<<threshold<<endl;
		if (n - v2 < n/2 + 1) {
			cout << "RECOUNT!" << endl;
		} else { 
			int remaining = n - v1 - v2;
			int needed = n/2 + 1 - v1;
			
			double prob = 0.0;
			for (int k = needed; k <= remaining; k++) {
				prob += choose(remaining, k)*pow(0.5,remaining);
			}

			if (prob >  1.0 * w /100){
				cout << "GET A CRATE OF CHAMPAGNE FROM THE BASEMENT!" << endl;
			} else {
				cout << "PATIENCE, EVERYONE!" << endl;
			}
		}
	}

	return 0;
}
