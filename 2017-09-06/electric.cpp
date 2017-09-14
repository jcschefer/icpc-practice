#include <iostream>
#include <unordered_map>
using namespace std;

const int PLANT = -1;

int main() {
	int N, M, P;
	cin >> N;
	cin >> M;
	cin >> P;

	unordered_map<int, pair<int,int>> priorities;

	int** squares = new int*[N-1];
	for (int i = 0; i < N - 1; i++) squares[i] = new int[M-1];

	for (int i = 0; i < P; i++) {
		int r, c;
		cin >> r;
		cin >> c;
		squares[r][c] = PLANT;
	}

	while (priorities.size() < M*N) {
		
	}
}
