#include<cmath>
#include<ctime>
#include<cstdio>
#include<cstring>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
const long long mod=998244353;
vector <long long>  f[100005];
long long n,m,q;
long long ch=1,wfy[100005]={0};
int vis[100005],che[100005];
long long a[100005];
int t[10050];


void work(int x)
{
	if(t[x]==1) 
	{
		a[f[x][0]]+=f[x][1];
		a[f[x][0]]=a[f[x][1]]%mod;		
		return ;
	}
	if(t[x]==2)
	{
		int i;
		for(i=1;i<=n;i++)
		{
			a[i]=(a[i]*f[x][0])%mod;
		}
		return ;
	}
	if(t[x]==3)
	{
		int i;
		for(i=1;i<=f[x][0];i++)
		{
			work(f[x][i]);
		}
		return ;
	}
	
}
/*
void dfs(int x)
{
	if(t[x]==1) 
	{
		wfy[f[x][0]]+=(f[x][1]*ch)%mod;
		return ;
	}
	if(t[x]==2)
	{
		ch*=f[x][0];
		return ;
}
	if(t[x]==3)
	{
		int i;
		long long ww=1;
		for(i=1;i<=f[x][0];i++)
		{
			dfs(f[x][i]);
		}
		return ;
	}
	return ;
}
*/
int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	
	scanf("%lld",&n);
	int i,j;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	scanf("%lld",&m);
	for(i=1;i<=m;i++)
	{
		int p,c;
		scanf("%lld",&t[i]);
		if(t[i]==1)
		{
			scanf("%d",&p);
			f[i].push_back(p);
			scanf("%d",&p);
			f[i].push_back(p);
		}
		if(t[i]==2)
		{
			scanf("%d",&p);
			f[i].push_back(p);
		}
		if(t[i]==3)
		{
			scanf("%d",&c);
			 f[i].push_back(c);
			for(j=1;j<=c;j++)
			{
				scanf("%d",&p);
			    f[i].push_back(p);
			}
		}
	}
	scanf("%lld",&q);
/*	for(i=1;i<=q;i++)
	{
		int x;
		scanf("%d",&x);
		dfs(x);
	//	cout<<wufuyang<<endl;
	}
	//cout<<ch<<endl;;*/
	for(i=1;i<=q;i++)
	{
		int x;
		scanf("%d",&x);
		work(x);
	}
	for(i=1;i<=n;i++)
	a[i]=a[i]%mod;
	
/*	for(i=1;i<=n;i++)
	{
		a[i]=(a[i]*ch+wfy[i])%mod;
	}*/
	for(i=1;i<=n;i++)
	printf("%lld ",a[i]);
	
	return 0;
}