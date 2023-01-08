#include<bits/stdc++.h>
using namespace std;

int a[500005];
int c[10001];

int main() {
	int n;
	cin >> n;
	a[0] = 0;
	a[n + 1] = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	n = unique(a, a + n + 2) - a;
	for (int i = 1; i <= n - 1; i++) {
		if (a[i - 1] < a[i] && a[i + 1] < a[i]) {
			c[a[i]]++;
		}
		else if (a[i - 1] > a[i] && a[i + 1] > a[i]) {
			c[a[i]]--;
		}
	}
	int result = 0;
	int sum = 0;
	for (int i = 10000; i >= 0; i--) {
		sum += c[i];
		result = max(sum, result);
	}
	cout << result << endl;
//	11 3 1 2 0 0 2 0 4 5 0 2
//  5
//	14 5 1 20 10 10 10 10 15 10 20 1 5 10 15
//	4
//  3 1 0 0
//	1
//	3 0 0 0
//	0
	return 0;
}
