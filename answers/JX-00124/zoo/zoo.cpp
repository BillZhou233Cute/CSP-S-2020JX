#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
ll n,m,c,k,a[1000002];
inline void rd(ll &x)
{
	x=0;
	char c=getchar();
	while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
}
int main()
{
	rd(n);
	for(int i=1;i<=n;i++) rd(a[i]);
	for(int i=1;i<=m;i++)
	{
		rd(p);rd(q);
	}
}
