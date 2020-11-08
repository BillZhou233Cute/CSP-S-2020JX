#include <cstdio>
#include <vector>

#define LL long long
#define VEC std::vector<int>
#define int LL

template <class T> inline void Read(T &n) { n = 0; char ch; bool f = false; do if ((ch = getchar()) == '-') f = true; while (ch < '0' || ch > '9'); while ('0' <= ch && ch <= '9') { n = (n << 1) + (n << 3) + ch - '0'; ch = getchar(); } if (f) n = -n; }

struct Func {
	int op;  // 0f 1mult 2plus
	int pos;
	int val;
	VEC f;
};

struct Node {
	int sum;
	int mult;
};

int n, m;
int a[100005];
Func f[100005];
Node t[400005];

/*
LL Mult(LL a, LL b, LL mod) {
	LL ret = 0;
	while (b) {
		if (b & 1) {
			ret = ret + a;
			if (ret > mod)
				ret -= mod;
		}
		a = a << 1;
		if (a > mod)
			a -= mod;
		b >>= 1;
	}
	return ret;
}
*/

void Build(int pos, int l, int r) {
	if (l == r) {
		t[pos] = (Node){a[l], 1};
		return;
	}
	int mid = (l + r) >> 1;
	int ls = pos << 1;
	int rs = ls | 1;
	Build(ls, l, mid);
	Build(rs, mid + 1, r);
	t[pos] = (Node){t[ls].sum + t[rs].sum, 1};
}

void Add(int pos, int l, int r, int to, int val) {
	if (l == r) {
		t[pos].sum = ((LL)t[pos].sum * t[pos].mult + val) % 998244353;
		t[pos].mult = 1;
		return;
	}
	int mid = (l + r) >> 1;
	int ls = pos << 1;
	int rs = ls | 1;
	// t[pos].sum = Mult(t[pos].sum, t[pos].mult, 998244353);
	// t[pos].sum = (t[pos].sum + val) % 998244353;
	t[pos].sum = ((LL)t[pos].sum * t[pos].mult + val) % 998244353;
	// t[ls].mult = Mult(t[ls].mult, t[pos].mult, 998244353);
	t[ls].mult = (LL)t[ls].mult * t[pos].mult % 998244353;
	// t[rs].mult = Mult(t[rs].mult, t[pos].mult, 998244353);
	t[rs].mult = (LL)t[rs].mult * t[pos].mult % 998244353;
	t[pos].mult = 1;
	if (to <= mid)
		Add(ls, l, mid, to, val);
	else
		Add(rs, mid + 1, r, to, val);
}

int Ask(int pos, int l, int r, int to) {
	if (l == r) {
		t[pos].sum = ((LL)t[pos].sum * t[pos].mult) % 998244353;
		t[pos].mult = 1;
		return t[pos].sum;
	}
	int mid = (l + r) >> 1;
	int ls = pos << 1;
	int rs = ls | 1;
	// t[pos].sum = Mult(t[pos].sum, t[pos].mult, 998244353);
	// t[pos].sum = ((LL)t[pos].sum * t[pos].mult + val) % 998244353;
	// t[ls].mult = Mult(t[ls].mult, t[pos].mult, 998244353);
	// t[ls].mult = (LL)t[ls].mult * t[pos].mult % 998244353;
	// t[rs].mult = Mult(t[rs].mult, t[pos].mult, 998244353);
	// t[rs].mult = (LL)t[rs].mult * t[pos].mult % 998244353;
	t[pos].sum = ((LL)t[pos].sum * t[pos].mult) % 998244353;
	t[ls].mult = (LL)t[ls].mult * t[pos].mult % 998244353;
	t[rs].mult = (LL)t[rs].mult * t[pos].mult % 998244353;
	t[pos].mult = 1;
	if (to <= mid)
		return Ask(ls, l, mid, to);
	return Ask(rs, mid + 1, r, to);
}

void Call(int pos) {
	// printf("Called %d\n", pos);
	Func &now = f[pos];
	if (now.op == 1) {
		Add(1, 1, n, now.pos, now.val);
	} else if (now.op == 2) {
		// t[1].mult = Mult(t[1].mult, now.val, 998244353);
		t[1].mult = (t[1].mult * now.val) % 998244353;
	} else {
		for (VEC::iterator it = now.f.begin(); it != now.f.end(); ++it)
			Call(*it);
	}
	/*
	for (int i = 1; i <= n; ++i)
		printf("%d ", Ask(1, 1, n, i));
	puts("");
	for (int i = 1; i <= (n << 2); ++i) {
		printf("%d %d\n", t[i].sum, t[i].mult);
	}
	puts("");
	*/
}

signed main()
{
	freopen("call.in", "r", stdin);
	freopen("call.out", "w", stdout);
	Read(n);
	for (int i = 1; i <= n; ++i)
		Read(a[i]);
	Build(1, 1, n);
	Read(m);
	for (int i = 1; i <= m; ++i) {
		Read(f[i].op);
		if (f[i].op == 1) {
			Read(f[i].pos);
			Read(f[i].val);
		} else if (f[i].op == 2) {
			Read(f[i].val);
		} else {
			int foo;
			Read(foo);
			int bar;
			for (int j = 1; j <= foo; ++j) {
				Read(bar);
				f[i].f.push_back(bar);
			}
		}
	}
	int q;
	Read(q);
	for (int i = 1; i <= q; ++i) {
		int foo;
		Read(foo);
		Call(foo);
	}
	for (int i = 1; i <= n; ++i)
		printf("%lld ", Ask(1, 1, n, i));
	puts("");
	return 0;
}
