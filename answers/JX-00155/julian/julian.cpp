#include <iostream>
#include <cstdio>
using namespace std;

const int Bc = 1721424;
const int Ge = 577736;
const int y4 = 1461;
const int y100 = 36524;
const int y400 = 146097;
const int month[20] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int Q, n;
int a = 0, b = 0, c = 0;

void reset()
{
	a =0 ;
	b =0;
	c = 0;
}

void Jug(bool run)
{
	int cache = 0;
	for (int i = 1; i < 12; ++i) {
		cache = month[i];
		if (i == 2 && run) cache = 29;
		
		if (c >= cache) {
			c -= cache;
			b ++;
		}
		else return ;
	}
}

void s_j()
{
	if (n <= 16) {
		b = 10;
		c = 15 + n;
		return ;
	}
	n -= 16;
	if (n <= 30) {
		b = 11;
		c = n;
		return ;
	}
	n -= 30;
	b = 12;
	c = n;
}

int main()
{
	freopen("julian.in", "r", stdin);
	freopen("julian.out", "w", stdout);
	
	scanf("%d", &Q);
	while (Q--) {
		scanf("%d", &n);
		reset();
		
		if (n < Bc) {
			a = (n / y4) * 4;
			c = n % y4;
			
			if (c >= 366) {
				c -= 1;
				while (c >= 365) {
					a++;
					c -= 365;
				}
			}
			
			Jug(n % y4 < 366);
			
			printf("%d %d %d BC\n", c + 1, b + 1, 4713 - a);
			continue;
		}
		if (n - Bc <= Ge) {
			n -= Bc;
			a = (n / y4) * 4;
			c = n % y4;
			
			bool run = false;
			for (int i = 1; i <= 3; ++i) {
				if (c >= 365) {
					c -= 365;
					a++;
					
					if (i == 3) run = true;
				}
				else break;
			}
			
			Jug(run);
			
			printf("%d %d %d\n", c + 1, b + 1, a + 1);
			continue;
		}
		if (1) {
			n -= Bc;n -= Ge;
			if (n < 77) {
				s_j();
				printf("%d %d %d\n", c + 1, b, 1582);
				continue;
			}
			n -= 77;
			c = n;
			
			bool run = false;
			if (c <= 6210) {
				for (int i = 1; i <= 17; ++i) {
					int cache = 365;
					if (i == 1 || i == 5 || i == 9 || i == 13 || i == 17) cache = 366;
					if (c >= cache) {
						c -= cache;
						a++;
						
						if (cache == 366) run = true;
					}
					else break;
				}
				printf("%d %d %d\n", c + 1, b + 1, a + 1582);
				continue;
			}
			else c -= 6210;
			
			a = (n / y400) * 400;
			c = n % y400;
			
			for (int i = 1; i <= 3; ++i) {
				if (c >= y100) {
					c -= y100;
					a += 100;
				}
				else break;
			}
			
			a += (c / y4) * 4;
			c %= y4;
			
			if (c >= 366) {
				c -= 1;
				if (c < 365) run = true;
				while (c >= 365) {
					a++;
					c -= 365;
				}
			}
			
			Jug(run);
			
			printf("%d %d %d\n", c + 1, b + 1, a + 1600);
			continue;
		}
	}
	
	getchar();
	getchar();
	return 0;
}
/*
1721789
1722885
2299160
2299237
2305447
2445334
*/