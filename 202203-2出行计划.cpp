#include<bits/stdc++.h>
using namespace std;

const int MAX = 2e5 + 1;
int diff[MAX] = {0};

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	int t, c;
	int l, r;
	while (n > 0) {
		n--;
		scanf("%d %d", &t, &c);
		l = max(0, t - k - c + 1);
		r = t - k;
		if (r <= 0) {
			continue;
		}
		diff[l]++;
		diff[r + 1]--;
	}
	for (int i = 1; i < MAX; i++) {
		diff[i] += diff[i - 1];
	}
	int q;
	while (m > 0) {
		scanf("%d", &q);
		printf("%d\n", diff[q]);
		m--;
	}
	return 0;
}
