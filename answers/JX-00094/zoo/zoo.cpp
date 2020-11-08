#include <iostream>
#include <cstdio>
using namespace std;
int n,m,c,k;
const int N=1e6+10;
long long ans=1;
int a[N];
bool lis[N],vis[N];
int ki,li;

int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&c,&k);
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) 
	{
		long long p,q;
		scanf("%lld%lld",&p,&q);
		if(!lis[p]) ki++,lis[p]=1;
	}
	for(int i=1;i<=n;i++)
	{
		int u=a[i];
		int j=0;
		while(u)
		{
			if(u&1&&!vis[j]&&lis[j]!=0) vis[j]=1,li++;
			u/=2;j++;
		}
	}
	for(int i=1;i<=k-ki+li;i++) ans*=2;
	ans-=n;
	//cout<<li<<" "<<ki<<" "; 
	printf("%lld\n",ans);
	return 0;
}
