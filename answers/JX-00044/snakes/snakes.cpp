#include<bits/stdc++.h>
#define read(a) scanf("%d",& a)
using namespace std;
int n;
struct snake{
	int t,b;
}a[500010];
bool eat[500010];
int cmp(snake x,snake y)
{
	if(x.t>y.t||(x.t==y.t&&x.b>y.b))return 0;
	return 1;
}
int T;
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	read(T);
	while(T--)
	{
		read(n);
		for(int i=1;i<=n;i++)
		{
			read(a[i].t);
			a[i].b=i;
		}
		memset(eat,0,sizeof(eat));
		int cnt=n;
		do
		{
			if(cnt==1)break;
			sort(a+1,a+cnt+1,cmp);
			if(eat[a[1].b])
			{cnt++;break;}
//			printf("%d %d\n",a[1].t,a[cnt].t);
			eat[a[cnt].b]=1;
			a[1].b=a[cnt].b;
			a[1].t=a[cnt].t-a[1].t;
		}while(cnt--);
		printf("%d\n",cnt);
	}
	return 0;
}