#include <iostream>
#include <cstdio>
using namespace std;

int n, m, a[10005];

struct Fun {
	int op, p, v;
	int a[10005];
} fun[10005];

int main() {
	freopen("call.in", "r", stdin);
	freopen("call.out", "w", stdout);
	
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	scanf("%d", &m);
	
	for (int i = 1; i <= m; i++) {
		int op, p, v;
		scanf("%d", &op);
		if (op == 1) {
			scanf("%d %d", &fun[i].p, &fun[i].v);
			fun[i].op = 1;
		} else if (op == 2) {
			scanf("%d", &fun[i].v);
			fun[i].op = 2;
		} else {
			for (int j = 1; j <= m; j++) {
				scanf("%d", &fun[i].a[j]);
			}
			fun[i].op = 3;
		}
	}
	
	int q;
	scanf("%d", &q);
	for (int i = 1; i <= n; i++) {
		int call;
		scanf("%d", &call);
		if (fun[i].op == 1) {
			a[fun[i].p] += fun[i].v;
		} else if (fun[i].op == 2) {
			for (int j = 1; j <= n; j++) {
				a[j] *= fun[i].v;
			}
		} else {
			if (fun[i].op == 1) {
			a[fun[i].p] += fun[i].v;
		} else if (fun[i].op == 2) {
			for (int j = 1; j <= n; j++) {
				a[j] *= fun[i].v;
			}
		}
	}
	}
	
	for (int i = 1; i <= n; i++) {
		printf("%d ", a[i]);
	}
	
	return 0;
}
