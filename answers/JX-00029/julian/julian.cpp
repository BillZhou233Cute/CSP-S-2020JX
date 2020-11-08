#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int q;
long long n;
int main() {
	freopen("julian.in", "r", stdin);
	freopen("julian.out", "w", stdout);
	scanf("%d", &q);
	for (int i  = 0; i < q; i++) {
		int now1 = 4713;
		int now2 = 1;
		int now3 = 1;
		scanf("%lld", &n);
		while (n >= 366) {
			if ( (now1- 1) % 4 == 0) n -= 366;
			else n -= 365;
			now1--;
		}
		if (n == 365 && (now1 - 1) % 4 != 0) {n -= 365 ; now1--;} 
		while (n >= 31) {
			if (now2 == 1 || now2 == 3 || now2 == 5 ||
				now2 == 7 || now2 == 8 || now2 == 10 ||
				now2 == 12) n -= 31;
			else if (now2 == 2) {
				if ((now1 - 1) % 4 == 0) n -= 29;
				else n -= 28;
			} else n-= 30;
			now2++;
		}
	   	if (n == 30) {
			if  (!(now2 == 1 || now2 == 3 || now2 == 5 ||
				now2 == 7 || now2 == 8 || now2 == 10 ||
				now2 == 12)) n -= 30, now2++;
		} else if (n == 29) {
			if (now2 == 2) {
				if ((now1 - 1) == 0) n -= 29;
				else n -= 28;
				now2++;
			}
		} else if (n == 28) {
			if (now2 == 2 && (now1 - 1) % 4 != 0) {
				n -= 28;
				now2++;
			}
		}
		now3 += n;
		printf("%d %d", now3, now2);
		if (now1 <= 0) printf(" %d\n", abs(now1)+1);
		else printf(" %d BC\n", now1);
	}
	return 0;
}