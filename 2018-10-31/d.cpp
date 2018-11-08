#include <iostream>
#include <algorithm>
#include <string>
#include <utility>

using namespace std;

const double PI = 3.1415926535;

int computeNum(char c){
	if(c >= 'A' && c <= 'Z'){
		return c - 'A';
	}
	if(c == ' '){
		return 26;
	}
	return 27;
}


int getDif(char c1, char c2){
	int i1 = computeNum(c1);
	int i2 = computeNum(c2);
	if(i1 > i2){
		return min(i1-i2,28+i2-i1);
	}
	return min(i2-i1,28+i1-i2);
}

int main(){

	cout.precision(10);

	int N;
	string s;
	getline(cin,s);
	N = atoi(s.c_str());
	for(int T = 0; T < N; T++){
		string input;
		getline(cin,input);
		double sum = 0.0;
		for(int i = 1; i < input.length(); i++){
			sum += 1.0;
			sum += getDif(input[i],input[i-1])*PI/7.0000000000000;
		}
		sum += 1.0;
		cout << fixed << sum << endl;
	}


}
