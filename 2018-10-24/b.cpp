#include<vector>
#include<string>
#include<queue>
#include<iostream>
using namespace std;

typedef struct {
	string name;
	int length;
	char team;
} dynasty;

void swap(int& a, int& b) {
	int t = a;
	a = b;
	b = t;
}

dynasty empty;

int main() {
	vector<dynasty> all;
	dynasty base;
	base.length = -1;
	all.push_back(base);

	queue<string> players;

	int n;
	cin >> n;

	string w[2];
	string b[2];
	cin >> w[0] >> b[0]>>w[1]>>b[1];

	for (int i =4;i<n;i++) {
		string s;
		cin >> s;
		players.push(s);
	}

	int wolder=0,bolder=0;

	string scores;
	cin >> scores;

	dynasty currd;
	currd.name = "";
	currd.length = -1;
	currd.team = 'n';

	for (int i = 0; i < scores.size(); i++) {
		char tem = scores[i];

		string* win = tem=='W' ? w : b;
		string* los = tem=='W' ? b : w;

		if (currd.team != tem) {
			if (currd.length > all[0].length) {
				all.clear();
				//cout <<"pushing"<<endl;
				all.push_back(currd);
			} else if (currd.length == all[0].length) {
				all.push_back(currd);
			}

				currd.length = 0;
				int winolder = tem=='W'?wolder:bolder;
				currd.name = win[winolder] + " " +win[1-winolder];
				currd.length=0;
				currd.team = tem;

		} else {

		}

		currd.length += 1;
		players.push(los[1]);
		los[1] = players.front();
		players.pop();
		swap(los[0],los[1]);
		swap(win[0], win[1]);

		if (tem=='W') {
			wolder = 1-wolder;
			bolder = 1;
		} else {
			bolder = 1-bolder;
			wolder = 1;
		}
	}

//	if (all[0].length == -1) {
//		all.clear();
//		all.push_back(currd);
//	}

	if (currd.length > all[0].length) {
		all.clear();
		//cout <<"pushing"<<endl;
		all.push_back(currd);
	} else if (currd.length == all[0].length) {
		all.push_back(currd);
	}

	for (int i = 0; i < all.size(); i++) {
		cout << all[i].name << endl;
	}
}
