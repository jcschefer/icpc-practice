#include <queue>
#include <vector>
#include <utility>
#include <unordered_set>
#include<iostream>
using namespace std;

typedef struct {
	int src;
	int dest;
	int weight;
} edge;

 struct myc {
	bool operator() (const edge& l, const edge& r) {
		return l.weight > r.weight;
	}
};

int main() {
	int n;
	cin >> n;

	int** adjmat = new int*[n];
	for (int i =0;i<n;i++)adjmat[i]=new int[n];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> adjmat[i][j];
		}
	}

	vector<int> ans;
	//unordered_set<bool> seen;
	priority_queue<edge, vector<edge>, myc> pq;

	for (int i =1;i<n;i++) {
		edge next;
		next.src = 0;
		next.dest = i;
		next.weight = adjmat[0][i];
		pq.push(next);
	}
	//seen.insert(0);
bool seen[2520];
for (int i =0;i<2520;i++)seen[i]=false;
seen[0]=true;
bool seenedge[2520][2520] ;
for (int i = 0; i < n;i++) {for (int j = 0; j < n;j++) {
	seenedge[i][j] = false;
}}
	int numedges = 0;
	while (!pq.empty() && numedges< n) {
		edge cur = pq.top();
		pq.pop();
		if (seenedge[cur.src][cur.dest]) continue;
		//cout << cur.src << " " << cur.dest<< " " << seenedge[cur.src][cur.dest] << endl;
		//pq.pop();
		seenedge[cur.src][cur.dest] = true;
		seenedge[cur.dest][cur.src] = true;

		// if (!seen[cur.src]) {
		// 	// already seen cur.src			//seen[cur.dest]=true;
		// 	for (int i = 0; i < n; i++) {
		// 		if (!seen[i] && !seenedge[cur.src][i]) {
		// 			edge next;
		// 			next.src = cur.src;
		// 			next.dest = i;
		// 			next.weight = adjmat[cur.src][i];
		// 			pq.push(next);
		// 		} //else { cout << "already seen "<< i << endl;}
		// 	}
		// } else {
		// 	//seen[cur.src] = true;
		// 	for (int i = 0; i < n; i++) {
		// 		if (!seen[i] && !seenedge[i][cur.dest]) {
		// 			edge next;
		// 			next.src = cur.dest;
		// 			next.dest = i;
		// 			next.weight = adjmat[cur.dest][i];
		// 			pq.push(next);
		// 		} //else { cout << "already seen "<< i << endl;}
		// 	}
		// }

		int newsrc = seen[cur.src] ? cur.dest : cur.src;
		if (seen[newsrc]) continue;

		for (int i =0;i<n;i++) {
			if (!seen[i] && !seenedge[newsrc][i]) {
				edge next;
				next.src = newsrc;
				next.dest = i;
				next.weight = adjmat[newsrc][i];
				pq.push(next);
			}
		}

		numedges++;
		seen[cur.src] = true;
		seen[cur.dest] = true;

		ans.push_back(cur.src); ans.push_back(cur.dest);
	}
	//cout << "found " << numedges<<endl;
	for (int i = 0; i < numedges; i++) {
		cout << ans[2*i]+1 << " " << ans[2*i+1]+1 << endl;
	}

}
