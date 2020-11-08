#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <iomanip>

typedef unsigned long long ull;
const int N = 1000001;
const int BIT = 64;

inline ull read() {
	ull x = 0; bool f = 1; char ch = getchar();
	while(ch > '9' || ch < '0') { if(ch == '-') f = -1; ch = getchar(); }
	while(ch >= '0' && ch <= '9') x = x * 10 + ch - 48, ch = getchar();
	return x * f;
}

int n,m,c,k,p[N],q[N],ocp[BIT];
ull a[N];

int main() {
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	n = read(), m = read(), c = read(), k = read();
	for(int i = 1;i <= n;i++) a[i] = read();
	for(int i = 1;i <= m;i++) p[i] = read(), q[i] = read(), ocp[p[i]] = true;
	long double ans = 1.0;
	for(int i = 0;i < k;i++) {
		int v = 0;
		for(int j = 1;j <= n;j++) v |= (a[j] >> i) & 1;
		if(v || (!v && !ocp[i])) ans *= 2.0;
	}
	std::cout << std::fixed << std::setprecision(0) << ans - n << std::endl;
	return 0;
}
