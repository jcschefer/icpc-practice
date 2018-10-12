#include <iostream>
#include <algorithm>

using namespace std;

int main(){

int best = 1;
		int longest[100];

		for(int i = 0; i < 100; i++){
			longest[i] = 1;
		}

			string s;
			cin >> s;

	for(int i = 1; i < s.length(); i++){
		for(int j = 0; j < i; j++){
			if(s[i] > s[j]){
				longest[i] = max(longest[i],longest[j]+1);
			}
		}
		best = max(longest[i],best);
	}

	if(best >= 26){
		cout << 0;
		return 0;
	}

	cout << 26-best;

	return 0;
}
