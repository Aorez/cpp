#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, N;
	cin >> n >> N;
	int num;
	int pre = 0;
	int sum = 0;
	int index = 0;
	while (n > 0) {
		scanf("%d", &num);
		sum += (num - pre) * index;
		index++;
		pre = num;
		n--;
	}
	num = N;
	sum += (N - pre) * index;
	cout << sum;
	return 0;
}
