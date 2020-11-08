#include<cmath>
#include<ctime>
#include<cstdio>
#include<cstring>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
int t,n;
long long a[15];

void work()
{
	if(a[3]-a[1]>a[2])
		cout<<"1"<<endl;
	else  
		cout<<"3"<<endl;
}


int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	srand(time(0));
	
	scanf("%d",&t);
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%lld",&a[i]);
	
	if(n==3)
	{
		work();
		for(i=2;i<=t;i++)
		{
			int k,x,y;
			scanf("%d",&k);
			for(int j=1;j<=k;j++)
			{
				scanf("%d%d",&x,&y);
				a[x]=y;
			}
			sort(a+1,a+4);
			work();
		}
	}
	else 
	{
		int ans=rand()%n+1;
		printf("%d\n",ans);
		for(i=2;i<=t;i++)
		{
			int k;int x;
			scanf("%d",&k);
			for(int j=1;j<=k*2;j++)
			scanf("%d",&x);
			ans=rand()%n+1;
			printf("%d\n",ans);
		}
		
	}
	
	
	return 0;
}