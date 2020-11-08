#include <iostream>
#include <cstdio>
#include <cstring>
typedef long long ll;

const int MAXN = 10e6 + 5;
int n, m, c, k;
ll powk = 1;
int a[MAXN], p[MAXN], q[MAXN], used[MAXN], siyang[MAXN];

void init_pow() {
	for (int i = 1; i <= k; i++)
		powk *= 2;
}

int main() {
	freopen("zoo.in", "r", stdin);
	freopen("zoo.out", "w", stdout);
	
	memset(a, 0, sizeof(a));
	memset(p, 0, sizeof(p));
	memset(q, 0, sizeof(q));
	memset(siyang, 0, sizeof(siyang));
	memset(used, 0, sizeof(used));
	scanf("%d %d %d %d", &n, &m, &c, &k);
	init_pow();
	
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		siyang[a[i]] = 1;
	}
	
	int cnt = 0;
	for (int j = 1; j <= m; j++) {
		scanf("%d %d", &p[j], &q[j]);
		
		for (int i = 1; i <= n; i++) {
			if ((a[i] >> p[j]) & 1) {
				if (!used[q[j]]) {
					used[q[j]] = 1;
					cnt++;
				}
			}
		}
	}
	
	ll tot = 0;
	for (int i = 0; i <= powk - 1; i++) {
		if (siyang[i]) continue;
		
		int flag = 1;
		for (int j = 1; j <= m; j++) {
			if ((i >> p[j]) & 1 && !used[q[j]]) {
				flag = 0;
				break;
			}
		}
		
		if (flag)
			tot++;
	}
	
	printf("%lld\n", tot);
	return 0;
}
