#include <iostream>
using namespace std;

#include <vector>
#include<string>

int main () {
	int rotationSum=0;
	vector<char> initial;
	vector<char> vecone;
	vector<char> vectwo;

	string s;
	cin >> s;
	for (int i = 0; i < s.size()/2; i++) {
		vecone.push_back(s.at(i));
	}

	for (int i = s.size() / 2; i < s.size(); i++) {
		vectwo.push_back(s.at(i));
	}

	for (int i = 0; i < vecone.size(); i++) {
		int offset = vecone.at(i) - 'A';
		rotationSum += offset;
	}

	rotationSum = rotationSum % 26;

	for (int i = 0; i < vectwo.size(); i++) {
		char now = vecone.at(i);
		vecone[i] = ((now - 'A'+rotationSum) % 26) + 'A';
	}
	string out ="";
	for (int i = 0;i < vecone.size();i++) {
		out += vecone[i];
	}

	//cout << out;
	//cout << out<<endl;

	//////
	rotationSum=0;

	for (int i = 0; i < vectwo.size(); i++) {
		int offset = vectwo.at(i) - 'A';
		rotationSum += offset;
	}

	rotationSum = rotationSum % 26;

	for (int i = 0; i < vectwo.size(); i++) {
		char now = vectwo.at(i);
		vectwo[i] = ((now - 'A'+rotationSum) % 26) + 'A';
	}

	 out ="";
	for (int i = 0;i < vectwo.size();i++) {
		out += vectwo[i];
	}
	//cout << out<<endl;

	/////////
	for (int i = 0; i < vecone.size(); i++) {
		char now = vecone.at(i);
		vecone[i] = ((now - 'A'+vectwo.at(i)-'A') % 26) + 'A';
	}

	///
	out ="";
	int i=0;
	for (;i < vecone.size();i++) {
		out += vecone[i];
	}

	cout << out;

}
