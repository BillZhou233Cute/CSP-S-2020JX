#include<cstdio>
#include<iostream>
#include<algorithm>
#define mod 998244353
using namespace std;
const int maxx=100005;
int n,m,t,a[maxx],p,v,c,g[maxx],Q,f[maxx],lover;
inline long long read()
{
	long long x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0')
	{
		if(ch=='-') ch=getchar();
		char ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	n=read();
	for(register int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	m=read();
	for(register int i=1;i<=m;i++)
	{
		if(t==1)
		{
			p=read(),v=read();
			a[p]+=v;
		}
		if(t==2)
		{
			lover=read();
		a[p]*=lover;
		}
		if(t==3)
		{
			c=read();
			for(register int i=1;i<=c;i++) 
			{
				g[i]=read();
			if(g[i]==1)
				{
					a[p]+=v;
				}
				if(g[i]==2)
				{
					for(register int i=1;i<=n;i++)
					{
						a[i]*=lover;
					}
				}
			}
		}
	}
	Q=read();
	for(register int i=1;i<=Q;i++)
	{
		f[i]=read();
	}	
	for(register int i=1;i<=n;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}
