#include<iostream>
#include<cstdio>
using namespace std;
int n,t,a[4];
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	scanf("%d",&t);
	for(int c=1;c<=t;c++)
	{
		int maxi,maxn=0,ren=3,mini;
		if(c==1)
		{
			scanf("%d",&n);
			for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		}
		else
		{
			int k;
			scanf("%d",&k);
			for(int i=1;i<=k;i++)
			{
				int x,y;
				scanf("%d%d",&x,&y);
				a[x]=y;
			}
		}
		for(int i=1;i<=n;i++)if(a[i]>maxn)maxn=a[i],maxi=i;
		if(maxi==1)
		{
			if((a[1]-a[2]<=a[3])||(a[1]-a[3]<=a[2]))
			{printf("3\n");continue;}
			else {printf("1\n");continue;}
		}
		if(maxi==2)
		{
			if((a[2]-a[1]<=a[3])||(a[2]-a[3]<a[1]))
			{printf("3\n");continue;}
			else {printf("1\n");continue;}
		}
		if(maxi==3)
		{
			if((a[3]-a[1]<a[2])||(a[3]-a[2]<a[1]))
			{printf("3\n");continue;}
			else {printf("1\n");continue;}
		}
	}
	return 0;
}
