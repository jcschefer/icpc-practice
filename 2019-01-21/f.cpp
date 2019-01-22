#include <iostream>
using namespace std;

int qr[10];
int qc[10];

int main() {
	int qind = 0;
	for (int r = 0; r < 8; r++) {
		string row;
		cin >> row;
		for (int c= 0; c < 8; c++) {
			if (row[c] == '*') {
				qr[qind] = r;
				qc[qind] = c;
				qind++;
			}
		}
	}

	bool valid = true;

	if (qind != 8) valid = false;

	for (int qind = 0; qind < 8; qind++) {
		for (int qother = 0; qother < 8; qother++) {
			if (qind == qother) continue;

			if (qr[qind] == qr[qother] || qc[qind] == qc[qother]
				|| qr[qind] + qc[qind] == qr[qother] + qc[qother]
				|| qr[qind] - qc[qind] == qr[qother] - qc[qother]) {
				
				valid = false;
			}
			
		}
	}

	if (valid) cout << "valid" << endl;
	else cout << "invalid" << endl;
}
