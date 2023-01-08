#include<bits/stdc++.h>
using namespace std;

const int MAX = 610;
int A[MAX][MAX];
int sna[MAX][MAX];

int main() {
	int n, L, r, t;
	scanf("%d %d %d %d ", &n, &L, &r, &t);
//	row-r+0, col-r, row-r+0, col+r//第一个 
//	     +1, ,           +1, //第二个neighbor
//	     +2, ,           +2, //第三个
//	共有2r+1行 
	for (int N = 0; N < n; N++) {
		scanf("%d", &A[N][0]);
		sna[N][0] = A[N][0];
		for (int NN = 1; NN < n; NN++) {
			scanf("%d", &A[N][NN]);
			sna[N][NN] = sna[N][NN - 1] + A[N][NN]; 
		}
	}
//	cout << endl;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			cout << sna[i][j] << ' ';
//		}
//		cout << endl;
//	}
//	cout << endl;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			cout << A[i][j] << ' ';
//		}
//		cout << endl;
//	}
	double nei;
	int startr, totalr, nowr;
	int leftc, rightc;
	int ans = 0;
	int count;
	for (int row = 0; row < n; row++) {
		for (int col = 0; col < n; col++) {
			nei = 0;
			leftc = max(0, col - r);
			rightc = min(n - 1, col + r);
			startr = max(0, row - r);
			totalr = min(n - 1, row + r) - startr + 1;
			count = totalr * (rightc - leftc + 1);
			for (int i = 0; i < totalr; i++) {
				nowr = startr + i; 
				if (leftc - 1 < 0) {
					nei += sna[nowr][rightc];
				}
				else {
					nei += sna[nowr][rightc] - sna[nowr][leftc - 1];
				}
			}
			if (nei / count <= t) {
				ans++;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
