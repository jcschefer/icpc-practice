#include <iostream>
using namespace std;

int max(int a, int b) {return a > b ? a : b;}

int main() {
	while (1) {
		int m;
		cin >> m;
		
		if (m==0) break;

		int* rowheights = new int[16];
		int max_width = 0;
		int max_height = 0;
		int sofar = 0;

		int width,height, curr = 0;
		while (1) {
			cin >> width >> height;
			bool done = (width == -1 && height == -1);

			if (sofar + width > m || done) {
				max_width = max(max_width, sofar);
				max_height += rowheights[curr];
				curr++;
				sofar = 0;
			}

			if (done) break;

			rowheights[curr] = max(rowheights[curr], height);
			sofar += width;
		}

		cout << max_width << " x " << max_height<<endl;
	}
}
