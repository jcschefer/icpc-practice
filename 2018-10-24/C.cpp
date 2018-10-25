#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

int cost[110];
int depth[110];

struct mc {
	bool operator() (int a, int b) {
		if (depth[a] != depth[b]) return a > b;
		return cost[a] > cost[b];
	}
};

int main(){

	unordered_map<string,int> map;

	int N, M;
	cin >> N >> M;


	for(int i = 0; i < 110; i++){
		cost[i] = INT_MAX;
	}
	cost[0] = 0;
	depth[0] = 0;

	for(int i = 0; i < N; i++){
		string s;
		cin >> s;
		map.insert(make_pair(s,i+1));
	}

	list<pair<int,int> > graph[110];
	for(int i = 0; i < M; i++){
		string s1, s2;
		int c;
		cin >> s1 >> s2 >> c;
		int i1 = (map.find(s1)==map.end())?0:map.find(s1)->second;
		int i2 = (map.find(s2)==map.end())?0:map.find(s2)->second;
		graph[i1].push_front(make_pair(i2,c));
		graph[i2].push_front(make_pair(i1,c));
	}

	priority_queue<int, vector<int>, mc> Q;
	Q.push(0);

	int D = 0;

	while(!Q.empty()){
		int curr = Q.top();
		Q.pop();
		if(depth[curr]!=D){
			D++;
		}
		for(pair<int,int> p : graph[curr]){
			if(cost[p.first] < INT_MAX){
				if(depth[p.first]<=D){
					cost[p.first]=min(cost[p.first],p.second);
				}
				continue;
			}
			cost[p.first] = p.second;
			depth[p.first] = D+1;
			Q.push(p.first);
		}
	}

	int ans = 0;
	for(int i = 1; i <= N; i++){
		if(cost[i]==INT_MAX){
			cout << "Impossible" << endl;
			return 0;
		}
		ans += cost[i];
	}
	cout << ans << endl;

	return 0;
}
