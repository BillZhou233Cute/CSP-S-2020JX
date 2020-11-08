#include<cstdio>
#include<iostream>
using namespace std;
int a[1000006];
int main()
{
	int t,n,k,x,y;
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	scanf("%d",&t);
	for(int T=1;T<=t;T++)
	{
		if(T==1)
		{
			scanf("%d",&n);
			for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		}
		else
		{
			scanf("%d",&k);
			for(int i=1;i<=k;i++)
			{
				scanf("%d%d",&x,&y);
				a[x]=y;
			}
		}
		long long sum=0;
		int cnt=n;
		for(int i=1;a[n-1]<a[n]&&i<n;i++) sum+=a[i],a[n]-=a[i],cnt--;
		printf("%d\n",cnt);
	}
	return 0;
}
