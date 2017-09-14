#include <iostream>
#include <string>
using namespace std;

int main() {
	int P, N;
	cin >> P;
	for(int i = 0; i < P;i++){
	
		cin >> N;

		int* digits = new int[8];
		for (int j = 0; j < 8;j++)digits[j]=0;
		string s;
		cin >> s;

		for (int j  = 0 ; j < 38; j++) {
			string small = s.substr(j, 3);
			if (small =="TTT"){
					digits[0] +=1;
			}
			else if(small == "TTH"){
					digits[1] +=1;
			} else if (small == "THT")
			{
					digits[2] +=1;
			} else if (small =="THH"){
					digits[3] +=1;
			} else if (small ==  "HTT") {
					digits[4] +=1;
			} else if (small == "HTH") {
					digits[5] +=1;
			}else if (small ==  "HHT"){
					digits[6] +=1;
			}
			else if (small == "HHH"){
					digits[7] +=1;
			}
		}

		cout << N<<" ";
		for (int i = 0; i < 8; i++) {
			cout << digits[i];
			if (i != 7) cout << " ";
		}
		cout << endl;
	}

}
