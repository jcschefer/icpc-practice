#include <iostream>
#include <sstream>
#include <queue>

using namespace std;

int getIdx(int curN, int curD, int targetN, int targetD, int num){
	if(curN == targetN && curD == targetD){
		return num;
	}
	if(targetN-curN < curD){
		return 0;
	}
	if(targetD-curD < curN){
		return 0;
	}
	int ans = 0;
	if(curD+curN <= targetD){
		ans += getIdx(curN,curD+curN,targetN,targetD,num*2);
	}
	if(curD+curN <= targetN){
		ans += getIdx(curN+curD,curD,targetN,targetD,1+num*2);
	}
	return ans;
}

typedef struct {
	int curN;
	int curD;
	int num;
} node;

int getIdxBFS(node curr, int targetN, int targetD){
	if(curr.curN == targetN && curr.curD == targetD){
		return curr.num;
	}
	if(targetN-curr.curN < curr.curD){
		return 0;
	}
	if(targetD-curr.curD < curr.curN){
		return 0;
	}
	int ans = 0;
	if(curr.curD+curr.curN <= targetD){
		node next;
		next.curN = curr.curN;
		next.curD = curr.curD+curr.curN;
		next.num = curr.num * 2;

		ans += getIdx(curN,curD+curN,targetN,targetD,num*2);
	}
	if(curD+curN <= targetN){
		ans += getIdx(curN+curD,curD,targetN,targetD,1+num*2);
	}
	return ans;
}

int main(){

	int P;
	string s;
	stringstream first;
	getline(cin,s);
	first << s;
	first >> P;
	for(int t = 1; t <= P; t++){
		stringstream s;
		string line;
		getline(cin,line);
		s << line;
		int x;
		s >> x;
		int n;
		s >> n;
		char c;
		s >> c;
		int d;
		s >> d;
		//cout << t << " " << getIdx(1,1,n,d,1) << endl;
		node nd;
		nd.curD = 1;
		nd.curN = 1;
		nd.num = 1;
		cout << t << " " << getIdxBFS(nd, n,d) << endl;
	}

	return 0;
}
