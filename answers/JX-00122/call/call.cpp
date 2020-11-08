#include <cstdio>

int n, a[100005], m, func[100005], t1p[100005], t1v[100005], t2v[100005], t3c[100005], t3g[100005][1005], Q;

int printAll() {
	for (int i = 1; i <= n; i++) {
		printf("%d ", a[i]);
	}
	putchar('\n');
}

int read() {
	int x = 0, w = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-') w = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = (x << 3) + (x << 1) + (ch - '0');
		ch = getchar();
	}
	return x * w;
}

void runFunc(int i) {
	int type = func[i];
	if (type == 1) {
		a[t1p[i]] += t1v[i];
		//printf("Add function\n");
		//printAll();
	} else if (type == 2) {
		for (int j = 1; j <= n; j++) {
			a[j] *= t2v[i];
		}
		//printf("Multi function\n");
		//printAll();
	} else if (type == 3) {
		for (int j = 1; j <= t3c[i]; j++) {
			runFunc(t3g[i][j]);
		}
		//printf("Call other function\n");
		//printAll();
	}
}

int main(void) {
	
	freopen("call.in", "r", stdin);
	freopen("call.out", "w", stdout);

	n = read();
	for (int i = 1; i <= n; i++) {
		a[i] = read();
	}
	m = read();
	for (int i = 1; i <= m; i++) {
		int type = read();
		func[i] = type;
		if (type == 1) {
			t1p[i] = read();
			t1v[i] = read();
		} else if (type == 2) {
			t2v[i] = read();
		} else if (type == 3) {
			t3c[i] = read();
			for (int j = 1; j <= t3c[i]; j++) {
				t3g[i][j] = read();
			}
		}
	}
	Q = read();
	for (int i = 1; i <= Q; i++) {
		int ff = read();
		runFunc(ff);
	}
	
	printAll();
	
}
