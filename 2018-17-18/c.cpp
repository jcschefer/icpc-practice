#include <unordered_set>
#include<iostream>
using namespace std;


long calc(unordered_set<int> avoids, int targetsum, int sofar) {
	if (sofar == targetsum) return 1;
	int s = 0L;
	for (int k = 1; k < targetsum; k++) {
		if (avoids.find(k) == avoids.end()) {
			//cout <<"adding"<<endl;
			s += calc(avoids, targetsum - k, sofar+1);
		}
	}
	return sofar +s;
}

int main() {
	int p;
	cin >> p;
	for (int k = 0; k < p; k++) {
		int trial;
		int n,m,ks;
		cin >> trial>>n>>m>>ks;
		unordered_set<int> avoids;

		while (m <= n) {
			avoids.insert(m);
			m += ks;
		}


		cout << trial << " " << calc(avoids, n,0) << endl;

	}
}
