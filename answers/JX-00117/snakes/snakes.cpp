#include<cstdio>
int read() {
	int v;
	scanf("%d", &v);
	return v;
}
int ori[1001000];
struct Snake{
	int g;
	int i;
} s[1001000];
int n;
bool check(int h, int i, int g) {
	if (h+1 == n) {
		return 0;
	}
	for (int j = n - 1;j >= h && s[j].g >= g;j--) {
		if ((s[j].g > g) || (s[j].g == g && s[j].i > i)) {
			return 0;
		}
	}
	return 1;
}
void swap(int &a, int &b) {
	int c = a;
	a = b;
	b = c;
}
void solve() {
	for (int i = 1;i <= n;i++) {
		s[i].i = i;
		s[i].g = ori[i];
		//printf("%d ", ori[i]);
	}
	//puts("");
	int h = 1;//head
	//puts("copy");
	while (check(h, s[n].i, s[n].g - s[h].g)) {
		//puts("body");
		s[n].g -= s[h].g;
		h++;
		for (int i = n - 1;i >= h;i--) {
			if (s[i + 1].g < s[i].g) {
				//puts("Swap");
				swap(s[i + 1].g, s[i].g);
				swap(s[i + 1].i, s[i].i);
			}
		}
	}
	printf("%d\n", n - h + 1);
}
int main() {
	freopen("snakes.in", "r", stdin);
	freopen("snakes.out", "w", stdout);
	int t = read() - 1;
	n = read();
	for (int i = 1;i <= n;i++) {
		ori[i] = read();
	}
	solve();
	while (t--) {
		int k = read();
		while(k--) {
			ori[read()] = read();
		}
		solve();
	}
	return 0;
}
