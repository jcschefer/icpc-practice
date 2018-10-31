#include <iostream>
#include <set>
#include <cmath>

using namespace std;

int primes[1130];
int TRUE = 1;
int FALSE = 0;
int UNKNOWN = 3;

bool isprime(int x) {
	if (primes[x]==TRUE) return true;
	else if (primes[x]==FALSE) return false;

	for (int i = 2; i < (int)floor(sqrt(x)); i++) {
		if (x % i == 0) {
			primes[x]=FALSE;
			return false;
		}
	}
	primes[x]=TRUE;
	return true;
}

int memo[15][1130];
int helper(int n, int k) {
	if (memo[k][n] != -1) return memo[k][n];
	//cout <<"calling helper on " << n <<" "<<k << endl;
	
	memo[k][n] = 0;
	int next = n;
	while (next > 1) {
		while (!isprime(next)) next--;
		memo[k][n] += 1*helper(n-next, k-1);
		///cout << helper(n-next, k-1)<<endl;
		next--;
	}
	return memo[k][n];
}

int main() {
	for (int i = 0; i < 1120;i++) {
		primes[i]=UNKNOWN;
	}
	primes[0] = primes[1] = FALSE;
	primes[2] = TRUE;

	for (int i = 0; i < 1120;i++) {
		memo[0][i]=0;
	}
	for (int i = 0; i < 1120;i++) {
		memo[1][i]=isprime(i)? 1:0;
	}
	for (int k = 2; k < 15;k++) for (int i = 0; i < 1120;i++) {
		memo[k][i]=-1;
	}
	cout<<isprime(19)<<endl;

	primes[1]=FALSE;
	primes[2]=TRUE;

	int n, k;
	cin >> n >>k;
	while (n || k) {

		cout << helper(n,k)<<endl;

		cin >> n >> k;
	}
}
