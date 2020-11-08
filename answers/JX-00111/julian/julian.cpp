#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;
#define int long long 
int q,n,y,m,d;
int da[14]={0,31,28,31,30,31,30,31,31,30,31,30,31},
    da2[14]={0,31,29,31,30,31,30,31,31,30,31,30,31};
signed main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	scanf("%lld",&q);
	while(q--)
	{
		y=-4713,m=d=1;
		scanf("%lld",&n);
		if(n>2298795)
		{
			n+=10;
			y=1584;
			n-=2298795;
			if(n>=5844)
			{
				n-=5844;
				y=1600;
			}
			y+=(n/146098)*400,n%=146098;
			for(int i=1;i<=4;i++)
			{
				if(i==1&&n>=36525) y+=100,n-=36525;
				else if(n>=36524) y+=100,n-=36524;
				else break;
			}
		}
		y+=(n/1461)*4,n%=1461;
		for(int i=1;i<=4;i++)
		{
			if(i==1&&n>=366) n-=366,y++;
			else if(n>=365) n-=365,y++;
			else break;
		}
		cout<<n<<endl;
		if(y<0)
		{
			if(-(y+1)%4!=0)
		    {
				for(int i=1;n>=da[i];i++)
				{
					n-=da[i];
					m++;
				}
				d+=n;
			}
			else
			{
				for(int i=1;n>=da2[i];i++)
				{
					n-=da2[i];
					m++;
				}
				d+=n;
			}
		}
		else
		{
			
			if(y<1584)
			{
				y++;
				if(y%4!=0)
				{
					for(int i=1;n>=da[i];i++)
					{
						n-=da[i];
						m++;
					}
					d+=n;
				}
				else
				{
					for(int i=1;n>=da2[i];i++)
					{
						n-=da2[i];
						m++;
					}
					d+=n;
				}
			}
			else if(y>=1584)
			{
				if((y%400==0)||(y%4==0&&y%100!=0))
				{
					for(int i=1;n>=da2[i];i++)
					{
						n-=da2[i];
						m++;
					}
					d+=n;
				}
				else
				{
					for(int i=1;n>=da[i];i++)
					{
						n-=da[i];
						m++;
					}
					d+=n;
				}
			}
		}
		if(y<0) printf("%lld %lld %lld BC\n",d,m,-y);
		else printf("%lld %lld %lld\n",d,m,y);
	}
	
	return 0;
}
