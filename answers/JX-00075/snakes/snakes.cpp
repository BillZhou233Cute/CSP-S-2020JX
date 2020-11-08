#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
long long f[1000000];
int T,n,k,i,m,j;
long long x,y;
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	scanf("%d",&T);
	T--;
	scanf("%d",&n);
	m=n;
		for(i=1;i<=n;i++)
			scanf("%lld",&f[i]);
	for(i=1;i<=n;i++)
	{
		if(f[n]-f[i]>=f[n-1])
			m--;
	}
	printf("%d\n",m);
	while(T--)
	{
		m=n;
		scanf("%d",&k);
		for(i=1;i<=k;i++)
		{
			scanf("%lld %lld",&x,&y);
			f[x]=y;
		}
		for(i=1;i<=n;i++)
	    {
		    if(f[n]-f[i]>=f[n-1])
			    m--;
	    }
		printf("%d\n",m);
	}
	return 0;
}