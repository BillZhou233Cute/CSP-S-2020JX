#include<cmath>
#include<cstring>
#include<cstdio>
#include<iostream>
#include<algorithm>
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
int a[maxn];
int k,n;
int T;
int ans=0;
int pre[maxn];
int s[maxn];
int b[maxn];
int tot=0;
signed main()
{	
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	T=read();
	n=read();
	if(n==3)
	{
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
			//pre[i]=pre[i-1]+a[i];
		}
		if(a[3]-a[1]>=a[2])
		{
			ans=1;
		}
		else
		{
			ans=3;
		}
		printf("%lld\n",ans);
		T--;
		while(T--)
		{
			k=read();
			for(int i=1;i<=k;i++)
			{
				int x=read(),y=read();
				a[x]=y;
			}
			if(a[3]-a[1]>=a[2])
			{
				ans=1;
			}
			else
			{
				ans=3;
			}
			printf("%lld\n",ans);
		}
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		//pre[i]=pre[i-1]+a[i];
		b[i]=a[i];
	}
	ans=n;
	int l=1,r=n;
	while(l<r)
	{
		//cout<<l<<" "<<r<<endl;
		pre[l-1]=pre[l-2]=0;
		for(int i=l;i<=r;i++)
		pre[i]=pre[i-1]+a[i];
		int now=a[r];
		//cout<<now<<endl;
		int nowl=l-1,nowr=r-1;
		while(nowl<nowr)
		{
			int mid=(nowl+nowr+1)>>1;
			if(pre[mid]>now)
			{
				nowr=mid-1;
				continue;
			}
			int wns=now-pre[mid];
			if(mid==r-1)
			{
				nowl=r-1;
				break;
			}
			int val=a[r-1];
			int res=val;
			if(res>wns)
			{
				nowr=mid-1;
			}
			else
			nowl=mid;
		}
		if(nowl==l-1)
		{
			break;
		}
		ans-=(nowl-l+1);
		a[r]-=pre[nowl];
		l=nowl+1;
		sort(a+l,a+r);
	}
	printf("%lld\n",ans);
	T--;
	while(T--)
	{
		for(int i=1;i<=n;i++)
		{
			a[i]=b[i];
		}
		k=read();
		for(int i=1;i<=k;i++)
		{
			int x=read(),y=read();
			a[x]=y;
		}
		for(int i=1;i<=n;i++)
		b[i]=a[i];
		ans=n;
	int l=1,r=n;
	while(l<r)
	{
		pre[l-1]=pre[l-2]=0;
		for(int i=l;i<=r;i++)
		pre[i]=pre[i-1]+a[i];
		int now=a[r];
		int nowl=l-1,nowr=r-1;
		while(nowl<nowr)
		{
			int mid=(nowl+nowr+1)>>1;
			if(pre[mid]>now)
			{
				nowr=mid-1;
				continue;
			}
			int wns=now-pre[mid];
			if(mid==r-1)
			{
				nowl=r-1;
				break;
			}
			int val=a[r-1];
			int res=val;
			if(res>wns)
			{
				nowr=mid-1;
			}
			else
			nowl=mid;
		}
		if(nowl==l-1)
		{
			break;
		}
		ans-=(nowl-l+1);
		a[r]-=pre[nowl];
		l=nowl+1;
		sort(a+l,a+r);
	}
	printf("%lld\n",ans);
	}
	return 0;
}
