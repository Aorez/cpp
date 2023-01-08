#include<bits/stdc++.h>
using namespace std;

struct Pulse{
	double intensity;
	int delay;
};

struct Neuron{
	int type;
	double v;
	double u;
	vector<Pulse> pulses;
	int count;
};

struct Type{
	double a, b, c, d;
};

//struct Source{
//	int r;
//};

struct Synapse{
	int s;
	int t;
	double w;
	int D;
	bool operator <(Synapse syn) {
		return this->D < syn.D;
	}
};

unordered_map<int, Neuron> neurons;
unordered_map<int, int> sources;
unordered_map<int, Type> types;
unordered_map<int, Synapse> syns;
vector<vector<int>> edges;

static unsigned long nextrand = 1;

int myrand() {
    nextrand = nextrand * 1103515245 + 12345;
    return ((nextrand / 65536) % 32768);
}

int main() {
		freopen("stdin.txt", "r", stdin);
	ios::sync_with_stdio(false);
	int N, S, P, T;
	cin >> N >> S >> P >> T;
//	scanf("%d %d %d %d", &N, &S, &P, &T);
//		cout << N << ' ' << S << ' ' << P << ' ' << T << endl;
	edges.resize(N + P + 10);
//	edges.resize(999999);
	int NN = N;
	int PP = P;
	int SS = S;
	double deltat;
	cin >> deltat;
//	scanf("%lf", &deltat);
//		cout << deltat << endl;
	int rn;
	double v, u, a, b, c, d;
	int typei = 1;
	int neuroni = 0;
//	cout << "������Ԫ\n";
	while (NN > 0) {
		cin >> rn >> v >> u >> a >> b >> c >> d;
//		scanf("%d %lf %lf %lf %lf %lf %lf", &rn, &v, &u, &a, &b, &c, &d);
//			cout << rn << ' ' << v << ' ' << u << ' ' << a << ' ' << b << ' ' << c << ' ' << d << endl;
		NN -= rn;
//		types[typei] = Type{a, b, c, d};
		types.insert({typei, Type{a, b, c, d}});
//		cout << typei << "��������Ԫ\n";
		while (rn > 0) {
//			neurons[neuroni] = Neuron{typei, v, u, vector<Pulse>(), 0};
			neurons.insert({neuroni, Neuron{typei, v, u, vector<Pulse>(), 0}});
			neuroni++;
			rn--;
		}
		typei++;
	}
	int r;
	int sourcei = N;
//		cout << "��������Դ\n";
//	for (auto it = sources.begin(); it != sources.end(); it++) {
//		cout << it->first << ' ' << it->second << endl;
//	}
//		cout << "��������Դ\n";
	while (PP > 0) {
//		cout << "����1\n";
//		cin.clear();
		cin >> r;
//		scanf("%d", &r);
//		cout << "����2\n";
		sources.insert(pair<int, int>(sourcei, r));
//		cout << "����3\n";
		PP--;
//		cout << "����" << sourcei << "rֵ" << r << endl;
//		sources[sourcei] = r;
//		cout << sources[sourcei] << endl;
		sourcei++;
	}
	int s, t, D;
	double w;
	int syni = 1;
//		cout << "����ͻ��\n";
	while (SS > 0) {
		SS--;
		cin >> s >> t >> w >> D;
//		scanf("%d %d %lf %d", &s, &t, &w, &D);
//		printf("%d %d %lf %d", s, t, w, D);
//		syns[syni] = Synapse{s, t, w, D};
		syns.insert({syni, Synapse{s, t, w, D}});
		edges[s].emplace_back(syni);
		syni++;
	}
//	cout << "edges.size=" << edges.size() << endl;
//	for (int i = 0; i < edges.size(); i++) {
//		cout << i << "��";
//		for (int ii = 0; ii < edges[i].size(); ii++) {
//			cout << edges[i][ii] << ' ';
//		}
//		cout << endl;
//	}
//	cout << "��ʼģ��\n";
	int TT = 1; 
	while (T > 0) {
		cout << TT << "ʱ��\n";
		TT++;
		T--;
		for (auto it = neurons.begin(); it != neurons.end(); it++) {
			Neuron &neurontemp = it->second;
			double prev = neurontemp.v;
			double preu = neurontemp.u;
			double I = 0;
			cout << it->first << "����Ԫ\n";
			for (auto it2 = neurontemp.pulses.begin(); it2 != neurontemp.pulses.end();) {
				it2->delay -= 1;
				cout << "����ǿ�ȣ�" << it2->intensity << ' ';
				cout << "�����ӳ٣�" << it2->delay << endl;
				if (it2->delay == 0) {
					I += it2->intensity;
					cout << "���I=" << I << endl;
					neurontemp.pulses.erase(it2);
				}
				else {
					cout << "δ����\n";
					it2++;
				}
				cout << endl;
			}
			cout << "ǿ��" << I << endl;
			neurontemp.v = prev+deltat*(0.04*prev*prev+5*prev+140-preu)+I;
//			-70+0.1*(0.04*(-70)*(-70)+5*(-70)+140-(-14))
			Type &typetemp = types[neurontemp.type];
			a = typetemp.a;
			b = typetemp.b;
			neurontemp.u = preu+deltat*a*(b*prev-preu);
			cout << "vֵ��" << neurontemp.v << endl;
			cout << "uֵ��" << neurontemp.u << endl;
			cout << endl;
		}
		for (auto it = neurons.begin(); it != neurons.end(); it++) {
			Neuron &neurontemp = it->second;
			Type &typetemp = types[neurontemp.type];
			if (neurontemp.v >= 30) {
				cout << "����30����\n";
				int v1 = it->first;
				neurontemp.v = typetemp.c;
				neurontemp.u += typetemp.d;
				for (int syni: edges[v1]) {
					Synapse syntemp = syns[syni];
					Neuron &neurontemp = neurons[syntemp.t];
					neurontemp.pulses.emplace_back(Pulse{syntemp.w, syntemp.D});
					cout << "���ݵ���Ԫ" <<syntemp.t << endl;
					cout << "����Ԫ���壺\n";
					for (auto i: neurontemp.pulses) {
						cout << i.intensity <<  ' ' << i.delay << endl;
					}
				}
				neurontemp.count += 1;
				cout << "�����ܴ���" << neurontemp.count << endl;
				cout << "vֵ�ı䣺" << neurontemp.v << endl;
				cout << "uֵ�ı䣺" << neurontemp.u << endl;
			}
			else {
				cout << "������\n";
			}
			cout << endl;
		}
		for (sourcei = N; sourcei <= N + P - 1; sourcei++) {
			int rand = myrand();
			r = sources[sourcei];
			cout << "����" << sourcei << ' ';
			cout << "rֵ" << r << ' ';
			cout << "rand��" << rand << endl;
			if (r > rand) {
				cout << "����\n";
				for (int syni: edges[sourcei]) {
					Synapse &syntemp = syns[syni];
					Neuron &neurontemp = neurons[syntemp.t];
					neurontemp.pulses.emplace_back(Pulse{syntemp.w, syntemp.D});
					cout << "���ݵ���Ԫ" <<syntemp.t << ' ';
					cout << "����Ԫ���壺\n";
					for (auto i: neurontemp.pulses) {
						cout << i.intensity <<  ' ' << i.delay << endl;
					}
				}
			}
			else {
				cout << "������\n";
			}
			cout << endl;
		}
	}
	Neuron &neurontemp = neurons[0];
	double minv = neurontemp.v, maxv = neurontemp.v;
	int mincount = neurontemp.count, maxcount = neurontemp.count;
	for (auto it = neurons.begin(); it != neurons.end(); it++) {
		Neuron &neurontemp = it->second;
		minv = min(minv, neurontemp.v);
		maxv = max(maxv, neurontemp.v);
		mincount = min(mincount, neurontemp.count);
		maxcount = max(maxcount, neurontemp.count);
	}
//	printf("%lf %lf\n%d %d\n", minv, maxv, mincount, maxcount);
	printf("%.3lf %.3lf\n", minv, maxv);
	cout << mincount << ' ' << maxcount << endl;
//1 1 1 10
//0.1
//1 -70.0 -14.0 0.02 0.2 -65.0 2.0
//30000
//1 0 30.0 2
	return 0;
}
