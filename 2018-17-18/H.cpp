#include <iostream>

using namespace std;

unsigned long long combo(int n, int k){
	if(k == 0 || k == n){
		return 1;
	}
	unsigned long long ret = 1;

	for(int i = 1; i <= k; i++){
		ret *= n+1-i;
		ret /= i;
	}

	return ret;
}

int main(){

	int P;
	cin >> P;

	for(int i = 0; i < P; i++){
		int x;
		cin >> x;

		int nSteps;
		cin >> nSteps;
		int ways[110];
		for(int i = 0; i < 110; i++){
			ways[i] = 0;
		}

		unsigned long long ans = 0;

		for(int tSteps = 0; tSteps <= nSteps/2; tSteps+=2){
			int oSteps = (nSteps-2*tSteps);
			if(oSteps > tSteps){
				continue;
			}
			//cout << oSteps << " " << tSteps << endl;
			int lO = oSteps/2, rO = oSteps/2;
			int lT = tSteps/2, rT = tSteps/2;
			ans += combo(rO+rT,rT)*combo(rO+rT,rT);
		}
		cout << i+1 << " " << ans << endl;
	}

}
