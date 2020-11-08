#include<bits/stdc++.h>
using namespace std;
int T,n,a[1000005],b[1000005],s[1000005],ans,poi;
bool cmp(int x,int y)
{
	return x<y;
}
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	int i,j;
	scanf("%d",&T);
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	scanf("%d",&a[i]);
	for(i=1;i<=n;i++)
	b[i]=a[i];
	sort(b+1,b+n+1,cmp);
	ans=n;
	while(ans>0)
	{
		if(b[ans]-b[1]<b[2]) break;
		else
		{
			ans--;
			b[1]=b[ans]-b[1];
			sort(b+1,b+n+1,cmp);
		}
	}
	printf("%d\n",ans);
	for(i=2;i<=T)
	{
		int k,x,y;
		scanf("%d",&k);
		for(j=1;j<=k;j++)
		{
			scanf("%d%d",&x,&y);
			a[x]=y;
			for(i=1;i<=n;i++)
		b[i]=a[i];
		sort(b+1,b+n+1,cmp);
		ans=n;
		while(ans>0)
		{
			if(b[ans]-b[1]<b[2]) break;
			else
			{
				ans--;
				b[1]=b[ans]-b[1];
				sort(b+1,b+n+1,cmp);
			}
		}
		printf("%d\n",ans);
		}
	}
	return 0;
}