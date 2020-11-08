#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
char In[1 << 20], *ss = In, *tt = In;
#define getchar() (ss == tt && (tt = (ss = In) + fread(In, 1, 1 << 20, stdin), ss == tt) ? EOF : *ss++)
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	for(; ch < '0' || ch > '9'; ch = getchar()) if(ch == '-') f = -1;
	for(; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + int(ch - '0');
	return x * f;

}
bool runnian(ll y) {
	if(y < 1582) {
		return y % 4 == 0;
	} else {
		return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
	}
}
struct Tim {
	ll y, d;
	ll getday(int m) {
		if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) return 31;
		else if(m == 0) return 0;
		else if(m != 2) return 30;
		else return runnian(y) ? 29 : 28;
	}
	void set(ll Y, ll M, ll D) {
		y = Y;
		d = D;
		for(int i = 1; i < M; i++) d += getday(i);
	}
	void print() {
		ll M = 0, D = d;
		while(1) {
			if(D > getday(M)) {
				D -= getday(M);
				M++;
			} else break;
		}
		printf("%lld %lld ", D, M);
		if(y > 0) printf("%lld\n", y);
		else printf("%lld BC\n", (-y+1));
	}
}st, fg;
ll fgr, r400year;
ll dist(Tim a, Tim b) {
	ll ans = 0;
	for(ll i = a.y; i < b.y; i++) {
		ans += runnian(i) ? 366 : 365;
	}
	ans += b.d - a.d;
	return ans;
}
Tim foll(ll r) {
	Tim ans = st;
	if(r <= fgr) {
		while(r) {
			ll t = runnian(ans.y) ? 366 : 365;
			if(r > t) {
				r -= t;
				ans.y++;
			} else {
				ans.d += r;
				if(ans.d > t) {
					ans.d -= t;
					ans.y++;
				}
				break;
			}
		}
	} else {
		r -= fgr;
		if(r == 0) {
			ans.set(1582, 10, 4);
		} else {
			ans.set(1582, 10, 15); r--;
			ans.y += r / r400year * 400ll; r %= r400year;
			while(r) {
				ll t = runnian(ans.y) ? 366 : 365;
				if(r > t) {
					r -= t;
					ans.y++;
				} else {
					ans.d += r;
					if(ans.d > t) {
						ans.d -= t;
						ans.y++;
					}
					break;
				}
			}
		}
	}
	return ans;
}

void work() {
	ll r = read();
	Tim a = foll(r);
	a.print();
}

int main() {
	freopen("julian.in", "r", stdin);
	freopen("julian.out", "w", stdout);
	st.set(-4712, 1, 1); fg.set(1582, 10, 4);
	fgr = dist(st, fg);
	Tim t1, t2;
	t1.set(2000, 1, 1); t2.set(2400, 1, 1);
	r400year = dist(t1, t2);
	int Q = read();
	while(Q--) work();
	return 0;
}
