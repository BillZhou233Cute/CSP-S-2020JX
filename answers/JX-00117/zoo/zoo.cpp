#include<cstdio>
#include<iostream>
#include<map>
using namespace std;
#define ull unsigned long long
ull read() {
	ull v;
	cin >> v;
	return v;
}
int main() {
	map<int, bool> rst;
	freopen("zoo.in", "r", stdin);
	freopen("zoo.out", "w", stdout);
	int n = read(),m = read(),c = read(),k = read();
	int bad = 0;
	ull usedBits=0, ai;
	for (int i = 0;i < n;i++) {
		ai = read();
		usedBits |= ai;
	}
	ull p, q;
	//cout << usedBits << endl;
	for (int i = 0;i < k;i++) {
		rst[i] = 0;
	}
	for (int i = 0;i < m;i++) {
		p = read();q = read();
		if ((usedBits & (1 << p)) == 0) {
			if (!rst[p]) {
				bad++;
			}
			rst[p] = 1;
		}
	}
	ull size = k - bad;
	//cout << bad << endl;
	//cout << size << endl;
	ull res = (1 << size) - n;
	cout << res;
	return 0;
}
