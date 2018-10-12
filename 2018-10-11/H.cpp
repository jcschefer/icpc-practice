#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<long,long> > painters;

vector<long> endV;

bool cmp(pair<long,long> p1, pair<long,long> p2){
	if(p1.second == p2.second){
		return p1.first < p2.first;
	}
	return p1.second < p2.second;
}
//returns the index of the right most element of ends such that ends[i] < target
//returns -1 if not possible
int binarySearch(int left, int right, long target){
	//cout << "b search " << left << " " << right << endl;
	if(left > right){
		return -1;
	}
	if(right-left<=1){
		if(endV[left] >= target){
			return -1;
		}
		if(endV[right] < target){
			return right;
		}
		return left;
	}
	int med = (left+right)/2;
	if(endV[med] == target){
		return med-1;
	}
	if(endV[med] < target){
		return binarySearch(med,right,target);
	}
	else{
		return binarySearch(left,med,target);
	}
}
long best[200010];

int main(){

	long N, K;
	cin >> N >> K;

	for(long i = 0; i < K; i++){
		long f, s;
		cin >> f >> s;
		painters.push_back(make_pair(f,s));
		best[i] = 0;
	}

	long M = 0;
	sort(painters.begin(),painters.end(),cmp);
	for(pair<long,long> p: painters){
		endV.push_back(p.second);
	}


	best[0] = painters[0].second-painters[0].first+1;

	for(long i = 1; i < K; i++){
		int idx = binarySearch(0,i-1,painters[i].first);
		//cout << i << ": " << idx << endl;
		if(idx == -1){
			best[i] = max(best[i-1],1+painters[i].second-painters[i].first);
		}
		else{
			best[i] = max(best[i-1],best[idx]+1+painters[i].second-painters[i].first);
		}
		M = max(M,best[i]);
	}

	cout << N-M;

	return 0;
}
