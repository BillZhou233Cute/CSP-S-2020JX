#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

const int MAXN=100010;
int t,n,a[MAXN],s[MAXN],k,i,j;

int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	scanf("%d",&t);
	int t1=t,ans=n;
	while(t--)
	{
		scanf("%d",&n);
		if(t==t1)
		{
			for(i=1;i<=n;i++)
		    scanf("%d",&a[i]);
		}
		else
		{
			
			scanf("%d",&k);
			for(i=1;i<=k;i++)
			{
				int x,y;
				scanf("%d %d",&x,&y);
				a[x]=y;
			}
		}
		ans-=2;
		printf("%d\n",ans);
	}
	return 0;
}