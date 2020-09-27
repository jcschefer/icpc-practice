#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef struct {
	int sofar;
	int n;
	int kred;
	int kblue;
} snode;

struct myc {
	bool operator()(const snode& lhs, const snode& rhs) {
		return lhs.sofar > rhs.sofar;
	}
};

int WHITE = 0, RED = 1, BLUE = 2;

pair<int, int> nbrs[455][455];
bool seen[455][805][805];

#define D 0
#define DEBUG if(D)

int main() {
	int n, m, k1, k2;
	cin >> n >> m  >> k1 >> k2;

	int u, v, x, c;
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> x >> c;
		nbrs[u][v] = make_pair(x, c);
		nbrs[v][u] = make_pair(x, c);
	}

	int s, t;
	cin >> s >> t;
	
	priority_queue<snode, vector<snode>, myc> pq;

	snode start;
	start.sofar = 0;
	start.n = s;
	start.kred = 0;
	start.kblue = 0;

	pq.push(start);

	while (!pq.empty()) {
		snode cur = pq.top();pq.pop();

		DEBUG cout << "visiting node " << cur.n << endl;
		if (seen[cur.n][cur.kred][cur.kblue]) {
			continue;
		}
		
		seen[cur.n][cur.kred][cur.kblue] = true;

		if (cur.kred > k1 || cur.kblue > k2) {
			continue;
		}

		if (cur.n == t && cur.kred == k1 && cur.kblue == k2) {
			cout << cur.sofar << endl;;
			return 0;
		}
		
		for (int i = 1; i <= n; i++) {
			if (i == cur.n) continue;
			pair<int, int> temp = nbrs[cur.n][i];
			if (temp.first > 0) {
				snode nxt;
				nxt.sofar = cur.sofar + temp.first;
				nxt.n = i;
				nxt.kred = cur.kred + (temp.second == RED ? 1 : 0);
				nxt.kblue = cur.kblue + (temp.second == BLUE ? 1 : 0);
				pq.push(nxt);
			}
		}
	}

	cout << "-1" << endl;
}
