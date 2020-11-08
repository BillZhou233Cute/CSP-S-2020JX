#include<cmath>
#include<cstring>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<map>
#define int long long 
using namespace std;
const int maxn=1e6+5;
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
int n,m,c,k;
int a[maxn];
struct node
{
	int x,y;
}p[maxn];
int book[105];
int vis[maxn];
int s[maxn];
int tot=0;
map<int,int> mp;
int danger[maxn];
int cnt=0;
int C(int n1,int m1)
{
	if(n1<m1 || m1<0)
	return 0;
	double wns=1;
	for(int i=1;i<=m1;i++)
	{
		wns=wns/(double)i;
	} 
	for(int i=1;i<=n1;i++)
	{
		wns=wns*(double)i;
	}
	for(int i=1;i<=n1-m1;i++)
	{
		wns=wns/(double)i;
	}
	return (int)wns;
}
int v[maxn];
signed main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	n=read(),m=read(),c=read(),k=read();
	v[0]=1;
	for(int i=1;i<=64;i++)
	v[i]=v[i-1]*2;
	int wns=v[k];
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		//int x=a[i];
		for(int j=0;j<=62;j++)
		{
			if((a[i]>>j) & 1)
			{
				book[j]=1;	
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		p[i].x=read(),p[i].y=read();
		if(book[p[i].x])
		{
			s[++tot]=p[i].y;
			mp[p[i].y]=1;
			vis[i]=1;
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(!book[p[i].x])
		{
			if(mp[p[i].y])
			continue;
			else
			danger[p[i].x]=1;
		}
	}
	int ans=0;
	for(int i=62;i>=0;i--)
	{
		if(danger[i])
		{
			cnt++;
		}
	}
	for(int i=1;i<=cnt;i++)
	{
		if(i & 1)
		ans=ans+C(cnt,i)*(v[k-i]);
		else
		ans=ans-C(cnt,i)*(v[k-i]);
	}
	printf("%lld\n",wns-n-ans);
	return 0;
}
/*
3 3 5 4
1 4 6
*/
