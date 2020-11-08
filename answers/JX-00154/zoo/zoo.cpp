#include <cstdio>

#define ULL unsigned long long

template <class T> inline void Read(T &n) { n = 0; char ch; bool f = false; do if ((ch = getchar()) == '-') f = true; while (ch < '0' || ch > '9'); while ('0' <= ch && ch <= '9') { n = (n << 1) + (n << 3) + ch - '0'; ch = getchar(); } if (f) n = -n; }

int n, m, c, K;
ULL a;
ULL lmt;
ULL vis;
ULL req;

int main()
{
	freopen("zoo.in", "r", stdin);
	freopen("zoo.out", "w", stdout);
	Read(n); Read(m); Read(c); Read(K);
	lmt = (1 << K) - 1;
	for (int i = 1; i <= n; ++i) {
		Read(a);
		vis |= a;
	}
	for (int i = 1; i <= m; ++i) {
		int p, q;
		Read(p); Read(q);
		req |= (1 << p);
	}
	req ^= (req & vis);
	ULL ans = 1;
	for (int i = 1; i <= K; ++i) {
		if (!(req & 1))
			ans <<= 1;
		req >>= 1;
	}
	printf("%lld\n", ans - n);
	return 0;
}
