#include <iostream>

using namespace std;

int N, M;
int arr[110][110];

bool marked[110][110];

bool isSet(int x, int y){
	if(x < 0 || x >= N){
		return false;
	}
	if(y < 0 || y >= M){
		return false;
	}
	return arr[x][y];
}

bool isValidLoop(int x, int y){

	if(!isSet(x,y)){
		return false;
	}
	if(marked[x][y]){
		return true;
	}
	marked[x][y] = true;

	int count = 0;

	if(isSet(x,y+1)){
		count++;
	}
	if(isSet(x,y-1)){
		count++;
	}
	if(isSet(x+1,y)){
		count++;
	}
	if(isSet(x-1,y)){
		count++;
	}
	if(isSet(x+1,y+1)){
		count++;
	}
	if(isSet(x-1,y-1)){
		count++;
	}
	if(isSet(x+1,y-1)){
		count++;
	}
	if(isSet(x-1,y+1)){
		count++;
	}
	if(count != 2){
		return false;
	}
	bool ret = true;

		if(isSet(x,y+1)){
			ret &= isValidLoop(x,y+1);
		}
		if(isSet(x,y-1)){
			ret &= isValidLoop(x,y-1);
		}
		if(isSet(x+1,y)){
			ret &= isValidLoop(x+1,y);
		}
		if(isSet(x-1,y)){
			ret &= isValidLoop(x-1,y);
		}
		if(isSet(x+1,y+1)){
			ret &= isValidLoop(x+1,y+1);
		}
		if(isSet(x-1,y-1)){
			ret &= isValidLoop(x-1,y-1);
		}
		if(isSet(x+1,y-1)){
			ret &= isValidLoop(x+1,y-1);
		}
		if(isSet(x-1,y+1)){
			ret &= isValidLoop(x-1,y+1);
		}
		return ret;
}

int main(){

	for(int i = 0; i < 110; i++){
		for(int j = 0; j < 110; j++){
			marked[i][j] = false;
		}
	}

	cin >> N >> M;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			char c;
			cin >> c;
			arr[i][j] = (c == '#') ? true : false;
		}
	}

	int numSeen = 0;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(!marked[i][j] && isValidLoop(i,j)){
				numSeen++;
			}
		}
	}

	cout << numSeen << endl;

	return 0;
}
