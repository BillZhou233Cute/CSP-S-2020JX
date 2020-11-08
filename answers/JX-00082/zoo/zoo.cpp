#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,m,c,k,a[31],ans,p[1001],q[1001];
int qing[32];
int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&c,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int j=1;j<=m;j++)
	{
		scanf("%d%d",&p[j],&q[j]);
		for(int i=1;i<=n;i++)
		{
			if(((a[i]>>p[j])&1)==1&&q[j]<=c){qing[q[j]]=1;}
		}
	}
	int maxn=pow(2,k)-1;
	ans=1;
	for(int i=1;i<=maxn;i++)
	{
		bool f=0;
		for(int j=1;j<=n;j++)if(a[j]==i){f=1;break;}
		if(f)continue;
	    f=0;
		for(int j=1;j<=m;j++)
		{
			if(q[j]>c)continue;
			if(((i>>p[j])&1)==1&&qing[q[j]]==0&&q[j]<=c){f=1;break;}
		}
		if(!f)ans++;
	}
	printf("%d",ans);
	return 0;
}
