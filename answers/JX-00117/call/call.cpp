#include<cstdio>
struct Func{
	int t;
	int p,q;
}func[100100];
int list[1000100];
int a[100100];
int read() {
	int v;
	scanf("%d", &v);
	return v;
}
int n;
#define MOD 998244353
inline void add(int i, int d) {
	a[i] = ((long long) a[i] + d) % MOD;
}
void multi(int d) {
	for (int i = 1;i <= n;i++) {
		a[i] = ((long long)a[i] * d) % MOD;
	}
}
void apply(int id) {
	switch(func[id].t) {
		case 1:
			add(func[id].p, func[id].q);
			break;
		case 2:
			multi(func[id].p);
			break;
		case 3:
			for (int i = func[id].p;i < func[id].q;i++) {
				apply(list[i]);
			}
	}
}
int main() {
	freopen("call.in", "r", stdin);
	freopen("call.out", "w", stdout);
	n = read();
	for (int i = 1;i <= n;i++) {
		a[i] = read();
	}
	int m = read();
	int alloc = 0;
	for (int i = 1;i <= m;i++) {
		func[i].t = read();
		switch(func[i].t) {
			case 1:
				func[i].p = read();
				func[i].q = read();
				break;
			case 2:
				func[i].p = read();
				break;
			case 3:
				func[i].p = alloc;
				func[i].q = alloc = alloc + read();
				for(int j = func[i].p;j < alloc;j++) {
					list[j] = read();
				}
		}
	}
	int q = read();
	for (int i = 0;i < q;i++) {
		apply(read());
	}
	for (int i = 1;i <= n;i++) {
		printf("%d ", a[i]);
	}
	return 0;
}
