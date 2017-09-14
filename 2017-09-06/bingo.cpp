#include <iostream>
using namespace std;

int main() {
	int N, B;
	while (1) {
		cin >> N;
		cin >> B;

		if ( N == 0 && B == 0) break;

		int* balls = new int[N+1];
		for (int i = 0; i < B; i++) {
			cin >> balls[i];
		}

		bool* canMake = new bool[N];
		for (int i = 0; i <= N; i++) {
			canMake[i] = false;
		}

		for (int i = 0; i <= B; i++) {
			for (int j = 0; j <= B; j++) {
				if (balls[i] >= balls[j]) canMake[balls[i] - balls[j]] = true;
			}
		}

		bool all = true;
		for (int i = 0; i<= N; i++) {
			if (!canMake[i]) all = false;
		}

		if (all) cout << "Y"<< endl;
		else cout << "N"<<endl;
	}
}
