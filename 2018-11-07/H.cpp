#include <iostream>
#include <unordered_set>
#include <queue>

using namespace std;

char rot(char c){
	if(c <= 'E'){
		return c+1;
	}
	return 'A';
}

string manip(int idx,string s){
	char arr[9];

	idx += 1;

	for(int i = 0; i < 8; i++){
		arr[i+1] = s[i];
	}
	char curr = arr[idx];
	if(curr == 'A'){
		if(idx != 1){
			arr[idx-1] = rot(arr[idx-1]);
		}
		if(idx != 8){
			arr[idx+1] = rot(arr[idx+1]);
		}
	}
	if(curr == 'B'){
		if(idx != 1 && idx != 8){
			arr[idx+1] = arr[idx-1];
		}
	}
	if(curr == 'C'){
		arr[9-idx] = rot(arr[9-idx]);
	}
	if(curr == 'D'){
		if(idx != 8 && idx != 1){
			if(8-idx > idx-1){
				for(int i = idx -1; i >= 1; i--){
					arr[i] = rot(arr[i]);
				}
			}
			else{
				for(int i = idx +1; i <= 8; i++){
					arr[i] = rot(arr[i]);
				}
			}
		}
	}
	if(curr == 'E'){
		if(idx != 1 && idx != 8){
			int diff = min(abs(8-idx),abs(1-idx));
			arr[idx-diff] = rot(arr[idx-diff]);
			arr[idx+diff] = rot(arr[idx+diff]);
		}
	}
	if(curr == 'F'){
		if(idx % 2 == 0){
			arr[idx/2] = rot(arr[idx/2]);
		}
		else{
			arr[(idx+9)/2] = rot(arr[(idx+9)/2]);
		}
	}

	string s2 = "";
	for(int i = 1; i <= 8; i++){
		s2 += arr[i];
	}
	return s2;
}

int main(){

	string start, target;

	cin >> start >> target;

	queue<pair<string,int> > Q;
	unordered_set<string> seen;
	//seen.insert(start);
	Q.push(make_pair(start,0));

	while(!Q.empty()){
		string curr = Q.front().first;
		int clicks = Q.front().second;
		Q.pop();
		if(seen.find(curr) != seen.end()){
			continue;
		}
		seen.insert(curr);
		if(curr == target){
			cout << clicks << endl;
			return 0;
		}
		for(int i = 0; i < 8; i++){
			string next = manip(i,curr);
		//	cout << next << endl;
			if(next == target){
				cout << clicks+1 << endl;
				return 0;
			}
			Q.push(make_pair(next,clicks+1));
		}
	}

	return 0;
}
