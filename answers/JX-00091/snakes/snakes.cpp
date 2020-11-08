#include<cstdio>
#include<algorithm>
using namespace std;
int T,n;
struct data
{
	int num;
	int t;
}a[1000005];
bool cmp(data a,data b)
{
	return a.t<b.t;
}
int main()
{
	freopen("snakes.in","r",stdin);
      freopen("snakes.out","w",stdout);
	scanf("%d%d",&T,&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i].t);
		a[i].num=i;
	}
	sort(a+1,a+n+1,cmp);
	//	for(int i=1;i<=n;i++)
	//	{
	//	printf("%d     ",a[i].t);
	//	}
	int cha=a[n].t-a[n-1].t;
	int i=1;
	for(i=1;i<=n;i++)
		if(cha-a[i].t>0)
			cha-=a[i].t;
		else
			break;
	printf("%d\n",n+1-i);
	for(int i=1;i<T;i++)
	{
		int k,x,y;
		scanf("%d",&k);
		for(int q=1;q<=k;q++)
		{
			scanf("%d%d",&x,&y);
			for(int j=1;j<=n;j++)
				if(a[j].num==x)
					a[j].t=y;
		}		
			sort(a+1,a+n+1,cmp);
			int cha=a[n].t-a[n-1].t;
			int j=1;
			for(j=1;j<=n;j++)
				if(cha-a[j].t>0)
					cha-=a[j].t;
				else
					break;
			printf("%d\n",n+1-j);
	}
	return 0;
}
