#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 1e6 + 10;
int n, m, c, k, q[N], idx;
bool st[100];
vector<int> s[100];
bool find(int x) {
	int l = 0, r = idx - 1;
	while (l < r) {
		int mid = l + r >> 1;
		if (q[mid] >= x) r = mid;
		else l = mid + 1;
	}
	return q[l] == x;
}
int main() {
	freopen("zoo.in", "r", stdin);
	freopen("zoo.out", "w", stdout);
	scanf("%d %d %d %d", &n, &m, &c, &k);
	for (int i = 0; i < n; i++) {
		long long a; int cnt = 0;
		scanf("%lld", &a);
		while (a) {
			if (a & 1) st[cnt] = 1;
			a >>= 1;
			cnt++;
		}
	}
	for (int i = 0; i < m; i++) {
		int p, a;
		scanf("%d %d", &p, &a);
		if (st[p]) q[idx++] = a;
		s[p].push_back(a);
	}
	sort(q, q + idx);
	long long ans = 0;
	for (int i  = k - 1; i >= 0; i--) {
		int flag = 1;
		for (int j = 0; j < s[i].size(); j++)
			if (!find(s[i][j])) {
				flag = 0;
				break;
			}
		if (flag) {
		    if (!ans) ans = 2;
			else ans *= 2;
		}	
	}
	printf("%lld\n", ans - n);
	return 0;
}