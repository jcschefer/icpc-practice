#include <iostream>

using namespace std;

int main(){

	int bArr[1010];

	int N, M;
	int arr [1010];
	cin >> N >> M;
	for(int i = 0; i < N; i++){
		cin >> arr[i];
	}
	for(int time = 0; time < N; time++){
		int best = 0;
		for(int i = 0; i < time; i++){
			if(time - i > 2){

			}
			else if(time - i == 2){

			}
			else if(time - i == 1){

			}
		}
		bArr[time] = best;
	}

	return 0;
}
