#include <iostream>

using namespace std;

int main(){

	int ansTable[10010];
	for(int i = 0; i < 10010; i++){
		ansTable[i] = 0;
	}
	ansTable[1] = 2;

	for(int i = 2; i <= 10000; i++){
		ansTable[i] = ansTable[i-1];
		for(int j = 1; j < i; j++){
			if(i%j != 0 || i ==1){
				ansTable[i]++;
			}
		}
	}

	int P;
	cin >> P;
	for(int i = 1; i <= P; i++){
		int t;
		cin >> t;
		int order;
		cin >> order;

		//cout << order << endl;

		cout << t << " " << ansTable[order] << endl;
	}

	return 0;
}
