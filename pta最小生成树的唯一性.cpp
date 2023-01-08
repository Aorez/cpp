#include<bits/stdc++.h>
using namespace std;

struct edge {
	int v1, v2, w;
};

//²»Í¨¹ý 
//6 6
//1 2 4
//2 3 3
//3 4 4
//5 6 4
//1 6 1
//2 5 2

bool cmp(edge &e1, edge&e2) {
	return e1.w < e2.w;
}

vector<edge> edges;
int ufs[501];
set<int> s;

int find(int v) {
	if (ufs[v] == -1) {
		return v;
	}
	else {
		return find(ufs[v]);
	}
}

void merge(int a, int b) {
	int x = find(a);
	int y = find(b);
	ufs[x] = y;
}

int main() {
	ios::sync_with_stdio(false);
	memset(ufs, -1, sizeof(ufs));
	int N, M;
	cin >> N >> M;
	int v1, v2, w;
	for (int i = 0; i < M; i++) {
		edge e;
		cin >> v1 >> v2 >> w;
		e.v1 = v1;
		e.v2 = v2;
		e.w = w;
		edges.emplace_back(e);
	}
	sort(edges.begin(), edges.end(), cmp);
	for (int i = 0; i < M; i++) {
		cout << edges[i].v1 << ' ' << edges[i].v2 << ' ' << edges[i].w << endl;
	}
	cout << endl;
	int total = 0;
	int flag = 0;
	for (int i = 0, num = 0; i < M && num < N - 1; i++) {
		int part1 = find(edges[i].v1);
		int part2 = find(edges[i].v2);
		if (part1 != part2) {
//			for (int j = i + 1; j < M; j++) {
//				if (edges[j].w == edges[i].w) {
//					int part3 = find(edges[j].v1);
//					int part4 = find(edges[j].v2);
//					if (part3 == part1 && part4 == part2 || part3 == part2 && part4 == part1) {
//						flag = 1;
//					}
//				}
//				else {
//					break;
//				}
//			}
			int j = i + 1;
			if (edges[j].w == edges[i].w) {
				int part3 = find(edges[j].v1);
				int part4 = find(edges[j].v2);
				if (part3 == part1 && part4 == part2 || part3 == part2 && part4 == part1) {
					flag = 1;
				}
			}
			total += edges[i].w;
			merge(part1, part2);
			num++;
		}
	}
	
	for (int i = 1; i <= N; i++) {
		s.insert(find(i));
	}
	if (s.size() > 1) {
		cout << "No MST\n" << s.size();
	}
	else {
		cout << total << endl;
		if (flag == 0) {
			cout << "Yes";
		}
		else {
			cout << "No";
		}
	}
	return 0;
}
