#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> vs;
queue<int> que;
unordered_set<int> se;
int flag = 0;
int s;

void dfs(int u) {
    se.erase(u);
    que.push(u);
    if (se.empty() == true) {
        flag = 1;
        return;
    }
    for (int i = vs[u].size() - 1; i >= 0; i--) {
        int v = vs[u][i];
        vs[u].pop_back();
        if (se.find(v) != se.end()) {
            dfs(v);
            que.push(u);
        }
    }
    if (u == s && flag == 0) {
    	que.push(0);
	}
}

int main() {
    int n, m;
    cin >> n >> m >> s;
    for (int i = 1; i <= n; i++) {
        se.insert(i);
    }
    vs.resize(n + 1);
    int v1, v2;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &v1, &v2);
        vs[v1].emplace_back(v2);
        vs[v2].emplace_back(v1);
    }
    for (int i = 1; i <= n; i++) {
        sort(vs[i].begin(), vs[i].end());
        reverse(vs[i].begin(), vs[i].end());
    }
//    for (int i = 1; i <= n; i++) {
//    	for (int j = 0; j < vs[i].size(); j++) {
//    		cout << vs[i][j] << ' ';
//		}
//		cout << endl;
//	}
    dfs(s);
    while (!que.empty() && que.size() != 1) {
        printf("%d ", que.front());
        que.pop();
    }
    cout << que.front();
    return 0;
}
