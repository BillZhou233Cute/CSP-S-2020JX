#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;
int n,m,q;
long long mulv=1;
long long a[100005];
int op[100005];
vector <int> c[100005];
void add(int x,int y)
{
	for (int i=1;i<=n;i++)
		a[i]=a[i]*mulv%MOD;
	mulv=1;
	a[x]=(a[x]+y)%MOD;
}
void mul(int x)
{
	mulv=(mulv*x)%MOD;
}
void call(vector <int> o)
{
	int len=o.size();
	for (int i=0;i<len;i++)
	{
		if (op[o[i]]==1)
			add(c[o[i]][0],c[o[i]][1]);
		if (op[o[i]]==2)
			mul(c[o[i]][0]);
		if (op[o[i]]==3);
			call(c[o[i]]);
	}
}
int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%lld",a+i);
	scanf("%d",&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d",op+i);
		if (op[i]==1)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			c[i].push_back(x);
			c[i].push_back(y);
		}
		if (op[i]==2)
		{
			int x;
			scanf("%d",&x);
			c[i].push_back(x);
		}
		if (op[i]==3)
		{
			int tot;
			scanf("%d",&tot);
			for (int j=1;j<=tot;j++)
			{
				int x;
				scanf("%d",&x);
				c[i].push_back(x);
			}
		}
	}
	scanf("%d",&q);
	while (q--)
	{
		int x;
		scanf("%d",&x);
		if (op[x]==1)
			add(c[x][0],c[x][1]);
		if (op[x]==2)
			mul(c[x][0]);
		if (op[x]==3)
			call(c[x]);
	}
	for (int i=1;i<=n;i++)
		printf("%lld ",a[i]*mulv%MOD);
	return 0;
}