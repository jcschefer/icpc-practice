#include <queue>
#include<unordered_map>
#include<string>
#include<iostream>
#include<vector>
#include<utility>
using namespace std;

unordered_map<string, int> langs;
int seen[110];
vector<pair<int,int>> adj[110];

typedef struct {
	int curr;
	int dist;
	int cost;
	int edgecost;
} node;

struct myc {
	bool operator() (const node& lhs, const node& rhs) {
		if (lhs.dist != rhs.dist) return lhs.dist > rhs.dist;
		return lhs.edgecost > rhs.edgecost;
	}
};

int main() {
	int n, m;
	cin >>n >>m;

	langs["English"] = 0;
	
	// read languages
	for (int i = 1; i <= n;i++) {
		string s;
		cin >> s;

		// if English is a target language, just ignore and remove from targets
		if (s == "English") {
			i--;
			n--;
			continue;
		}

		langs[s] = i;
	}

	// build adjacency lists
	for (int i = 0; i < m; i++) {
		string l1, l2;
		int cost;
		cin >> l1>>l2>>cost;

		int pos1 = (*(langs.find(l1))).second, pos2 = (*(langs.find(l2))).second;
		adj[pos1].push_back(make_pair(pos2, cost));
		adj[pos2].push_back(make_pair(pos1, cost));
	}

	// initialize shortest paths to -1
	for (int i = 0 ; i <=n;i++) seen[i] = -1;

	priority_queue<node, vector<node>, myc> pq;
	//queue<node> pq;
	node begin;
	begin.curr		= 0;
	begin.dist 		= 0;
	begin.cost 		= 0;
	begin.edgecost	= 0;
	pq.push(begin);

	int totalcost=0;

	// begin graph search
	while (!pq.empty()) {
		node cur = pq.top();
		//node cur = pq.front();
		pq.pop();
		
		if (seen[cur.curr] <= 0 || cur.dist < seen[cur.curr]) {
			seen[cur.curr] = cur.dist;
			totalcost += cur.edgecost;
			//cout << "visiting " << cur.curr << endl;

			for (pair<int,int> outgoing:adj[cur.curr]) {
				node next;
				next.curr = outgoing.first;
				next.dist = cur.dist + 1;
				next.cost = cur.cost + outgoing.second;
				next.edgecost = seen[outgoing.first] == -1 ? outgoing.second : 0;

				pq.push(next);
			}
		}
	}

	// make sure we've reached everywhere
	for (int k = 0; k < n+1;k++) {
		if (seen[k] ==  -1) {
			cout << "Impossible" << endl;
			return 0;
		}
	}

	cout << totalcost <<endl;
}
