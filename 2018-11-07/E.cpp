#include <iostream>

using namespace std;

int main(){

	int C;
	cin >> C;
	string s1, s2;
	cin >> s1 >> s2;

	int M = 0;

	int S = 0, D = 0;
	for(int i = 0; i < s1.length(); i++){
		if(s1[i]==s2[i]){
			S++;
		}
		else{
			D++;
		}
	}
//	cout << S << " " << D << endl;
	if(C > S){
		M = S+D-(C-S);
	}
	else{
		M = C+D;
	}
	cout << M << endl;

	return 0;
}
