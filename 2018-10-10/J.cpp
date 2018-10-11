#include <iostream>

using namespace std;
int startTimes[11],usages[11],rests[11];
int jU[11],jR[11];

int all10(int start){
	int time = start;
	for(int i = 0; i < 10; i++){
		if(time < startTimes[i]){
			time += jU[i] + jR[i];
			if(time -jR[i] > startTimes[i]){
				startTimes[i] += time -jR[i] - startTimes[i];
			}
			continue;
		}
		int tmp = time - startTimes[i];
		tmp %= usages[i]+rests[i];
		if(tmp > usages[i]){
			int remrest = usages[i]+rests[i]-tmp;
			time += jU[i] + jR[i];
			if(remrest < jU[i]){
				startTimes[i] += jU[i]-remrest;
			}
			continue;
		}
		else{
			time += usages[i]-tmp;
			time += jU[i] + jR[i];
			if(jU[i] > rests[i]){
				startTimes[i] += jU[i]-rests[i];
			}
		}
	}
	return time;
}

int main(){

	for(int i = 0; i < 10; i++){
		cin >> jU[i] >> jR[i];
	}
	for(int i = 0; i < 10; i++){
		cin >> usages[i] >> rests[i] >> startTimes[i];
	}

	cout << all10(all10(all10(0))) -jR[9];

	return 0;
}
