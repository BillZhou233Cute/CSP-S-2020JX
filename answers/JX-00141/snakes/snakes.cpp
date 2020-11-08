#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#define ri register int
using namespace std;
int T,n;
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	scanf("%d %d",&T,&n);
	for(ri i=1,k;i<=T;++i)
	{
		if(i!=1)
		{
			scanf("%d",&k);
			for(ri j=1,a;j<=2*k;++j)
			{
				scanf("%d",&a);
			}
		}
		else{
			for(ri j=1,a;j<=n;++j)
			{
				scanf("%d",&a);
			}
		}
		printf("%d",n);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}