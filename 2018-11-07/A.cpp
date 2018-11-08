#include <iostream>

using namespace std;

int main(){

	int max = 0;

	int count[256];
	for(int i = 0; i < 255; i++){
		count[i] = 0;
	}
	for(int i = 0; i < 5; i++){
		string s;
		cin >> s;
		count[s[0]]++;
		if(count[s[0]]>max){
			max = count[s[0]];
		}
	}

	cout << max << endl;

	return 0;
}
