#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
ll n,m,b,a[200002],h[200002][4],d[2000002],mo=998244353,t;
inline void pd(ll x);
inline void rd(ll &x)
{
	x=0;
	char c=getchar();
	while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
}
inline void pt(ll x)
{
	if(x>9) pt(x/10);
	putchar(x%10+'0');
}
inline void h1(ll x)
{
	a[h[x][1]]+=h[x][2];
	a[h[x][1]]%=mo;
}
inline void h2(ll x)
{
	for(int i=1;i<=n;i++) a[i]*=h[x][1],a[i]%=mo;
}
inline void h3(ll l,ll r)
{
	for(int i=l;i<=r;i++) pd(d[i]);
}
inline void pd(ll x)
{
	if(h[x][0]==1) h1(x);
	else if(h[x][0]==2) h2(x);
	else h3(h[x][2],h[x][3]);
}
int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	rd(n);
	for(ll i=1;i<=n;i++) rd(a[i]);
	rd(m);
	for(ll i=1;i<=m;i++)
	{
		rd(h[i][0]);
		if(h[i][0]==1) rd(h[i][1]),rd(h[i][2]);
		else if(h[i][0]==2) rd(h[i][1]);
		else
		{
			rd(h[i][1]);
			h[i][2]=t+1;h[i][3]=t+h[i][1];
			while(++t<=h[i][3]) rd(d[t]);
		}
	}
	ll x;
	rd(b);
	while(b--) rd(x),pd(x);
	for(ll i=1;i<=n;i++) pt(a[i]),putchar(' ');
	return 0;
}
