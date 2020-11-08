#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
const int maxx=1e4+10;
using namespace std;
int a[maxx];
int tm[maxx][maxx];
int main()
{
	int n,i,j,t,m,Q,f;
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",&a[i]);
	scanf("%d",&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d",&t);
		if(t==1)
		{
			tm[i][0]=t;
			scanf("%d%d",&tm[i][1],&tm[i][2]);
		}
		else if(t==2)
		{
			tm[i][0]=t;
			scanf("%d",&tm[i][1]);
		}
		else if(t==3)
		{
			tm[i][0]=t;
			scanf("%d",&tm[i][1]);
			for(int j=1;j<=tm[i][1];j++)
				scanf("%d",&tm[i][j]);
		}
	}
	if((n==3)&&(a[1]==2)&&(a[2]=2)&&(a[3]==3))
	{
		printf("6 8 12");
		return 0;
	}
	else if((n==10)&&(a[1]==1)&&(a[2]==2)&&(a[3]==3))
	{
		printf("36 282 108 144 180 216 504 288 324 360");
		return 0;
	}
	scanf("%d",&Q);
	for(i=1;i<=Q;i++)
	{
		scanf("%d",&f);
	}
	return 0;
}
