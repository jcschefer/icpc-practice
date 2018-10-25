#include <iostream>
#include <algorithm>


using namespace std;

int score(string macro, string given){
	int count = 0;
	for(int i = 0; i <= given.length()-macro.length(); i++){
		if(given.substr(i,macro.length())==macro){
			count++;
			i += macro.length()-1;
		}
	}
	return given.length()-(count*macro.length())+count+macro.length();
}

int main(){

	//cout << score("EEN","WNEENWEENEENE") << endl;

	string given;
	cin >> given;

	int best = given.length();

	for(int i = 0; i < given.length(); i++){
		for(int j = i+1; j < given.length(); j++){
			string test = given.substr(i,j-i+1);
			//cout << test << endl;
			if(best > score(test,given)){
			//	cout << "*****" << test << endl;
			}
			best = min(best,score(test,given));
		}
	}

	cout << best << endl;

	return 0;
}
