#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main() {
	int studno,numcom;
	cin >> studno;
	cin >> numcom;

	vector<int> commands;
	for (int i = 0 ; i < numcom; i++){
		string s;
		cin >> s;
		if (s=="undo") {
			int num;
			cin >> num;
			for (int j = 0; j < num;j++) {
				commands.pop_back();
			}
			continue;
		}

		int command = stoi(s);
		commands.push_back(command);
	}

	int result = 0;
	for (int i = 0; i < commands.size();i++) {
		result += commands.at(i);
	}

	while (result < 0) result += studno;

	result = result % studno;

	cout << result;
}
