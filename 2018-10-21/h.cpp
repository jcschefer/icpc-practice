#include <queue>
#include <vector>
#include <iostream>
#include <utility>
using namespace std;

int h[110];
int b[110];
typedef struct {
	int packs;

	int nh;
	int nb;

	int hused;
	int bused;
};

struct Compare {
	bool operator() (const Node& lhs, const Node& rhs) {
		return lhs.packs > rhs.packs;
	}
};

int main() {
	int h, b;
	cin >>h;
	for (int i = 0; h; i++) {
		cin >> h[i];
	}

	cin >> b;
	for (int i=0;i<b;i++) {
		cin >> b[i];
	}

	priority_queue<Node, vector<node>, Compare> pq;

	Node start;
	start.packs = 0;
	start.nh = 0;
	start.nb = 0;
	start.hused = 0;
	start.bused = 0;

	while (!pq.empty()) {
		Node curr = pq.top();
		//cout << "just popped "<< curr.currLoc <<" "<<curr.pickedUpSoFar << endl;
		pq.pop();

		if (curr.nh == curr.nb) {
			cout << curr.packs << endl;
			return 0;
		}

		//vector<ii> nbrs = adj[curr.currLoc];
		for (int i = 0; i < h; i++) {
			if ()
		}
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
