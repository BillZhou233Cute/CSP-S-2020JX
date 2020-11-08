#include<cstdio>
#include<iostream>
#include<cmath>
#define INF 100000005
using namespace std;
int n;
const int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int ansn[INF],ansy[INF],ansr[INF];
bool ry(int x,int y,int r)
{
	if((x>1582)||(x==1582&&y>10)||(x==1582&&y==10&&r>=15))
	{
		if(x%100!=0)
		{
			if(x%4==0)
				return 1;
			else
				return 0;
			}
		else if(x%100==0)
		{
			if(x%400==0)
				return 1;
			else
				return 0;
			}
		}
	else
	{
		if(x<0)
		{
			x=abs(x);
			if(x%4==1)
				return 1;
			else
				return 0;
			}
		else if(x>0)
		{
			if(x%4==0)
				return 1;
			else
				return 0;
			}
			}
}
void gl(int x)//儒略历转公历//公元前 4713 年 1 月 1 日
{
	int n=-4713,y=1,r=1;
	int rec=x;
	if(ansn[x]!=0)
	{
		printf("%d %d",ansr[x],ansy[x]);
		if(ansn[x]>0)
			printf(" %d\n",ansn[x]);
		else
			printf(" %d BC\n",-ansn[x]);
		return;
		}
	while(x)
	{
		x--;
		r++;
		if(n==1582)
		{
			if(y==10)
			{
				if(r==5)
				{
					r=15;
					continue;
					}
				}
			}
		//
		if(y!=2&&y!=13)
		{
			if(r==a[y]+1)
			{
				y++;
				r=1;
				}
			}
		else if(y==2)
		{
			if(r==a[y]+1+ry(n,y,r))
			{
				y++;
				r=1;
				}
			}
		else if(y==13)
		{
			n++;
			y=1;
			}
		//
		if(n==0)
			n=1;
		ansn[rec-x]=n,ansy[rec-x]=y,ansr[rec-x]=r;
		}
	printf("%d %d",r,y);
	if(n>0)
		printf(" %d\n",n);
	else
		printf(" %d BC\n",-n);
	return;
}
void gln(int x)
{
	int n=-4713,y=1,r=1;
	int rec=x;
	while(x)
	{
		x--;
		r++;
		if(n==1582)
		{
			if(y==10)
			{
				if(r==5)
				{
					r=15;
					continue;
					}
				}
			}
		//
		if(y!=2&&y!=13)
		{
			if(r==a[y]+1)
			{
				y++;
				r=1;
				}
			}
		else if(y==2)
		{
			if(r==a[y]+1+ry(n,y,r))
			{
				y++;
				r=1;
				}
			}
		else if(y==13)
		{
			n++;
			y=1;
			}
		//
		if(n==0)
			n=1;
		ansn[rec-x]=n,ansy[rec-x]=y,ansr[rec-x]=r;
		}
	return;
}
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	scanf("%d",&n);
	gln(10000001);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		gl(x);
	}
	return 0;
}