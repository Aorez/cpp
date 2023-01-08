#include<bits/stdc++.h>
using namespace std;

vector<int> codes;
vector<int> codes2;

vector<vector<vector<int>>> mode_code = {{{},{27},{28}}, {{28,28},{},{28}}, {{28},{27},{}}};

int main() {
	ios::sync_with_stdio(false);
	int w, s;//每行码字数和校验级别
	cin >> w >> s;
	int k = (s == -1?0:pow(2, s + 1));
//	cout << k << endl;
	string str;
	cin >> str;
	int pre_mode = 0;//0大写1小写2数字 
	int now_mode;
	int strcode;
	for (auto stri: str) {
		if (stri >= 65 && stri <= 90) {
			now_mode = 0;
			strcode = stri - 65;
		}
		else if (stri >= 97 && stri <= 122) {
			now_mode = 1;
			strcode = stri - 97;
		}
		else {
			now_mode = 2;
			strcode = stri - 48;
		}
		codes.insert(codes.end(), mode_code[pre_mode][now_mode].begin(), mode_code[pre_mode][now_mode].end());
		codes.emplace_back(strcode);
		pre_mode = now_mode;
	}
	int n = codes.size();
	if (n % 2 == 1) {
		codes.emplace_back(29);
	}
	codes2.emplace_back(0);
	for (int i = 0; i < n; i += 2) {
		codes2.emplace_back(codes[i] * 30 + codes[i + 1]);
	}
	n = codes2.size();
	n = w - ((n + k) - (n + k) / w * w);
	codes2.insert(codes2.end(), n, 900);
	codes2[0] = codes2.size();
//	for (int i = 0; i < codes.size(); i++) {
//		cout << codes[i] << endl;
//	}
	for (int i = 0; i < codes2.size(); i++) {
		cout << codes2[i] << endl;
	}
//	5 -1 HELLO
//	4 0 HE1lo
	return 0;
}
