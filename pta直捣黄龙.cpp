#include<bits/stdc++.h>
using namespace std;

const int MAX = 200;
const int INF = 99999999;
vector<string> name;
unordered_map<string, int> number;
int len[MAX][MAX];
int troops[MAX];

int shortest[MAX];
int shortnum[MAX];
int towns[MAX];
int kills[MAX];

int visited[MAX];
int from[MAX];

void arrout(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << ' ';
	}
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	int N, K;
	string own, enemy;
	cin >> N >> K >> own >> enemy;
	int count = 0;
	name.push_back(own);
	number[own] = count;
	count++;
	string str;
	int t;
	for (int i = 1; i < N; i++) {
		cin >> str >> t;
		name.push_back(str);
		number[str] = count;
		troops[count] = t;
		count++;
	}
	string str2;
	for (int i = 0; i < K; i++) {
		cin >> str >> str2 >> t;
		len[number[str]][number[str2]] = t;
		len[number[str2]][number[str]] = t;
	}
	shortnum[0] = 1;
	int v = 0;
	visited[0] = 1;
	for (int i = 0; i < N; i++) {
		if (len[v][i] != 0) {
			shortest[i] = len[v][i];
			kills[i] = troops[i];
			towns[i] = 1;
			shortnum[i] = 1;
			from[i] = 0;
		}
	}
	for (int k = 0; k < N; k++) {
		int v = -1;
		for (int j = 0; j < N; j++) {
			if (visited[j] == 1) {
				continue;
			}
			if (shortest[j] != 0) {
				if (v == -1) {
					v = j;
				}
				else if (shortest[j] < shortest[v]) {
					v = j;
				}
			} 
		}
		if (v == -1) {
			break;
		}
		else {
			visited[v] = 1;
		}
		for (int i = 0; i < N; i++) {
			if (visited[i] == 1) {
				continue;
			}
			if (len[v][i] != 0) {
				int len2 = len[v][i] + shortest[v];
				int towns2 = 1 + towns[v];
				int kills2 = troops[i] + kills[v];
				if (shortest[i] == 0 || len2 < shortest[i]) {
					shortest[i] = len2;
					towns[i] = towns2;
					kills[i] = kills2;
					from[i] = v;
					shortnum[i] = shortnum[v];
				}
				else if (len2 == shortest[i]) {
					shortnum[i] += shortnum[v];
					if (towns2 > towns[i]) {
						towns[i] = towns2;
						kills[i] = kills2;
						from[i] = v;
					}
					else if (towns2 == towns[i]) {
						if (kills2 > kills[i]) {
							kills[i] = kills2;
							from[i] = v;
						}
					} 
				}
			}
		}
	}
	stack<int> sta;
	int num = number[enemy];
	sta.push(num);
	while (num != 0) {
		num = from[num];
		sta.push(num);
	}
	cout << own;
	sta.pop();
	while (sta.size() > 0) {
		cout << "->" << name[sta.top()];
		sta.pop();
	}
	cout << endl;
	cout << shortnum[number[enemy]] << ' ' << shortest[number[enemy]] << ' ' << kills[number[enemy]] << endl;
	return 0;
}
