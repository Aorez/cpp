#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

LL sgx(LL r, LL right) {
	if (right <= 0) {
		return 0;
	}
	LL n = (right + 1) / r;
	return (n - 1) * n / 2 * r + (right - (n * r - 1)) * n;
}

int main() {
	LL n, N;
	cin >> n >> N;
	LL r = N / (n + 1);
	LL left = 0;
	LL right;
	LL sum = 0;
	LL fx = 0;
	while (n > 0) {
		scanf("%lld", &right);
		if (left / r >= fx) {
			sum += sgx(r, right - 1) - sgx(r, left - 1);
			sum -= (right - left) * fx;
		}
		else if ((right - 1) / r <= fx) {
			sum -= sgx(r, right - 1) - sgx(r, left - 1);
			sum += (right - left) * fx;
		}
		else {
//			int mid = fx * r;
//			sum -= sgx(r, mid - 1) - sgx(r, left - 1);
//			sum += (mid - 1 - left) * fx;
//			sum += sgx(r, right - 1) - sgx(r, mid);
//			sum -= (right - mid + 1) * fx;
			int mid = fx * r;
			sum -= sgx(r, mid - 1) - sgx(r, left - 1);
			sum += (mid - left) * fx;
			sum += sgx(r, right - 1) - sgx(r, mid);
			sum -= (right - mid - 1) * fx;
		}
		left = right;
		fx++;
		n--;
	}
	right = N;
	if (left / r >= fx) {
		sum += sgx(r, right - 1) - sgx(r, left - 1);
		sum -= (right - left) * fx;
	}
	else if ((right - 1) / r <= fx) {
		sum -= sgx(r, right - 1) - sgx(r, left - 1);
		sum += (right - left) * fx;
	}
	else {
		int mid = fx * r;
		sum -= sgx(r, mid - 1) - sgx(r, left - 1);
		sum += (mid - left) * fx;
		sum += sgx(r, right - 1) - sgx(r, mid);
		sum -= (right - mid - 1) * fx;
	}
	printf("%lld\n", sum);
//	3 10 2 5 8 
//	2 10 1 3
//  9 10 1 2 3 4 5 6 7 8 9
	return 0;
}
