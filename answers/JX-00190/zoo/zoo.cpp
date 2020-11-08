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
#include<vector>
#include<map>
#define int unsigned long long

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

const int N = 1e6 + 10;

int a[N];
int f[101];
int num[101];

signed main()
{
	freopen("zoo.in" , "r" , stdin);
	freopen("zoo.out" , "w" , stdout);
	int n , m , c , k;
	n = read() ; m = read() ; c = read() ; k = read();
	for(register int i = 1 ; i <= n ; i++)
	{
		a[i] = read();
	}
	for(register int i = 1 ; i <= n ; i++)
	{
		int p = 0;
		while(a[i])
		{
			if(a[i] & 1){f[p] = 1;}
			a[i] >>= 1 ; p++;
		}
	}
	for(register int i = 0 ; i <= k ; i++)
	{
		num[i] = 2;
	}
	for(register int i = 1 ; i <= m ; i++)
	{
		int p = read() , q = read();
		if(f[p] == 0)
		{
			num[p] = 1;
		}
	}
	int ans = 1;
	for(register int i = 0 ; i <= k - 1; i++)
	{
		ans *= num[i];
	}
	print(ans - n);
	return 0;
}
