#include<iostream>
#include<cstdio>
#include<list>
#define ll long long
using namespace std;
ll read(){ll x;scanf("%lld",&x);return x;}
ll a[1000010],s[1000010];
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	int t=read(),n,rn;
	for(int w=1;w<=t;w++)
	{
		if(w==1) 
		{
			rn=n=read();
			for(int i=1;i<=n;i++) a[i]=read();
		}
		else
		{
			n=rn;
			int k=read();
			for(int i=1;i<=k;i++)
			{
				int p=read();
				a[p]=read();
			}
		}
		if(n==3)
		{
			if(a[3]>=a[2]+a[1]) printf("1\n");
			else printf("3\n");
		}
		else
		{
			s[0]=0;
			for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
			while(a[n]-a[1]>=a[n-1]||(!(a[n]-a[1]<a[2]&&a[n-1]+a[1]-a[n]>=s[n-2]-a[1])))
			{
				n--;
				a[1]=a[n]-a[1];
				int now=1;
				while(a[now]>a[now+1]) swap(a[now],a[now+1]),now++;
				for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
			}
			printf("%d\n",n);
		}
	}
	return 0;
}
