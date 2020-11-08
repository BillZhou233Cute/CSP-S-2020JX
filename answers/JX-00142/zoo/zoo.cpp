#include<bits/stdc++.h>
using namespace std;
int n,m,c,k,a[1000005],p[1000005],q[1000005],loc[70],sum;
unsigned long long ans=1;
int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	int i;
	scanf("%d%d%d%d",&n,&m,&c,&k);
	for(i=1;i<=n;i++)
	scanf("%d",&a[i]);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&p[i],&q[i]);
		loc[p[i]]=-1;
	}
	for(i=0;i<k;i++)
	if(loc[i]!=-1) loc[i]=1;
	for(i=1;i<=n;i++)
	{
		int temp=a[i],now=0;
		while(temp!=0)
		{
			if(temp%2==1) loc[now]=1;
			temp/=2;
			now++;
		}
	}
	for(i=0;i<k;i++)
	if(loc[i]==1) sum++;
	for(i=1;i<=sum;i++)
	ans*=2;
	cout<<ans-n<<endl;
	return 0;
}