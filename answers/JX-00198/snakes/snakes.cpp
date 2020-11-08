#include<bits/stdc++.h>
using namespace std;
int t,n,a[1000001],b[1000001],re=0;
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
		int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		scanf("%d",&n);
		if(i==1)
		for(int i=1;i<=n;i++)
		{scanf("%d",&a[i]);b[i]=a[i];}
		else
		{
			for(int i=1,x,y;i<=n;i++)
			{
				scanf("%d%d",&x,&y);
				a[x]=y;
			}
		}
		
		if(a[3]-a[1]>=a[2]) 
		{cout<<1<<endl;}
	    else cout<<3<<endl;
		
	}
}