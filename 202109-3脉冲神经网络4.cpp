#include<bits/stdc++.h>
using namespace std;

struct Pulse{
	double I;
	int D;
};

//struct Neuron{
//	int type;
//	double v;
//	double u;
//	double a;
//	double b;
//	double c;
//	double d;
//	int count;
//	vector<Pulse> pulses;
//};

double neuronv[1001];
double neuronu[1001];
double neurona[1001];
double neuronb[1001];
double neuronc[1001];
double neurond[1001];
int neuroncount[1001];
vector<vector<Pulse>> pulses;

//struct Type{
//	double a, b, c, d;
//};

//struct Source{
//	int r;
//};

struct Synapse{
//	int s;
	int t;
	double w;
	int D;
	bool operator <(Synapse syn) {
		return this->D < syn.D;
	}
};

//unordered_map<int, Neuron> neurons;
//unordered_map<int, int> sources;
//unordered_map<int, Type> types;
//unordered_map<int, Synapse> syns;
vector<vector<int>> edges;
//vector<Neuron> neurons;
//Neuron neurons[1001];
//vector<int> sources;
int sources[1001];
//vector<Type> types;
//vector<Synapse> syns;
Synapse syns[1001];

static unsigned long nextrand = 1;

int myrand() {
    nextrand = nextrand * 1103515245 + 12345;
    return ((unsigned)(nextrand / 65536) % 32768);
}

int main() {
//		freopen("stdin.txt", "r", stdin);
//	ios::sync_with_stdio(false);
	int N, S, P, T;
//	cin >> N >> S >> P >> T;
	scanf("%d %d %d %d", &N, &S, &P, &T);
//		cout << N << ' ' << S << ' ' << P << ' ' << T << endl;
	edges.resize(N + P + 10);
//	neurons.resize(N);
//	sources.resize(P);
//	syns.resize(S);
//	edges.resize(999999);
	pulses.resize(N);
	int NN = N;
//	int PP = P;
//	int SS = S;
	double deltat;
//	cin >> deltat;
	scanf("%lf", &deltat);
//		cout << deltat << endl;
	int rn;
	double v, u, a, b, c, d;
//	int typei = 0;
	int neuroni = 0;
//	cout << "������Ԫ\n";
	while (NN > 0) {
//		cin >> rn >> v >> u >> a >> b >> c >> d;
		scanf("%d %lf %lf %lf %lf %lf %lf", &rn, &v, &u, &a, &b, &c, &d);
//			cout << rn << ' ' << v << ' ' << u << ' ' << a << ' ' << b << ' ' << c << ' ' << d << endl;
		NN -= rn;
//		types[typei] = Type{a, b, c, d};
//		types.insert({typei, Type{a, b, c, d}});
//		types.emplace_back(Type{a, b, c, d});
//		cout << typei << "��������Ԫ\n";
		while (rn > 0) {
			neuronv[neuroni] = v;
			neuronu[neuroni] = u;
			neurona[neuroni] = a;
			neuronb[neuroni] = b;
			neuronc[neuroni] = c;
			neurond[neuroni] = d;
//			neurons[neuroni] = Neuron{v, u, a, b, c, d, 0, vector<Pulse>()};
//			neurons.insert({neuroni, Neuron{typei, v, u, vector<Pulse>(), 0}});
//			neurons.emplace_back(Neuron{v, u, a, b, c, d, 0, vector<Pulse>()});
			neuroni++;
			rn--;
		}
//		typei++;
	}
	int r;
//	int sourcei = 0;
//		cout << "��������Դ\n";
//	for (auto it = sources.begin(); it != sources.end(); it++) {
//		cout << it->first << ' ' << it->second << endl;
//	}
//		cout << "��������Դ\n";
//	while (PP > 0) {
	for (int sourcei = 0; sourcei < P; sourcei++) {
//		cout << "����1\n";
//		cin.clear();
//		cin >> r;
		scanf("%d", &r);
//		sources.emplace_back(r);
//		cout << "����2\n";
//		sources.insert(pair<int, int>(sourcei, r));
//		cout << "����3\n";
//		PP--;
//		cout << "����" << sourcei << "rֵ" << r << endl;
		sources[sourcei] = r;
//		cout << sources[sourcei] << endl;
//		sourcei++;
	}
	int s, t, D;
	double w;
	int syni = 0;
//		cout << "����ͻ��\n";
//	while (SS > 0) {
	for (int syni = 0; syni < S; syni++) {
//		SS--;
//		cin >> s >> t >> w >> D;
		scanf("%d %d %lf %d", &s, &t, &w, &D);
//		syns.emplace_back(Synapse{t, w, D});
//		printf("%d %d %lf %d", s, t, w, D);
		syns[syni] = Synapse{t, w, D};
//		syns.insert({syni, Synapse{s, t, w, D}});
		edges[s].emplace_back(syni);
//		syni++;
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
//	int TT = 1;
	while (T > 0) {
//		cout << TT << "ʱ��\n";
//		TT++;
		T--;
//		for (auto it = neurons.begin(); it != neurons.end(); it++) {
		for (int it = 0; it < N; it++) {
//			Neuron &neurontemp = it->second;
//			Neuron &neurontemp = neurons[it];
//			double prev = neurontemp.v;
//			double preu = neurontemp.u;
			double prev = neuronv[it];
			double preu = neuronu[it];
			double I = 0;
//			cout << it << "����Ԫ\n";
//			for (auto it2 = neurontemp.pulses.begin(); it2 != neurontemp.pulses.end();) {
			for (auto it2 = pulses[it].begin(); it2 != pulses[it].end();) {
				it2->D -= 1;
//				cout << "����ǿ�ȣ�" << it2->I << ' ';
//				cout << "�����ӳ٣�" << it2->D << endl;
				if (it2->D == 0) {
					I += it2->I;
//					cout << "���I=" << I << endl;
					pulses[it].erase(it2);
				}
				else {
//					cout << "δ����\n";
					it2++;
				}
//				cout << "" << endl;
			}
//			cout << "ǿ��" << I << endl;
			neuronv[it] = prev+deltat*(0.04*prev*prev+5*prev+140-preu)+I;
//			-70+0.1*(0.04*(-70)*(-70)+5*(-70)+140-(-14))
//			Type &typetemp = types[neurontemp.type];
//			a = typetemp.a;
//			b = typetemp.b;
			neuronu[it] = preu+deltat*neurona[it]*(neuronb[it]*prev-preu);
//			cout << "vֵ��" << neurontemp.v << endl;
//			cout << "uֵ��" << neurontemp.u << endl;
//			cout << "" << endl;
		}
//		for (auto it = neurons.begin(); it != neurons.end(); it++) {
		for (int it = 0; it < N; it++) {
//			Neuron &neurontemp = it->second;
//			Neuron &neurontemp = neurons[it];
//			Type &typetemp = types[neurontemp.type];
			if (neuronv[it] >= 30) {
//				cout << "����30����\n";
//				int v1 = it->first;
				neuronv[it] = neuronc[it];
				neuronu[it] += neurond[it];
				for (int syni: edges[it]) {
					Synapse syntemp = syns[syni];
//					Neuron &neurontemp2 = neurons[syntemp.t];
//					neurontemp2.pulses.emplace_back(Pulse{syntemp.w, syntemp.D});
					pulses[syntemp.t].emplace_back(Pulse{syntemp.w, syntemp.D});
//					cout << "���ݵ���Ԫ" << syntemp.t << endl;
//					cout << "����Ԫ���壺\n";
//					for (auto i: neurontemp2.pulses) {
//						cout << i.I <<  ' ' << i.D << endl;
//					}
				}
				neuroncount[it] += 1;
//				cout << "�����ܴ���" << neurontemp.count << endl;
//				cout << "vֵ�ı䣺" << neurontemp.v << endl;
//				cout << "uֵ�ı䣺" << neurontemp.u << endl;
			}
//			else {
//				cout << "������\n";
//			}
//			cout << "" << endl;
		}
		for (int sourcei = 0; sourcei < P; sourcei++) {
			int rand = myrand();
			r = sources[sourcei];
//			cout << "����Դ" << sourcei + N << ' ';
//			cout << "rֵ" << r << ' ';
//			cout << "rand��" << rand << endl;
			if (r > rand) {
//				cout << "����\n";
				for (int syni: edges[sourcei + N]) {
					Synapse &syntemp = syns[syni];
//					cout << "1\n";
//					Neuron &neurontemp2 = neurons[syntemp.t];
//					cout << "2\n";
//					neurontemp2.pulses.emplace_back(Pulse{syntemp.w, syntemp.D});
					pulses[syntemp.t].emplace_back(Pulse{syntemp.w, syntemp.D});
//					cout << "3\n";
//					cout << "���ݵ���Ԫ" <<syntemp.t << ' ';
//					cout << "����Ԫ���壺\n";
//					for (auto i: neurontemp2.pulses) {
//						cout << i.I <<  ' ' << i.D << endl;
//					}
				}
			}
//			else {
//				cout << "������\n";
//			}
//			cout << "" << endl;
		}
	}
//	Neuron &neurontemp = neurons[0];
	double minv = neuronv[0], maxv = neuronv[0];
	int mincount = neuroncount[0], maxcount = neuroncount[0];
//	for (auto it = neurons.begin(); it != neurons.end(); it++) {
//		Neuron &neurontemp = it->second;
	for (int it = 1; it < N; it++) {
//		Neuron &neurontemp = neurons[it];
		minv = min(minv, neuronv[it]);
		maxv = max(maxv, neuronv[it]);
		mincount = min(mincount, neuroncount[it]);
		maxcount = max(maxcount, neuroncount[it]);
	}
//	printf("%lf %lf\n%d %d\n", minv, maxv, mincount, maxcount);
	printf("%.3lf %.3lf\n%d %d\n", minv, maxv, mincount, maxcount);
//	cout << mincount << ' ' << maxcount << endl;
//1 1 1 10
//0.1
//1 -70.0 -14.0 0.02 0.2 -65.0 2.0
//30000
//1 0 30.0 2
	return 0;
}
