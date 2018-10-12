#include <iostream>

using namespace std;

int R, C;

bool isValid(int r, int c){
	return (0 <= r && r < R) && (0 <= c && c < C);
}

char grid[100][100];
bool marked[100][100];

void fill(int r, int c){
	//cout << R << ": " << r << " " << C << ": " << c << endl;
	if(!isValid(r,c)){
		return;
	}
	if(marked[r][c]){
		return;
	}
	if(grid[r][c] == 'W'){
		return;
	}
	marked[r][c] = true;
	fill(r+1,c);
	fill(r-1,c);
	fill(r,c+1);
	fill(r,c-1);
}

int main(){

	for(int i = 0; i < 100; i++){
		for(int j = 0; j < 100; j++){
			grid[i][j] = false;
			marked[i][j] = false;
		}
	}

	cin >> R >> C;
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			char c;
			cin >> grid[i][j];
		}
	}

	int count = 0;
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			if(!marked[i][j] && grid[i][j] == 'L'){
				fill(i,j);
				count++;
			}
		}
	}

	cout << count;

	return 0;
}
