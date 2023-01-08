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
		freopen("stdin2.txt", "r", stdin);
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
//	cout << "输入神经元\n";
	while (NN > 0) {
		cin >> rn >> v >> u >> a >> b >> c >> d;
//		scanf("%d %lf %lf %lf %lf %lf %lf", &rn, &v, &u, &a, &b, &c, &d);
//			cout << rn << ' ' << v << ' ' << u << ' ' << a << ' ' << b << ' ' << c << ' ' << d << endl;
		NN -= rn;
//		types[typei] = Type{a, b, c, d};
		types.insert({typei, Type{a, b, c, d}});
//		cout << typei << "次输入神经元\n";
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
//		cout << "输入脉冲源\n";
//	for (auto it = sources.begin(); it != sources.end(); it++) {
//		cout << it->first << ' ' << it->second << endl;
//	}
//		cout << "输入脉冲源\n";
	while (PP > 0) {
//		cout << "插入1\n";
//		cin.clear();
		cin >> r;
//		scanf("%d", &r);
//		cout << "插入2\n";
		sources.insert(pair<int, int>(sourcei, r));
//		cout << "插入3\n";
		PP--;
//		cout << "脉冲" << sourcei << "r值" << r << endl;
//		sources[sourcei] = r;
//		cout << sources[sourcei] << endl;
		sourcei++;
	}
	int s, t, D;
	double w;
	int syni = 1;
//		cout << "输入突触\n";
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
//		cout << i << "：";
//		for (int ii = 0; ii < edges[i].size(); ii++) {
//			cout << edges[i][ii] << ' ';
//		}
//		cout << endl;
//	}
//	cout << "开始模拟\n";
//	int TT = 1; 
	while (T > 0) {
//		cout << TT << "时刻\n";
//		TT++;
		T--;
		for (sourcei = N; sourcei <= N + P - 1; sourcei++) {
			int rand = myrand();
			r = sources[sourcei];
//			cout << "脉冲" << sourcei;
//			cout << "r值" << r << endl;
//			cout << "rand：" << rand << endl;
			if (r > rand) {
//				cout << "发放\n";
				for (int syni: edges[sourcei]) {
					Synapse &syntemp = syns[syni];
					Neuron &neurontemp = neurons[syntemp.t];
					neurontemp.pulses.emplace_back(Pulse{syntemp.w, syntemp.D});
//					cout << "传递到神经元" <<syntemp.t << endl;
//					cout << "该神经元脉冲：\n";
//					for (auto i: neurontemp.pulses) {
//						cout << i.intensity <<  ' ' << i.delay << endl;
//					}
				}
			}
			else {
//				cout << "不发放\n";
			}
		}
		for (auto it = neurons.begin(); it != neurons.end(); it++) {
			Neuron &neurontemp = it->second;
			v = neurontemp.v;
			u = neurontemp.u;
			double I = 0;
//			cout << it->first << "号神经元\n";
			for (auto it2 = neurontemp.pulses.begin(); it2 != neurontemp.pulses.end();) {
//				cout << it->first << "脉冲延迟：" << it2->delay << endl;
				if (it2->delay == 0) {
//					cout << "到达，I=" << I << endl;
					I += it2->intensity;
					neurontemp.pulses.erase(it2);
				}
				else {
//					cout << "未到达\n";
					it2->delay -= 1;
					it2++;
				}
			}
//			cout << "强度" << I << endl;
			v = v+deltat*(0.04*v*v+5*v+140-u)+I;
//			-70+0.1*(0.04*(-70)*(-70)+5*(-70)+140-(-14))
			Type &typetemp = types[neurontemp.type];
			a = typetemp.a;
			b = typetemp.b;
			neurontemp.u = u+deltat*a*(b*v-u);
			neurontemp.v = v;
//			cout << "v值：" << neurontemp.v << endl;
//			cout << "u值：" << neurontemp.u << endl;
			if (v >= 30) {
//				cout << "大于30发放\n";
				int v1 = it->first;
				neurontemp.v = typetemp.c;
				neurontemp.u += typetemp.d;
				for (int syni: edges[v1]) {
					Synapse syntemp = syns[syni];
					Neuron &neurontemp = neurons[syntemp.t];
					neurontemp.pulses.emplace_back(Pulse{syntemp.w, syntemp.D - 1});
//					cout << "传递到神经元" <<syntemp.t << endl;
//					cout << "该神经元脉冲：\n";
//					for (auto i: neurontemp.pulses) {
//						cout << i.intensity <<  ' ' << i.delay << endl;
//					}
				}
				neurontemp.count += 1;
//				cout << "发放总次数" << neurontemp.count << endl; 
//				cout << "v值改变：" << neurontemp.v << endl;
//				cout << "u值改变：" << neurontemp.u << endl;
			}
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
	cout << minv << ' ' << maxv << endl << mincount << ' ' << maxcount;
//1 1 1 10
//0.1
//1 -70.0 -14.0 0.02 0.2 -65.0 2.0
//30000
//1 0 30.0 2
	return 0;
}
