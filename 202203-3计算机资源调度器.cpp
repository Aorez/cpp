#include<bits/stdc++.h>
using namespace std;

struct Node{
	int number;
	int area;
	int tasknum;
	set<int> app;
	Node(int number, int area) {
		this->number = number;
		this->area = area;
		this->tasknum = 0;
	}
};

bool nodecmp(Node node1, Node node2) {
	if (node1.tasknum < node2.tasknum) {
		return true;
	}
	else if (node1.tasknum > node2.tasknum) {
		return false;
	}
	else {
		return node1.number < node2.number;
	}
}

vector<set<int>> area_app;

vector<Node> nodes;
vector<Node> avai;
vector<Node> avai_paa;

void nacheck(int na) {
	if (na == 0) {
		return;
	}
//		cout << "na=" << na << endl;
	for (vector<Node>::iterator i = avai.begin(); i != avai.end(); i++) {
//			cout << "area=" << (*i).area << endl;
		if ((*i).area != na) {
			avai.erase(i);
//				cout << "erase" << (*i).number << endl;
			i--;
		}
	}
}

void pacheck(int pa) {
	if (avai.size() == 0) {
		return;
	}
	if (pa == 0) {
		return;
	}
	for (vector<Node>::iterator i = avai.begin(); i != avai.end(); i++) {
		int area = (*i).area;
		if (area_app[area].find(pa) == area_app[area].end()) {
			avai.erase(i);
			i--;
		}
	}
}

void paacheck(int paa) {
	if (avai.size() == 0) {
		return;
	}
	if (paa == 0) {
		return;
	}
	for (vector<Node>::iterator i = avai.begin(); i != avai.end(); i++) {
		if ((*i).app.find(paa) != (*i).app.end()) {
			avai_paa.emplace_back(*i);
			avai.erase(i);
			i--;
		}
	}
}

void paarcheck() {
	avai.clear();
	avai = avai_paa;
}

int main() {
		freopen("stdin.txt","r",stdin);
	ios::sync_with_stdio(false);
	int n, m;//计算节点和可用区的数目 
	cin >> n >> m;
	int area;
	area_app.resize(m + 1);
	for (int i = 1; i <= n; i++) {
		cin >> area;
		Node node(i, area);
		nodes.emplace_back(node);
	}
//		for (vector<Node>::iterator i = nodes.begin(); i != nodes.end(); i++) {
//			cout << (*i).number << ' ' << (*i).area << endl;
//		}
//		cout << endl;
	int g;
	cin >> g;
	//任务数f，应用编号a，可用区编号na 
	//和pa应用在同一个可用区
	//不能和paa应用在同一个节点
	//paar满足性要求 
	int f, a, na, pa, paa, paar;
	while (g > 0) {
		g--;
		cin >> f >> a >> na >> pa >> paa >> paar;
		while (f > 0) {
			f--;
			avai.clear();
			avai = nodes;
//				for (vector<Node>::iterator i = avai.begin(); i != avai.end(); i++) {
//					cout << (*i).number << ' ' << (*i).area << endl;
//				}
//				cout << endl;
			avai_paa.clear();
			nacheck(na);
			pacheck(pa);
			paacheck(paa);
			if (avai.size() == 0 && paar == 0) {
				paarcheck();
			}
			if (avai.size() != 0) {
				sort(avai.begin(), avai.end(), nodecmp);
				cout << avai[0].number << ' ';
				nodes[avai[0].number - 1].tasknum++;
				nodes[avai[0].number - 1].app.insert(a);
				area_app[nodes[avai[0].number - 1].area].insert(a);
			}
			else {
				cout << 0 << ' ';
			}
		}
		cout << endl;
	}
//	10 4 1 1 1 1 1 2 2 2 2 2 6 2 1 4 1 2 1 6 1 1 0 1 1 1 2 2 0 0 0 6 1 2 0 2 1 5 2 2 0 1 0 11 3 0 1 3 0
	return 0;
}
