#include<bits/stdc++.h>
using namespace std;
const int MAX = 21;
int n;
int y;
int t;
int ar[MAX];
int total = 0;//方法总计
vector<int> ans;
int flag = 0;
 
//初始化
void Initialize() {
	cin >> n >> y;
	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		ar[i] = num;
	}
	cin >> t;
}

void problem(int pos, int sum) {
//		for (int i = 0; i < ans.size(); i++) {
//			cout << ans[i] << ' ';
//		}
//		cout << endl;
	if (sum == y) {
		total++;//方法总计
//		cout << "total为" << total << endl;
		if (total == t) {
			flag = 1;
			for (int i = 0; i < ans.size() - 1; i++) {
				cout << ans[i] << ' ';
			}
			cout << ans[ans.size() - 1];
		}
		return;
	}
	for (int i = pos; flag == 0 && i < n; i++) {
		if (sum + ar[i] > y) {
			break;
		}
		else {
//			cout << "插入" << ar[i] << endl; 
			ans.emplace_back(ar[i]);
			problem(i + 1, sum + ar[i]);
//			cout << "弹出" << ans[ans.size() - 1] << endl;
			ans.pop_back();//回溯
		}
	}
}

//6 80 10 20 30 50 60 80 2
 
int main() {
	Initialize();
	problem(0, 0);
	if (flag == 0) {
		cout << "No Solution!";
	}
	return 0;
}
