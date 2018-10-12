#include <iostream>
#include <algorithm>

using namespace std;

int arr[1000010];
int high[1000010];
int low[1000010];

int minSeen = 0;
int maxSeen = 999999999;

int main(){
#include <iostream>
#include <algorithm>

using namespace std;

int arr[1000010];
int high[1000010];
int low[1000010];

int minSeen = 0;
int maxSeen = 999999999;

int main(){

	int N;
	cin >> N;

	for(int i = 0; i < N; i++){
		cin >> arr[i];
		high[i] = 1;
		low[i] = 1;
	}

	for(int i = 1; i < N; i++){
		bool mi = false, ma = false;
		for(int j = 0; j < i && !(mi&&ma); j++){
			if(arr[j] <= minSeen){
				mi = true;
			}
			if(arr[j] >= maxSeen){
				ma = true;
			}
			if(arr[i] > arr[j]){
				low[i] = max(low[i],high[j]+1);
			}
			else if(arr[i] < arr[j]){
				high[i] = max(high[i],low[j]+1);
			}
		}
		maxSeen = max(maxSeen,arr[i]);
		minSeen = min(minSeen,arr[i]);
	}

	cout << max(high[N-1],low[N-1]);

	return 0;
}

	int N;
	cin >> N;

	for(int i = 0; i < N; i++){
		cin >> arr[i];
		high[i] = 1;
		low[i] = 1;
	}

	for(int i = 1; i < N; i++){
		bool mi = false, ma = false;
		for(int j = 0; j < i && !(mi&&ma); j++){
			if(arr[j] <= minSeen){
				mi = true;
			}
			if(arr[j] >= maxSeen){
				ma = true;
			}
			if(arr[i] > arr[j]){
				low[i] = max(low[i],high[j]+1);
			}
			else if(arr[i] < arr[j]){
				high[i] = max(high[i],low[j]+1);
			}
		}
		maxSeen = max(maxSeen,arr[i]);
		minSeen = min(minSeen,arr[i]);
	}

	cout << max(high[N-1],low[N-1]);

	return 0;
}
