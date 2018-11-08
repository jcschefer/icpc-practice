#include <queue>
#include <vector>
#include <iostream>
#include <cmath>
#include <set>
#include<utility>
using namespace std;

double x[1010], y[1010];
bool seen[1010], seenedge[1010][1010];


typedef struct {
	int src;
	int dst;
	double weight;
} edge;

struct myc {
	bool operator() (const edge& l, const edge& r) {
		return r.weight < l.weight;
	}
};

struct hasher {
	const size_t operator() (const pair<int,int> & l) {
		return 1010*l.first + l.second;
	}
};

int main() {
	int n, e, p;
	//unordered_set<pair<int, int>, hasher> existing;
	set<pair<int, int> > existing;
	cin>>n>>e>>p;

	for (int i = 0; i < 1010;i++) {
		seen[i] = false;
		for (int j = 0; j < 1010;j++)
			seenedge[i][j]=seenedge[j][i]=false;
	}
	seen[1001]=true;

	for (int i=0;i<n;i++){
		cin >>x[i]>>y[i];
	}

	priority_queue<edge, vector<edge>, myc> pq;

	for (int i=0;i<p;i++) {
		int a,b;
		cin >> a >> b;
		//edge next;
		//next.src=a-1;
		//next.dst=b-1;
		//next.weight=0.0; //hypot(x[a]-x[b],y[a]-y[b]);
		//pq.push(next);

		existing.insert(make_pair(a-1,b-1));
		existing.insert(make_pair(b-1,a-1));
	}

	for (int i =0;i<e;i++) {
		edge ne;
		ne.src=1001;
		ne.dst=i;
		ne.weight=0.0;
		pq.push(ne);
	}

	int nadded=0;
	double tot=0.0;
	while (!pq.empty() && nadded < n) {
		edge cur = pq.top();
		pq.pop();
		//cout << "popping off " << cur.src << " " << cur.dst << endl;

		if (seenedge[cur.src][cur.dst]) continue;
		if (seen[cur.src] && seen[cur.dst]) continue;

		seenedge[cur.src][cur.dst]=true;
		seenedge[cur.dst][cur.src]=true;
		seen[cur.src] = true;
		seen[cur.dst] = true;
		nadded++;
		tot += cur.weight;

		int nsrc = seen[cur.src] ? cur.dst : cur.src;
		//cout << nsrc << endl;

		for (int i =0; i < n; i++) {
			if (!seen[i]) {
				if (!seenedge[nsrc][i]) {
					edge ne;
					ne.src = nsrc;
					ne.dst = i;
					bool inex = existing.find(make_pair(nsrc, i)) != existing.end();
					ne.weight =inex ? 0 : hypot(x[nsrc]-x[i],y[nsrc]-y[i]);
					pq.push(ne);
					//cout << "pushed new edge to "<<i << " with weight " <<ne.weight<< endl;
				}
			}
		}
	}

	cout << tot << endl;
}
