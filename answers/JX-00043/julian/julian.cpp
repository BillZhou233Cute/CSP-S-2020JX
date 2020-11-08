#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdlib>

typedef long long ll;
const int Q = 100001;

inline ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch > '9' || ch < '0') { if(ch == '-') f = -1; ch = getchar(); }
	while(ch >= '0' && ch <= '9') x = x * 10 + ch - 48, ch = getchar();
	return x * f;
}

int mon[13] = {0,31,0,31,30,31,30,31,31,30,31,30,31};
struct Date {
	ll y, m, d;
	Date() {}
	Date(ll _y, ll  _m, ll _d) :
		y(_y), m(_m), d(_d) {}
	friend bool operator <(const Date &x,const Date &y) {
		if(x.y != y.y) return x.y < y.y;
		if(x.m != y.m) return x.m < y.m;
		return x.d < y.d;
	}
	friend bool operator ==(const Date &x,const Date &y) {
		return x.y == y.y && x.m == y.m && x.d == y.d;
	}
	friend bool operator <=(const Date &x,const Date &y) {
		return x < y || x == y;
	}
	int Run1() {
		ll Y = y; if(y < 0) Y++;
		Y = (Y % 400 + 400) % 400;
		return !(Y % 4);
	}
	int Run2() {
		ll Y = y; if(y < 0) Y++;
		Y = (Y % 400 + 400) % 400;
		return !(Y % 400) || (!(Y % 4) && Y % 100);
	}
	int Month1() {
		if(m != 2) return mon[m];
		if(Run1()) return 29;
		else return 28;
	}
	int Month2() {
		if(m != 2) return mon[m];
		if(Run2()) return 29;
		else return 28;
	}
	void NextDay() {
		if(*this < Date(1582,10,4)) {
			d++;
			if(d > Month1()) d = 1, m++;
			if(m > 12) {
				m = 1;
				if(y == -1) y = 1;
				else y++;
			}
		} else if(*this == Date(1582,10,4)) {
			*this = Date(1582,10,15);
		} else {
			d++;
			if(d > Month2()) d = 1, m++;
			if(m > 12) {
				m = 1;
				if(y == -1) y = 1;
				else y++;
			}
		}
	}
	void print() {
		if(y < 0) std::printf("%lld %lld %lld BC\n",d,m,-y);
		else std::printf("%lld %lld %lld\n",d,m,y);
	}
};

void AddY(ll &y,ll d) {
	ll p = y; y += d;
	if(p < 0 && y >= 0) y++;
}
void Solve1(Date now,ll r) {
	const int L = 365 * 4 + 1;
	AddY(now.y,r / L * 4);
	r %= L;
	while(r >= 366) {
		if((now.Run1() && Date(0,now.m,now.d) <= Date(0,2,29)) ||
		   (Date(now.y + 1,now.m,now.d).Run1() && Date(0,2,29) < Date(0,now.m,now.d))) r -= 366;
		else r -= 365;
		AddY(now.y,1);
	}
	while(r--) now.NextDay();
	now.print();
}

void Solve2(Date now,ll r) {
	const int L = (365 * 4 + 1) * 100 - 3;
	AddY(now.y,r / L * 400);
	r %= L;
	while(r >= 366) {
		if((now.Run2() && Date(0,now.m,now.d) <= Date(0,2,29)) ||
		   (Date(now.y + 1,now.m,now.d).Run2() && Date(0,2,29) < Date(0,now.m,now.d))) r -= 366;
		else r -= 365;
		AddY(now.y,1);
	}
	while(r--) now.NextDay();
	now.print();
}

int main() {
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	int q = read();
	while(q--) {
		ll r = read();
		if(r <= 2299160) Solve1(Date(-4713,1,1),r);
		else Solve2(Date(1582,10,15),r - 2299161);
	}
	return 0;
}
