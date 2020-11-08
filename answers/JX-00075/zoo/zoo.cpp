#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
long long n,qwe,c,k,a[1000001],ans=0,num,q,m;
int i,j;
int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	scanf("%lld%lld%lld%lld",&n,&m,&c,&k);
	qwe=n;
	for(i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld",&num,&q);
		num=k-num;
		while(num!=-1)
		{
			if(num==0&&a[i]%2==1)
			{
				a[++n]=q;   //代表次饲料要买
				break;
			}
			num--;
			a[i]/=2;
		}
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)
	{
		if(a[i]==a[i+1])
			ans++;
	}
	qwe-=ans;
	long long sum=1;
	while(k--)
	{
		sum*=2;
	}
	qwe++;
	printf("%lld",sum-qwe);
	return 0;
}