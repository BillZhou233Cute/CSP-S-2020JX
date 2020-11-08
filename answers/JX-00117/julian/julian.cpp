#include<cstdio>
#include<iostream>
using std::cin;
#define ll long long
int max[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int get(ll y) {
	if (y <= 1582) {
		if (y <= 0) {
			return (y + 1) % 4 == 0;
		} else {
			return y % 4 == 0;
		}
	} else {
		return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
	}
}
int get(int y, int m) {
	return m == 2 ? (get(y) ? 29 : 28) : max[m];
}
int main() {
	freopen("julian.in", "r", stdin);
	freopen("julian.out", "w", stdout);
	int n;
	scanf("%d", &n);
	while (n--) {
		ll r;
		cin >> r;
		if (r < 1721424) {
			int y = -4713, m = 1, d = 1;
			for (int i = 0;i < r;i++) {
				if (d == get(y, m)) {
					d = 1;
					m++;
					if (m == 13) {
						y++;
						if (y == 0) {
							y++;
						}
						m = 1;
					}
				} else {
					d++;
				}
				if (y == 1582 && m == 10 && d == 5) {
					d = 15;
				}
			}
			if (y < 0) {
				printf("%d %d %d BC", d, m, -y);
			} else {
				printf("%d %d %d", d, m, y);
			}
			puts("");
		} else {
			r -= 1721424;
			ll y = 1, m = 1, d = 1;
			int dd;
			while (r >= (dd=(get(y) ? 366 : 365))) {
				y++;
				r -= dd;
			}
			while (r >= (dd = get(y, m))) {
				r -= dd;
				m ++;
			}
			if (y > 1582 || (y == 1582 && m > 10) || (y == 1582 && m == 10 && d >= 5)) {
				r += 10;
			}
			while (r >= (dd = get(y, m))) {
				r -= dd;
				m++;
			}
			printf("%lld %lld %lld\n", r+ 1,m,y);
		}
	}
	return 0;
}
