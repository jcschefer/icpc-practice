
#include <iostream>
using namespace std;

typedef struct node {
	int v;
	int c;
	int m;
	int* obstructs;
} node;

int maxVal(node* root) {
	for (int ind = 0; ind < root->m; ind++) {
		int 
	}
}

int main() {
	int n;
	cin >> n;
	node** nodes = new node*[n+1];

	for (int i = 0; i < n; i++) {
		int v, c;
		cin >> v;
		cin >> c;

		node* nn = new node;
		nn->v = v;
		nn->c = c;
		
		int m;
		cin >> m;
		nn->m = m;
		int* o = new int[m];

		for (int j = 0; j < m; j++) {
			cin >> o[j];
		}
		
		nn->obstrcuts = o;

		nodes[i] = nn;
	}

	node* root = new node;
	node->v = 0;
	node->c = 0;

	node->obstructs = new int[n];
	for (int k = 0; k < n;k++) node->obstructs[k]=k;

	cout<<maxVal(root)<<endl;


	return 0;
}
