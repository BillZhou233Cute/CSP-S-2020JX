#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath> #include <algorithm>
#include <cstdlib>

const int N = 1000001;

inline int read() {
	int x = 0, f = 1; char ch = getchar();
	while(ch > '9' || ch < '0') { if(ch == '-') f = -1; ch = getchar(); }
	while(ch >= '0' && ch <= '9') x = x * 10 + ch - 48, ch = getchar();
	return x * f;
}

int n,a[N];

void Solve() {
	int ans = 0;
	if(a[3] - a[1] >= a[2]) ans = 1;
	else ans = 3;
	std::printf("%d\n",ans);
	return;
}

int main() {
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	int t = read();
	n = read();
	for(int i = 1;i <= n;i++) a[i] = read();
	Solve(), t--;
	while(t--) {
		int k = read();
		while(k--) {
			int x = read(), y = read();
			a[x] = y;
		}
		Solve();
	}
	return 0;
}
