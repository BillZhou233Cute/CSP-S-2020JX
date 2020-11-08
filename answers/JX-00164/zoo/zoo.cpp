#include<iostream>
#include<cstdio>
using namespace std;
unsigned long long n,m,y[100],h[100],k,c,ck,zk,hhh,ans=1;
int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	scanf("%lld%lld%lld%lld",&n,&m,&c,&k);
	for(unsigned long long i=1;i<=n;i++)
	{
		scanf("%lld",&ck);
		hhh|=ck;
	}
	for(unsigned long long i=1;i<=m;i++)
	{
		scanf("%lld%lld",&zk,&ck);
		y[zk]=1;
	}
	zk=0;
	while(hhh)
	{
		h[zk++]=hhh%2;
		hhh/=2;
	}
	for(unsigned long long i=0;i<k;i++)
	{
		if(y[i]&&!h[i])continue;
		ans*=2;
	}
	printf("%lld",ans-n);
	return 0;
}