#include <algorithm>
#include <cstdio>
using namespace std;

const int L = 1e6+5;
int T, k, n, a[L], t1, t2, exist[L];

void solve() {
	int sum = 0;
	for (int i = 1; i < n; i++) sum += a[i];
		
	if (sum <= a[n]) {
		printf("1\n");
		return;
	} else if (a[n] - a[1] < a[2]) {
		printf("%d\n", n);
		return;
	} else {
		int minn = 1, maxn = n, smax = n-1, ans = 0;
		while (a[maxn] - a[minn] >= a[minn+1]) {
			//printf("round:%d  minn:%d   maxn:%d   smax:%d   \n", ans, minn, maxn, smax);
			ans++;
			a[maxn] -= a[minn];
			exist[minn] = 1;
			
			minn = n;
			maxn = 1;
			smax = 1;
			
			for (int i = 1; i <= n; i++) {
				if (exist[i] == 1) continue;
				if (a[i] < a[minn]) minn = i;
				if (a[i] >= a[maxn]) {
					smax = maxn;
					maxn = i;
				} else if (a[i] >= smax) smax = i;
			}
		}
		printf("%d\n", n-ans);
	}
}

int main() {
    freopen("snakes.in", "r", stdin);
    freopen("snakes.out", "w", stdout);
    
	scanf("%d", &T);
	T--;
	
	scanf("%d", &n);
	for (int i = 1; i <=n; i++) scanf("%d", &a[i]);
	solve();
	
	while (T--) {
		scanf("%d", &k);
		for (int i = 1; i <= k; i++) scanf("%d %d", &t1, &t2), a[t1] = t2;
		solve();
	}
	
    return 0;
}