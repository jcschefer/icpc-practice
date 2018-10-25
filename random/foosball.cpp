#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
	int n;
	cin >> n;
	queue<string> line;
	string wo, bo, wd, bd;
	cin wo >> bo >> wd >>bd;
	for (int k = 4; k < n; k++) {
		string p;
		cin >> p;
		line.push(p);
	}

	string scores;
	cin >> scores;
	string longeststreakppl = ""
	unordered_map<int, vector<string>> streak_to_teams;
	int longeststreak = -1;
	int currentstreak = 0;
	bool whitehasstreak = scores[i] == 'W';
	for (int i = 0; i < scores.size(); i++) {
		bool whitescored = scores[i] == 'W';
		if (whitescored == whitehasstreak) {
			// same people scored again
			currentstreak++;
			if (currentstreak >= longeststreak) {
				longeststreak = currentstreak;
				longeststreakppl = whitescored ?
					wd + ""

		}

	}
}
