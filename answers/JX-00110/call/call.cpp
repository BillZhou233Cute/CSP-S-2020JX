#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<queue>
using namespace std;
#define int long long
int read()
{
	int f=1, x=0;
	char c=getchar();
	for(; c<'0' || c>'9'; c=getchar())
		if(c=='-') f=-f;
	for(; c>='0'&&c<='9'; c=getchar())
		x = (x>>1) + (x>>3) + (c^48);
	return x*f;
}
#define N 20005
signed n, m, q, tot[N], g[N][20006];
int id[N], ope[N], a[N], kind[N];
void f1(int ind)
{
	a[id[ind]] += ope[ind];
	a[id[ind]] %= 998244353;
}
void f2(int ind)
{
	for(int i=1; i<=n; i++)
		a[i] *= ope[ind], a[i] %= 998244353;
}
void f3(int ind)
{
	for(int i=1; i<=tot[ind]; i++)
	{
		if(kind[g[ind][i]]==1)f1(g[ind][i]);
		if(kind[g[ind][i]]==2)f2(g[ind][i]);
	}
}
signed main()
{
	freopen("call.in", "r", stdin);
	freopen("call.out", "w", stdout);
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
		a[i] = read();
	scanf("%d", &m);
	for(int i=1; i<=m; i++)
	{
		int typ = read();
		kind[i] = typ;
		if(typ==1)
		{
			id[i] = read();
			ope[i] = read();
		}
		else if(typ==2)
			ope[i] = read();
		else if(typ==3)
		{
			tot[i] = read();
			for(int j=1; j<=tot[i]; j++)
				g[i][j] = read();
		}
	}
	scanf("%d", &q);
	for(int i=1; i<=q; i++)
	{
		int e = read();
		if(kind[e]==1)f1(e);
		if(kind[e]==2)f2(e);
		if(kind[e]==3)f3(e);
	}
	for(int i=1; i<=n; i++)
		printf("%lld ", a[i]%998244353);
	puts("");
	fclose(stdin);
	fclose(stdout);
	return 0;
}