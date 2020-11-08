#include<bits/stdc++.h>
using namespace std;
const int N=20005;
int n,m,q;
int a[N];
int mod=998244353;
int b[N],p[N],v[N],mu[N],num[N];
vector <int> c[N];
template <class T> inline void read(T &x)
{
	x=0;int g=1;char s=getchar();
	for (;s>'9'||s<'0';s=getchar())if (s=='-') g=-1;
	for (;s>='0'&&s<='9';s=getchar()) x=(x<<1)+(x<<3)+(s^48);
	x*=g;	
}
void dfs(int x)
{
	int i;
	if (b[x]==1)
		{
			a[p[x]]=(a[p[x]]+v[x])%mod;
		}
		else	if (b[x]==2)
		{
			for (i=1;i<=n;i++)
				a[i]=(a[i]*mu[x])%mod;
		}
			else
			{
				for (i=0;i<num[x];i++)
						dfs(c[x][i]);
			}
}

int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	int i,j;
	read(n);
	for (i=1;i<=n;i++)	read(a[i]);
	read(m);
	for (i=1;i<=m;i++)
	{
		int op;read(op);
		b[i]=op;
		if (op==1)
		{
			read(p[i]);read(v[i]);
		}
		else
			if (op==2)
			{
				read(mu[i]);
			}
			else
			{
				int t;
				read(num[i]);
				for (j=1;j<=num[i];j++)
				{
					int x;read(x);
					c[i].push_back(x);
				}
			}
	}
	read(q);
	for (i=1;i<=q;i++)
	{
		int x;
		read(x);
		dfs(x);
	}	
	for (i=1;i<n;i++)
		printf("%d ",a[i]);
	printf("%d\n",a[n]);
	return 0;
}
