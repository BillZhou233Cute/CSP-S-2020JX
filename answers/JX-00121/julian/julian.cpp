#include<bits/stdc++.h>
using namespace std;
#define R register
#define ll long long
inline int read()
{
	int x=0;bool f=0;char s=getchar();
	while(s>'9'||s<'0') {if(s=='-') f=1;s=getchar();}
	while(s>='0'&&s<='9') {x=(x<<1)+(x<<3)+s-'0';s=getchar();}
	return f?-x:x;
} 
int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31},
	 b[13]={0,31,29,31,30,31,30,31,31,30,31,30,31},
	 c[13]={0,31,28,31,30,21,30,31,31,30,31,30,31};

int n,t;
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	t=read();
	while(t--)
	{
		//cout<<1;
		bool f=0;
		int now=-4713,v=-1;
		n=read()+1;
		if(n<=31)
		{
			printf("%d %d %d BC\n",n,1,-now);
			continue;
		}
		while(n)
		{
			if(!now) v=0,now=1;
			if(now<1582)
			{
				if((now-v)%4)
					for(R int i=1;i<=12;i++)
					{
						n-=a[i];
						if(n<=0)
						{
							if(now<0) printf("%d %d %d BC\n",n+a[i],i,-now);
								else printf("%d %d %d\n",n+a[i],i,now);
							f=1;break;
						}
					}
				else
					for(R int i=1;i<=12;i++)
					{
						n-=b[i];
						if(n<=0)
						{
							if(now<0) printf("%d %d %d BC\n",n+b[i],i,-now);
								else printf("%d %d %d\n",n+b[i],i,now);
							f=1;break;
						}
					}
			}
				else 
					if(now==1582)
					for(R int i=1;i<=12;i++)
					{
						n-=c[i];
						if(n<=0)
						{
							if(i!=5||(i==5&&n+c[i]>=4)) printf("%d %d %d\n",n+c[i],i,now);
								else  printf("%d %d %d\n", n+c[i]+10,i,now);
							f=1;break;
						}
					}
				else
				{
					if((now-v)%400==0||((now-v)%4==0&&(now-v)%100))
						for(R int i=1;i<=12;i++)
						{
							n-=b[i];
							if(n<=0)
							{
								printf("%d %d %d\n",n+b[i],i,now);
								f=1;break;
							}
						}
					else
						for(R int i=1;i<=12;i++)
						{
							n-=a[i];
							if(n<=0) 
							{
								printf("%d %d %d\n",n+a[i],i,now);
								f=1;break;
							}
						}
				}
				if(f) break;
				now++;
			}
	}
	return 0;
}