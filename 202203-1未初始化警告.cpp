#include<bits/stdc++.h>
using namespace std;

int initial[100001];

int main() {
	int n, k;
	cin >> n >> k;
	int left, right;
	int count = 0;
	while (k > 0) {
		scanf("%d %d", &left, &right);
		if (right != 0 && initial[right] == 0) {
			count++;
		}
		initial[left] = 1;
		k--;
	}
	printf("%d", count);
	return 0;
}
