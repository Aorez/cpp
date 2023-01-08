#include<bits/stdc++.h>
using namespace std;

const int MAX = 500;
const int INF = 99999999;
int len[MAX][MAX];
int charge[MAX][MAX];
int shortest[MAX];
int cheapest[MAX];
int visited[MAX];
int from[MAX];
queue<int> queueue;

int main() {
	int N, M, S, D;
	cin >> N >> M >> S >> D;
	int c1, c2, l, c;
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d %d", &c1, &c2, &l, &c);
		len[c1][c2] = l;
		len[c2][c1] = l;
		charge[c1][c2] = c;
		charge[c2][c1] = c;
	}
	queueue.push(S);
	while (queueue.size() > 0) {
		int v = queueue.front();
		queueue.pop();
		if (visited[v] == 1) {
			continue;
		}
		for (int i = 0; i < N; i++) {
			if (len[v][i] != 0) {
				int len2 = len[v][i] + shortest[v];
				int cost2 = charge[v][i] + cheapest[v];
				if (shortest[i] == 0 || len2 < shortest[i]) {
					shortest[i] = len2;
					cheapest[i] = cost2;
					from[i] = v;
				}
				else if (len2 == shortest[i]) {
					if (cost2 < cheapest[i]) {
						cheapest[i] = cost2;
						from[i] = v;
					}
				}
				queueue.push(i);
			}
		}
		visited[v] = 1;
	}
	cout << shortest[D] << ' ' << cheapest[D] << endl;
	return 0;
}
