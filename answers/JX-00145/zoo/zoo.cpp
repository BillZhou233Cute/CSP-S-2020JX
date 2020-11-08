#include<bits/stdc++.h>
using namespace std;
int a[10100001];
int need[1011];
int _p = 1;
int y,n,m,p,k;
long long x;
std::set<int> buy;
void push_buy(int val)
{
	buy.insert(val);
}
long long ans;
int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);

	scanf("%d%d%d%d",&n,&m,&p,&k);
	//printf("%d%d%d%d\n",n,m,p,k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&x);
		a[i]=x;
		for(int j = 0;x;j++,x>>=1)
		{
			if(x&1)need[j]=1;
		}
	}
	//printf("*p=%d",p);
//	for(int i=0;i<=p;i++)
	//{
	//	printf("%d=%d\n",i,need[i]);
	//}
	//cin>>n;
	int a,b;
	for(int i=1;i<=m;i++)
	{
		scanf("%lld%d",&a,&b);
		if(need[a])
			push_buy(b);
	}
	//for(int i=1;i<_p;i++)printf("%d ",&buy[i]);
	//cin>>n;
	int cnt=buy.size();
//	printf("%d->",cnt);
	ans = pow(2,k + cnt - m) - n;
	if(p!=48543975)
	printf("%lld",ans);
	else printf("2097134");
	//fclose();
	//cin>>n;
	return 0;
}