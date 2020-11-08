#include<cmath>
#include<cstring>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#define int long long
using namespace std;
const int maxn=1e5+5;
const int mod=998244353;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9')
	{
		if(ch=='-')
		f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int n,m;
struct node
{
	int opt;
	int id;
	int val;
}p[maxn];
vector<int> v[maxn];
int a[maxn];
int Q;
void Work(int x)
{
	//cout<<x<<endl;
	if(p[x].opt==1)
	{
		a[p[x].id]+=p[x].val;
		a[p[x].id]%=mod;
	}
	else
	if(p[x].opt==2)
	{
		for(int i=1;i<=n;i++)
		{
			a[i]=a[i]*p[x].val%mod;
		}
	}
	else
	{
		int tot=v[x].size();
		for(int i=0;i<tot;i++)
		{
			Work(v[x][i]);
		}
	}
}
signed main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	m=read();
	for(int i=1;i<=m;i++)
	{
		p[i].opt=read();
		if(p[i].opt==1)
		{
			p[i].id=read(),p[i].val=read()%mod;
		}
		else
		if(p[i].opt==2)
		{
			p[i].val=read()%mod;
		}
		else
		{
			int cnt=read();
			for(int j=1;j<=cnt;j++)
			{
				int x=read();
				v[i].push_back(x);
			}
		}
	}
	Q=read();
	while(Q--)
	{
		int x=read();
		Work(x);
	}
	for(int i=1;i<=n;i++)
	{
		printf("%lld ",a[i]);
	}
	//printf("\n");
	return 0;
}
/*
3
1 2 3
3
1 1 1
2 2
3 2 1 2
2
2 3
*/
