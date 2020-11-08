#include<bits/stdc++.h>
#define ll long long
#define R register int
using namespace std;
const int mod=998244353,N=1e6+5;
ll a[N],d[N],g[1005][1005],ans[N],c[N];
ll n,m,q,v[N],p[N],t[N];
int read()
{
	int f=1;char ch;
	while((ch=getchar())<'0'||ch>'9') if(ch=='-') f=-1;
	int res=ch-'0';
	while((ch=getchar())>='0'&&ch<='9') res=res*10+ch-'0';
	return res*f;
}
void write(int x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
void work(int x)
{
	if(t[x]==1) d[p[x]]=(d[p[x]]+v[x])%mod,d[p[x]+1]=(d[p[x]+1]-v[x]+mod)%mod;
	if(t[x]==2) for(R i=1;i<=n;i++) d[i]=d[i]*v[x]%mod;
	if(t[x]==3)
	{
		for(R i=1;i<=c[x];i++)
			work(g[x][i]);
	}
}
int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	n=read();
	for(R i=1;i<=n;i++) a[i]=read()%mod;
	for(R i=1;i<=n;i++) d[i]=(a[i]-a[i-1]+mod)%mod;
	m=read();
	for(R i=1;i<=m;i++)
	{
		t[i]=read();
		if(t[i]==1) p[i]=read(),v[i]=read();
		if(t[i]==2) v[i]=read();
		if(t[i]==3)
		{
			c[i]=read();
			for(R j=1;j<=c[i];j++) g[i][j]=read();
		}
	}
	q=read();
	for(R i=1;i<=q;i++) 
	{
		int x=read();
		work(x);
	}
	for(R i=1;i<=n;i++) ans[i]=(d[i]+ans[i-1])%mod;
	for(R i=1;i<=n;i++) printf("%lld ",ans[i]%mod);
	fclose(stdin);fclose(stdout);
}