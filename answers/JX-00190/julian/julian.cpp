#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<ctime>
#include<climits>
#include<sstream>
using namespace std;
#define int long long

inline int read()
{
	char c ; int flag = 1;
	while((c = getchar()) < '0' || c > '9'){if(c == '-'){flag = -1;}}
	int count = c - '0';
	while((c = getchar()) >= '0' && c <= '9'){count *= 10 ; count += c - '0';}
	return count * flag;
}
inline void print(int x)
{
	if(x < 0){putchar('-') ; x = -x;}
	if(x > 9){print(x / 10);}
	putchar(x % 10 + '0');
}

inline int pow(int a , int b)
{
	int ans = 1;
	while(b)
	{
		if(b & 1){ans *= a;}
		a *= a;
		b >>= 1;
	}
}

int f[110];
int p;
void build()
{
	f[0] = 1461;
	p = 1;
	while(f[p - 1] < 1e16)
	{
		f[p] = 1461 * pow(2 , p);
		//f[p] -= (12 + 4 * pow(2 , p)) / 100;
		//f[p] += (12 + 4 * pow(2 , p)) / 400;
		p++;
	}
	p--;
}

int pn[13] = {0 , 31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31};
int rn[13] = {0 , 31 , 29 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31};

void check(int x)
{
	if(x < 1721433 + 1) //in BC
	{
		int t = p;
		int y = 0;
		while(t >= 0)
		{
			if(x > f[t])
			{
				x -= f[t];
				y += 4 * pow(2 , t);
				continue;
			}
			t--;
		}
		while(x > 731)
		{
			y++;
			x -= 365;
		}
		if(x > 366)
		{
			y++;
			x -= 366;
		}
		if((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
		{
			int m = 1;
			for(register int i = 1 ; i <= 12 ; i++)
			{
				if(x - rn[i] > 0)
				{
					x -= rn[i];
					m++;
				}
			}
			print(x) ; putchar(' ');
			print(m) ; putchar(' ');
			print(4713 - y) ; putchar(' ');
			putchar('B') ; putchar('C');
			putchar('\n');
		}
		else
		{
			int m = 1;
			for(register int i = 1 ; i <= 12 ; i++)
			{
				if(x - pn[i] > 0)
				{
					x -= pn[i];
					m++;
				}
			}
			print(x) ; putchar(' ');
			print(m) ; putchar(' ');
			print(4713 - y) ; putchar(' ');
			putchar('B') ; putchar('C');
			putchar('\n');
		}
		return;
	}
	x -= 1721433;
	if(x < 558065 + 1)
	{
		int t = p;
		int y = 1;
		while(t >= 0)
		{
			if(x > f[t])
			{
				x -= f[t];
				y += 4 * pow(2 , t);
				continue;
			}
			t--;
		}
		while(x > 731)
		{
			y++;
			x -= 365;
		}
		if(x > 366)
		{
			y++;
			x -= 366;
		}
		if((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
		{
			int m = 1;
			for(register int i = 1 ; i <= 12 ; i++)
			{
				if(x - rn[i] > 0)
				{
					x -= rn[i];
					m++;
				}
			}
			print(x) ; putchar(' ');
			print(m) ; putchar(' ');
			print(y) ; putchar(' ');
			putchar('\n');
		}
		else
		{
			int m = 1;
			for(register int i = 1 ; i <= 12 ; i++)
			{
				if(x - pn[i] > 0)
				{
					x -= pn[i];
					m++;
				}
			}
			print(x) ; putchar(' ');
			print(m) ; putchar(' ');
			print(y) ; putchar(' ');
			putchar('\n');
		}
		return;
	}
	x -= 558065 - 1;
	if(x < 77 + 1)
	{
		if(x <= 16)
		{
			print(15 + x) ; putchar(' ');
			print(10) ; putchar(' ');
			print(1528) ; putchar(' ');
			putchar('\n');
			return;
		}
		if(x <= 16 + 30)
		{
			print(x - 16) ; putchar(' ');
			print(11) ; putchar(' ');
			print(1528) ; putchar(' ');
			putchar('\n');
			return;
		}
		print(x - 16 - 30) ; putchar(' ');
		print(12) ; putchar(' ');
		print(1528) ; putchar(' ');
		putchar('\n');
		return;
	}
	x -= 77 - 1;
	if(x < 1095 + 1)
	{
		int y = 1528;
		while(x > 365)
		{
			x -= 365;
			y++;
		}
		int m = 1;
		for(register int i = 1 ; i <= 12 ; i++)
		{
			if(x - pn[i] > 0)
			{
				x -= pn[i];
				m++;
			}
		}
		print(x) ; putchar(' ');
		print(m) ; putchar(' ');
		print(y) ; putchar(' ');
		putchar('\n');
		return;
	}
	x -= 1975 - 1;
	int t = p;
	int y = 1532;
	while(t >= 0)
	{
		if(x > f[t])
		{
			x -= f[t];
			y += 4 * pow(2 , t);
			continue;
		}
		t--;
	}
	while(x > 731)
	{
		y++;
		x -= 365;
	}
	if(x > 366)
	{
		y++;
		x -= 366;
	}
	if((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
	{
		int m = 1;
		for(register int i = 1 ; i <= 12 ; i++)
		{
			if(x - rn[i] > 0)
			{
				x -= rn[i];
				m++;
			}
		}
		print(x) ; putchar(' ');
		print(m) ; putchar(' ');
		print(y) ; putchar(' ');
		putchar('\n');
	}
	else
	{
		int m = 1;
		for(register int i = 1 ; i <= 12 ; i++)
		{
			if(x - pn[i] > 0)
			{
				x -= pn[i];
				m++;
			}
		}
		print(x) ; putchar(' ');
		print(m) ; putchar(' ');
		print(y) ; putchar(' ');
		putchar('\n');
	}
	return;
}

signed main()
{
	freopen("julian.in" , "r" , stdin);
	freopen("julian.out" , "w" , stdout);
	int q = read();build();
	for(register int i = 1 ; i <= q ; i++)
	{
		check(read() + 1);
	}
	return 0;
}
