#include<cstdio>
#include<iostream>
using namespace std;
const int mo[14]={0,31,28,31,30,31,30,31,31,30,31,30,31,0};
int main()
{
	int t;
	long long n;
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&n);
		if(n==2299161)
		{
			puts("15 10 1582");
			continue;
		}
		if(n<2299161) //before 1582 10 15
		{
			if(n==1721424)
			{
				puts("1 1 1");
				continue;
			}
			if(n<1721424) //before 1 1 1
			{
				int y,m,d;
				for(y=4713;n>365;y--)
				{
					n-=365;
					if(y%4==1)  n--;
				}
				for(m=1;n>mo[m];m++)
				{
					if(m==2&&y%4==1) n--;
					n-=mo[m];
				}
				d=n;
				printf("%d %d %d BC\n",d+1,m,y);
			}
			if(n>1721424) //between 1 1 1 and 1582 10 4
			{
				n-=1721424;
				int y,m=1,d;
				for(y=1;n>365+(y%4==0?1:0);y++)
				{
					n-=365;
					if(y%4==0) n--;
				}
				while(n>mo[m])
				{
					n-=mo[m];
					m++;
				}
				d=n+1;
				printf("%d %d %d\n",d,m,y);
				continue;
			}
		}
		else
		{
			n-=2299161;
			if(n<=17)
			{
				printf("%lld 10 1582\n",n+15);
				continue;
			}
			if(n<=78)
			{
				n-=17;
				if(n>30)
				{
					printf("%lld 12 1582\n",n-30);
					continue;
				}
				else
				{
					printf("%lld 11 1582\n",n);
					continue;
				}
			}
			else
			{
				n-=78;
				int y=1583,m=1,d;
				while(n>365+(y%4==0&&y%100!=0?1:0))
				{
					n-=365;
					if(y%4==0&&y%100!=0) n--;
					y++;
				}
				while(n>mo[m])
				{
					n-=mo[m];
					if(m==2&&y%100!=0&&y%4==0) n--;
					m++;
				}
				d=n+1;
				printf("%d %d %d\n",d,m,y);
				continue;
			}
		}
	}
	return 0;
}
