#include <queue>
#include <vector>
#include <iostream>
#include <utility>
using namespace std;

int t[110];
bool seen[110];
typedef pair<int, int> ii;
typedef struct {
	int pickedUpSoFar;
	int traveledSoFar;
	int currLoc;
} Node;
vector<ii> adj[110];

struct Compare{
	bool operator() (const Node& lhs, const Node& rhs) {
		if (lhs.traveledSoFar < rhs.traveledSoFar) return false;
		if (lhs.traveledSoFar == rhs.traveledSoFar) return lhs.pickedUpSoFar < rhs.pickedUpSoFar;
		return true;
	}
};


int main() {
	int n;
	int m;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> t[i];
		//cout << "i: "<<i<<"t: "<<t[i]<<endl;
		seen[i] = false;
	}

	
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a,b,d;
		cin >> a >> b >> d;
		adj[a].push_back( make_pair(b, d));
		adj[b].push_back(make_pair(a, d));
	}

	priority_queue<Node, vector<Node>, Compare> pq;

	Node start;
	start.currLoc = 1;
	start.pickedUpSoFar = t[1];
	start.traveledSoFar = 0;
	pq.push(start);
	while (!pq.empty()) {
		Node curr = pq.top();
		//cout << "just popped "<< curr.currLoc <<" "<<curr.pickedUpSoFar << endl;
		seen[curr.currLoc] = true;
		pq.pop();

		if (curr.currLoc == n) {
			cout << curr.traveledSoFar << " " << curr.pickedUpSoFar << endl;
			return 0;
		}

		vector<ii> nbrs = adj[curr.currLoc];
		for (int j = 0; j < nbrs.size(); j++) {
			int nloc = nbrs.at(j).first, nweight = nbrs.at(j).second;
			if (!seen[nloc]) {
				//cout << "adding " << nloc << " with weight " << nweight<< endl;
				Node next;
				next.pickedUpSoFar = curr.pickedUpSoFar + t[nloc];
				next.traveledSoFar = curr.traveledSoFar + nweight;
				next.currLoc = nloc;
				pq.push(next);
			}
		}
	}

	cout << "impossible" << endl;
	return 0;

}
