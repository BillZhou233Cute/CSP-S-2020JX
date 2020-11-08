#include<bits/stdc++.h>
using namespace std;
long long n,a[100001],m,t[100001],p[100001],v[100001],c[100001],g[10001][10001],q,f;
long long mod=998244353;
inline long long read()
{
	long long x=0;
	char c=getchar();
	bool flag=0;
	while(c>'9'||c<'0')
	{
		if(c=='-') flag=1;
		c=getchar();
	}
	while(c<='9'&&c>='0')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	if(flag) x=-x;
	return x;
}
int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	m=read();
	for(int i=1;i<=m;i++)
	{
		t[i]=read();
		if(t[i]==1) p[i]=read(),v[i]=read();
		if(t[i]==2) v[i]=read();
		if(t[i]==3) 
		{
			c[i]=read();
			for(int j=1;j<=c[i];j++)
			g[i][j]=read();
		}
	}
	q=read();
	while(q--)
	{
		f=read();
		if(t[f]==1) a[p[f]]=(a[p[f]]+v[f])%mod;
		if(t[f]==2) for(int i=1;i<=n;i++) a[i]=a[i]*v[f]%mod;
		if(t[f]==3) for(int i=1;i<=c[f];i++) 
		{
			if(g[f][i]==1) a[p[g[f][i]]]=(a[p[g[f][i]]]+v[g[f][i]])%mod;
			if(g[f][i]==2) for(int j=1;j<=n;j++) a[j]=a[j]*v[g[f][i]]%mod;
		}
	}
	for(int i=1;i<=n;i++) printf("%lld ",a[i]%mod);
	return 0;
}
