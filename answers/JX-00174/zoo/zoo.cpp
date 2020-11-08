#include <bits/stdc++.h>
using namespace std;
int n,m,c,k;
bool vis[100],d[100];
int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&c,&k);
	for (int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		int cnt=0;
		while (x)
		{
			if (x&1)
				vis[cnt]=1;
			cnt++;
			x>>=1;
		}
	}
	for (int i=1;i<=m;i++)
	{
		int p,q;
		scanf("%d%d",&p,&q);
		if (!vis[p] && !d[p])
		{
			k--;
			d[p]=1;
		}
	}
	printf("%lld",(1ll<<k)-n);
	return 0;
}