#include <iostream>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int main() {
	while (1) {
		int N, A_i, L_i, Q, S, T;
		unordered_map<int, unordered_set<pair<int, int>>> graph;
		cin >> N;
		for (int i = 0; i < N; i++) {
			graph[i] = new unordered_set;
		}
		for (int i = 1; i < N; i++) {
			cin >> A_i;
			cin >> L_i;
			pair<int,int> edge = make_pair(A_i, L_i);
			graph[i].insert(edge);
			graph[A_i].insert(make_pair(i, L_i));
		}
		for (int i = 1; i < N; i++) {
			for (auto itr = graph[i].begin(); itr != graph[i].end(); ++itr) {
				cout << "saddd"<< endl; 
			}
		}
	}
}
