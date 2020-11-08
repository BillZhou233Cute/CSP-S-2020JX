#include<cmath>
#include<ctime>
#include<cstdio>
#include<cstring>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

int q;
long long r;
int md[13]={31,31,28,31,30,31,30,31,31,30,31,30,31};
long long day=1,month=1,year=-4713;
long long dy=365,ry=1461,hy=36524,fy=146097;

void riqi(long long a)
{
	if(a<=31) 
	{
		day=a;
		return ;
	}
	a=a-31;
	if(a<=29)
	{
		day=a;
		month=2;
		return ;
	}
	int i;
	for(i=3;i<=12;i++)
	{
		md[2]=29;
		a-=md[i-1];
		if(a<=md[i])
		{
			day=a;
			month=i;
			return ;
		}
		md[2]=28;
	}
	
	while(1)
	{
		year++;
		for(i=1;i<=12;i++)
	   {
		   a-=md[i-1];
		   if(a<=md[i])
		   {
			   day=a;
			   month=i;
			   return ;
	       }
		   
	   }
	
   }
   return ;
}

void work()
{
	scanf("%lld",&r);
	int i;
	if(r<=2299160)
	{
		long long x1=r/ry,x2=r%ry;
		x2++;
		year=x1*4+year;
		riqi(x2);
		if(year>=0) year++;
	}
	else
	{
		day=15;month=10;year=1582;
		r-=2299160;
		for(;;)
		{
			r--;
			if(r==0) return ;
			day++;
			if(day>md[month])
			{
				day=1;month++;
			}
			if(month>12)
			{
				month=1;year++;
				break;
			}
		}
		for(;;)
		{
			r--;
			if(r==0) return ;
			day++;
			if(day>md[month])
			{
				day=1;month++;
			}
			if(month>12)
			{
				month=1;year++;
			}
			if(year==1600) break;
		}
		r--;
		long long x1=r/fy,x2=r%fy;
		x2++;
		year=x1*400+year;
		for(;;)
		{
			
			if(r==0) return ;
			day++;
			if((year%400==0)||(year%4==0&&year%100!=0))
				md[2]=29;
			if(day>md[month])
			{
				day=1;month++;
			}
			if(month>12)
			{
				month=1;year++;
			}
			
			r--;
		}
	}
	
	
}
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	
	scanf("%d",&q);
	int i;
	for(i=1;i<=q;i++)
	{
		day=1,month=1,year=-4713;
		work();
		bool w=0;
	if(year<0) {year=-year;w=1;}
	printf("%lld %lld %lld",day,month,year);
	if(w)  printf(" BC");
	printf("\n");
	}
	
	
//	cout<<ry<<" "<<hy<<" "<<fy;
	return 0;
}