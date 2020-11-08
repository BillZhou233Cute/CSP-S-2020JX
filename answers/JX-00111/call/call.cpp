#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;
#define int long long
#define MAXN 1000010
#define mod 998244353
int n,m,q;
int ord[MAXN],ax[MAXN],ay[MAXN],b[MAXN],c[2002][2002];
inline void change(int k)
{
	for(int i=1;c[k][i];i++)
	{
		int x=c[k][i];
		if(ax[x]) ord[ax[x]]=(ord[ax[x]]+ay[x])%mod;
		else if(b[x])
		{
			for(int i=1;i<=n;i++)
			{
				ord[i]=ord[i]*b[x]%mod;
			}
		}
		else
		{
			change(x);
		}
	}
}
signed main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&ord[i]);
	scanf("%lld",&m);
	for(int i=1;i<=m;i++)
	{
		int t,x,y;
		scanf("%lld",&t);
		if(t==1)
		{
			scanf("%lld%lld",&x,&y);
			ax[i]=x,ay[i]=y;
		}
		else if(t==2)
		{
			scanf("%lld",&b[i]);
		}
		else
		{
			scanf("%lld",&x);
			for(int j=1;j<=x;j++)
			{
				scanf("%lld",&c[i][j]);
			}
		}
	}
	scanf("%lld",&q);
	while(q--)
	{
		int x;
		scanf("%lld",&x);
		if(ax[x]) ord[ax[x]]=(ord[ax[x]]+ay[x])%mod;
		else if(b[x])
		{
			for(int i=1;i<=n;i++)
			{
				ord[i]=ord[i]*b[x]%mod;
			}
		}
		else
		{
			change(x);
		}
	}
	for(int i=1;i<=n;i++) printf("%lld ",ord[i]);
	return 0;
}
