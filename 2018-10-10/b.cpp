#include <vector>
#include <algorithm>
#include<iostream>
#include <unordered_map>

using namespace std;

vector<int> meals;
int intake_max;
int mealnum;
unordered_map<int, int> memo;

int hash(int a, int b, int c) {
	return 31*a+37*b+41*c;
}

int maxeat(int index, int intake_current, char rested) {
	if (index == mealnum) {
		return 0;
	}

	auto finding = memo.find(hash(index, intake_current, rested));
	if (finding != memo.end()) {
		return *finding;
	}

	if (rested ==2){
		intake_current = intake_max;

		int result max(
			maxeat(index+1, intake_current, 0) + min(meals.at(index), intake_current),
			maxeat(index+1, intake_current, 2)
		);
	}
	else if (rested == 1) {
		return max(
			maxeat(index+1, intake_current, 0) + min(meals.at(index), intake_current),
			maxeat(index+1, intake_current, 2)
		);
	}
	else {
		intake_current = intake_current * 2 / 3;
		return max(
			maxeat(index+1, intake_current, 0) + min(meals.at(index), intake_current),
			maxeat(index+1, intake_current, 1)
		);
	}


}

int main() {
	cin >> mealnum;
	cin >> intake_max;

	for (int i = 0; i < mealnum; i++) {
		int n;
		cin >>n;
		meals.push_back(n);

	}

	cout << maxeat(0, intake_max, 2);


}
