#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
int n,m,callnum,callcall[100001],numjia;
int i,j,ccnum;
int x,y,starcall,Q;
long long ans[100001],jianum,chengnum;
void callnum1()
{
	ans[numjia]=(ans[numjia]+jianum)%998244353;
}
void callnum2()
{
	for(x=1;x<=n;x++)
		ans[x]=(ans[x]*chengnum)%998244353;
}
int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&ans[i]);
	scanf("%d",&m);      //函数的个数;
	for(i=1;i<=m;i++)
	{
		scanf("%d",&callnum);
		if(callnum==3)
		{
			scanf("%d",&ccnum); //函数中函数的个数;
			for(j=1;j<=ccnum;j++)
				scanf("%d",&callcall[j]);
		}
		if(callnum==1)
			scanf("%d%lld",&numjia,&jianum);
		if(callnum==2)
			scanf("%lld",&chengnum);
	}
	scanf("%d",&Q);
	for(i=1;i<=Q;i++)
	{
		scanf("%d",&starcall);
		if(starcall==1)
			callnum1();
		if(starcall==2)
			callnum2();
		if(starcall==3)
			for(j=1;j<=ccnum;j++)
			{
				if(callcall[j]==1)
					callnum1();
				if(callcall[j]==2)
					callnum2();
			}
	}
	for(i=1;i<=n;i++)
		printf("%lld ",ans[i]);
	return 0;
}