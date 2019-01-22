#include <iostream>
using namespace std;

int max (int a, int b) {
	return a > b ? a : b;
}

int main() {
	int maxw;
	while (cin >> maxw) {
		if (maxw == 0 ) break;
		
		int col=0,height = 0;
		int tmaxheight = 0;
		int maxwidth = 0;

		int w, h;
		while (cin >> w >> h) {
			if (w == -1 && h == -1) {
				height += tmaxheight;
				maxwidth = max(col, maxwidth);
				break;
			}

			if (col + w > maxw) {
				height += tmaxheight;
				maxwidth = max(col, maxwidth);
				col = 0;
				tmaxheight = 0;
			}

			col += w;
			tmaxheight = max(h, tmaxheight);
		}

		cout << maxwidth << " x " << height << endl;
	}
}
