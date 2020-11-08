#include <cstdio>

using namespace std;

int T, n, a[1000005], k;

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

void dfs() {

}

void manipulate() {
	
}

int findMax() {
	int n = 0;
	int max = -1;
	for (int i = 1; i <= n; i++) {
		if (a[i] > a[n]) {
			n = i;
			max = a[i]; 
		} else if (a[i] == a[n]) {
			if (i > n) {
				n = i;
			}
		}
	}
	return n;
}

int findMin() {
	int n = 0;
	int min = 900000000;
	for (int i = 1; i <= n; i++) {
		if (a[i] < a[n]) {
			n = i;
			min = a[i]; 
		} else if (a[i] == a[n]) {
			if (i < n) {
				n = i;
			}
		}
	}
	return n;
}

int max(int a, int b) {
	return (a >= b) a : b;
}

int min(int a, int b) {
	return (a <= b) a : b;
}


int main(void) {

	freopen("snakes.in", "r", stdin);
	freopen("snakes.out", "w", stdout);
	
	T = read();
	for (int i = 1; i <= T; i++) {
		if (i == 1) {
			n = read();
			for (int j = 1; j <= n; j++) {
				a[j] = read();
			}
			printf("%d", n);
		} else {
			k = read();
			for (int j = 1; j <= k; j++) {
				int x = read();
				int y = read();
				a[x] = y;
			}
			printf("%d", n-1);
		}
	}

}
