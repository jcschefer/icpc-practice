#include <iostream>
#include <string>
using namespace std;



int main() {
	int N;
	cin >> N;

	for (int n = 0; n < N; n++) {
		int num;
		string line;
		cin >> num;
		getline(cin, line);
		line += " ";

		string newline = "";

		for (int i = 0; i < line.size(); i++) {
			if (i < line.size() - 2) {
				string small = line.substr(i, 3);
				if (small == "sss") {
					newline += "[longs]s";
					i += 1;
					continue;
				} else if (small == "ffi") {
					newline += "[ffi]";
					i += 2;
					continue;
				} else if (small == "ffl") {
					newline += "[ffl]";
					i += 2;
					continue;
				} else if (small == "ssi") {
					newline += "[longssi]";
					i += 2;
					continue;
				}
			}
			if (i < line.size() - 1){
				string small = line.substr(i, 2);
				char next = small.at(1);
				if (small == "AE") {
					newline += "[AE]";
					i += 1;
					continue;
				} else if (small == "Ae") {
					newline += "[AE]";
					i += 1;
					continue;
				} else if (small == "ae") {
					newline += "[ae]";
					i += 1;
					continue;
				} else if (small == "OE") {
					newline += "[OE]";
					i += 1;
					continue;
				}else if (small == "Oe") {
					newline += "[OE]";
					i += 1;
					continue;
				} else if (small == "oe") {
					newline += "[oe]";
					i += 1;
					continue;
				} else if (small == "ct") {
					newline += "[ct]";
					i += 1;
					continue;
				} else if (small == "ff") {
					newline += "[ff]";
					i += 1;
					continue;
				} else if (small == "fi") {
					newline += "[fi]";
					i += 1;
					continue;
				} else if (small == "fl") {
					newline += "[fl]";
					i += 1;
					continue;
				} else if (small == "si") {
					newline += "[longsi]";
					i += 1;
					continue;
				} else if (small == "sh") {
					newline += "[longsh]";
					i += 1;
					continue;
				} else if (small == "sl") {
					newline += "[longsl]";
					i += 1;
					continue;
				} else if (small == "ss") {
					newline += "[longss]";
					i += 1;
					continue;
				} else if (small == "st") {
					newline += "[longst]";
					i += 1;
					continue;
				} else if (small.at(0) == 's') {
					char next = small.at(1);
					if (( (int)next <= 122 && (int)next >= 97) || ((int)next <= 90 && (int)next >= 65 )) {
						//next char is a letter
						newline += "[longs]";
						continue;
					} 
				}
				else if (small.at(0) == 's' && !(( (int)next <= 122 && (int)next >= 97) || ((int)next <= 90 && (int)next >= 65 )) )
				{
					newline += "s";
					continue;
				}
			}
			// 1 char
			if (line.at(i) == 's') {
				newline += "[longs]" ;
				continue;
			}

			newline += line.substr(i, 1);
		}
		newline = newline.substr(1, newline.length() - 1);
		cout << num << " " << newline<<endl;
	}
	return 0;
}
