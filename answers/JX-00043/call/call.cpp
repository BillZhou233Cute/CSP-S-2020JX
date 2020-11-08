#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdlib>

const int N = 100001;
const int P = 998244353;

inline int read() {
	int x = 0, f = 1; char ch = getchar();
	while(ch > '9' || ch < '0') { if(ch == '-') f = -1; ch = getchar(); }
	while(ch >= '0' && ch <= '9') x = x * 10 + ch - 48, ch = getchar();
	return x * f;
}

int n,a[N],m,t[N],p[N],v[N];
std::vector <int> g[N];

void Call(int i) {
	if(t[i] == 1) a[p[i]] = (a[p[i]] + v[i]) % P;
	else if(t[i] == 2)
		for(int j = 1;j <= n;j++) a[j] = 1ll * a[j] * v[i] % P;
	else {
		for(int j = 0;j < p[i];j++)
			Call(g[i][j]);
	}
}

int main() {
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	n = read();
	for(int i = 1;i <= n;i++) a[i] = read();
	m = read();
	for(int i = 1;i <= m;i++) {
		t[i] = read();
		if(t[i] == 1) p[i] = read(), v[i] = read();
		if(t[i] == 2) v[i] = read();
		if(t[i] == 3) {
			p[i] = read();
			for(int j = 1;j <= p[i];j++) g[i].push_back(read());
		}
	}
	int Q = read();
	while(Q--) {
		int i = read();
		Call(i);
	}
	for(int i = 1;i <= n;i++) std::printf("%d ",a[i]);
	std::puts("");
	return 0;
}
