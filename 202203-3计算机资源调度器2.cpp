#include<bits/stdc++.h>
using namespace std;

struct Node{
	int number;
	int area;
	int tasknum;
	set<int> app;
//	Node(int number, int area) {
//		this->number = number;
//		this->area = area;
//		this->tasknum = 0;
//	}
	bool operator <(const Node &n) const {
		if (this->tasknum != n.tasknum) {
			return this->tasknum < n.tasknum;
		}
		else {
			return this->number < n.number;
		}
	}
};

vector<set<int>> area_app;

unordered_map<int, Node> nodes;
vector<int> avai;
vector<int> avai_paa;
vector<int> avai_default;

void nacheck(int na) {
	if (na == 0) {
		return;
	}
//		cout << "na=" << na << endl;
	for (auto i = avai.begin(); i != avai.end();) {
//			cout << "area=" << (*i).area << endl;
		if (nodes[*i].area != na) {
			avai.erase(i);
//				cout << "erase" << (*i).number << endl;
		}
		else {
			i++;
		}
	}
}

void pacheck(int pa) {
//	if (avai.size() == 0) {
//		return;
//	}
	if (pa == 0) {
		return;
	}
	for (auto i = avai.begin(); i != avai.end();) {
		int area = nodes[(*i)].area;
		if (area_app[area].find(pa) == area_app[area].end()) {
			avai.erase(i);
		}
		else {
			i++;
		}
//		if (area_app[area].count(pa) == 0) {
//			avai.erase(i);
//		}
//		else {
//			i++;
//		}
	}
}

void paacheck(int paa) {
//	if (avai.size() == 0) {
//		return;
//	}
	if (paa == 0) {
		return;
	}
	for (auto i = avai.begin(); i != avai.end();) {
		if (nodes[(*i)].app.find(paa) != nodes[(*i)].app.end()) {
			avai_paa.emplace_back(*i);
			avai.erase(i);
		}
		else {
			i++;
		}
//        if (nodes[(*i)].app.count(paa) == 1) {
//			avai_paa.emplace_back(*i);
//			avai.erase(i);
//		}
//		else {
//			i++;
//		}
	}
}

bool cmp(int n1, int n2) {
	return nodes[n1] < nodes[n2];
}

bool nodecmp(int n1, int n2) {
	if (nodes[n1].tasknum < nodes[n2].tasknum) {
		return true;
	}
	else if (nodes[n1].tasknum > nodes[n2].tasknum) {
		return false;
	}
	else {
		return n1 < n2;
	}
}

int main() {
//		freopen("stdin.txt","r",stdin);
	ios::sync_with_stdio(false);
	int n, m;//计算节点和可用区的数目 
	cin >> n >> m;
//	scanf("%d %d", &n, &m);
	int area;
	area_app.resize(m + 1);
	for (int i = 1; i <= n; i++) {
//		scanf("%d", &area);
		cin >> area;
		nodes.insert(pair<int, Node>(i, Node{i, area, 0, set<int>()}));
//		Node node(i, area);
//		nodes[i] = node;
		avai_default.emplace_back(i);
	}
//		for (auto i = nodes.begin(); i != nodes.end(); i++) {
//			cout << i->first << (i->second).area << endl;
//		}
//		cout << endl;
	int g;
	cin >> g;
//	scanf("%d", &g);
	//任务数f，应用编号a，可用区编号na 
	//和pa应用在同一个可用区
	//不能和paa应用在同一个节点
	//paar满足性要求 
	int f, a, na, pa, paa, paar;
	while (g > 0) {
		g--;
//		scanf("%d %d %d %d %d %d", &f, &a, &na, &pa, &paa, &paar);
		cin >> f >> a >> na >> pa >> paa >> paar;
		while (f > 0) {
			f--;
			avai.clear();
			avai = avai_default;
//				for (vector<Node>::iterator i = avai.begin(); i != avai.end(); i++) {
//					cout << (*i).number << ' ' << (*i).area << endl;
//				}
//				cout << endl;
			avai_paa.clear();
			nacheck(na);
			pacheck(pa);
			paacheck(paa);
			if (avai.size() == 0 && paar == 0) {
				avai.clear();
				avai = avai_paa;
			}
			if (avai.size() != 0) {
//				sort(avai.begin(), avai.end(), nodecmp);
//				sort(avai.begin(), avai.end(), [](int &a, int &b)->bool{
//					return nodes[a] < nodes[b];
//				});
				sort(avai.begin(), avai.end(), cmp);
//				printf("%d ", avai[0]);
				cout << avai[0] << ' ';
				nodes[avai[0]].tasknum++;
				nodes[avai[0]].app.insert(a);
				area_app[nodes[avai[0]].area].insert(a);
			}
			else {
//				printf("0 ");
				cout << "0 ";
			}
		}
//		printf("\n");
		cout << endl;
	}
//	10 4 1 1 1 1 1 2 2 2 2 2 6 2 1 4 1 2 1 6 1 1 0 1 1 1 2 2 0 0 0 6 1 2 0 2 1 5 2 2 0 1 0 11 3 0 1 3 0
	return 0;
}
