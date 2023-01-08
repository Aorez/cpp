#include<bits/stdc++.h>
using namespace std;

int n, a, b;
int flag = 0;
int bo[1001][1001];
int rowadd[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int coladd[] = {-1, -2, -2, -1, 1, 2, 2, 1};

bool check(int r, int c) {
	if (r < 1 || c < 1 || r > n || c > n || bo[r][c]) {
		return false;
	}
	return true;
}

int steps(int r, int c) {
	int step = 0;
	for (int i = 0; i < 8; i++) {
		if (check(r + rowadd[i], c + coladd[i])) {
			step++;
		}
	}
	return step;
}

void dfs(int r, int c, int count) {
//	cout << count << endl;
	if (count == n * n + 1) {
		flag = 1;
		return;
	}
	int row, col;
	for (int i = 0; flag == 0 && i < 8; i++) {
		row = r + rowadd[i];
		col = c + coladd[i];
		if (check(row, col)) {
			bo[row][col] = count + 1;
			dfs(row, col, count + 1);
			bo[row][col] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> a >> b;
	bo[a][b] = 1;
	dfs(a, b, 1);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << bo[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}
