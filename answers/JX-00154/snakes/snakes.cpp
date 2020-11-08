#include <cstdio>
#include <set>

#define SET std::set<Node>

template <class T> inline void Read(T &n) { n = 0; char ch; bool f = false; do if ((ch = getchar()) == '-') f = true; while (ch < '0' || ch > '9'); while ('0' <= ch && ch <= '9') { n = (n << 1) + (n << 3) + ch - '0'; ch = getchar(); } if (f) n = -n; }

int a[1000005];

struct Node {
	int val, pos;
	friend bool operator< (const Node &a, const Node &b) {
		if (a.val != b.val)
			return a.val < b.val;
		return a.pos < b.pos;
	}
};

int n;
SET set;

int Solve() {
	int ret = n;
	SET set = ::set;
	while (true) {
		if (set.size() == 2)
			return --ret;
		SET::iterator beg = set.begin();
		Node min = *beg, max = *set.rbegin();
		++beg;
		max.val -= min.val;
		if (max < *beg)
			break;
		set.erase(set.begin());
		set.erase(*set.rbegin());
		set.insert(max);
		--ret;
		/*
		for (SET::iterator it = set.begin(); it != set.end(); ++it) {
			printf("%d ", it->val);
		}
		*/
	}
	return ret;
}

int main()
{
	freopen("snakes.in", "r", stdin);
	freopen("snakes.out", "w", stdout);
	int T;
	scanf("%d", &T);
	Read(n);
	for (int i = 1; i <= n; ++i) {
		Read(a[i]);
		set.insert((Node){a[i], i});
	}
	int ans = Solve();
	if (!(ans & 1))
		--ans;
	printf("%d\n", ans);

	while (--T) {
		int k;
		Read(k);
		for (int i = 1; i <= k; ++i) {
			int x, y;
			Read(x); Read(y);
			set.erase((Node){a[x], x});
			a[x] = y;
			set.insert((Node){y, x});
		}
		int ans = Solve();
		if (!(ans & 1))
			--ans;
		printf("%d\n", ans);
	}
	return 0;
}
