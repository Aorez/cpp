#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int pre = 0;
	int num;
	int min = 0, max = 0;
	while (n > 0) {
		scanf("%d", &num);
		if (num == pre) {
			max += num;
		}
		else {
			min += num;
			max += num;
			pre = num;
		}
		n--;
	}
	cout << max << endl << min << endl;
//	6 0 0 5 5 10 10
//	7 10 20 30 40 50 60 75
	return 0;
}
