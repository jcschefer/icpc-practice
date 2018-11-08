#include <iostream>

using namespace std;

long pow[63];

int main(){

	pow[0] = 1;
	for(int i = 1; i < 63; i++){
		pow[i] = 2*pow[i-1];
	}

	int N;
	cin >> N;
	long ans = 0;
	for(int i = N-1; i >= 0; i--){
		char c;
		cin >> c;
		if(c == 'O'){
			ans += pow[i];
		}
	}
	cout << ans << endl;

	return 0;
}
