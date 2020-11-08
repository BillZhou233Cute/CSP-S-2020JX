#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

const int MAXN=100010;
int q,i,j,mid=2299161;
int day1[15]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int day2[15]={0,31,29,31,30,31,30,31,31,30,31,30,31};
long long r,s[MAXN];

int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	scanf("%d",&q);
	while(q--)
	{
		    scanf("%lld",&r);
			i=0;
		    if(r<mid)
			{
				int month=0,year=4713,day=0;
			int num1=r/1461,num2=r%1461;
		    int num3=num2/365,num4=num2;
		    if(num4-366>0) num4-=366;
			for(i=1;i<=3;i++)
			{if(num4-365>0) num4-=365;
			 else break;}
			bool f=false;
			year-=num1*4+num3;
			if(year<=0) {year=-year+1;f=true;}
			if(num3%4==0)
			{
				for(i=1;i<=12;i++)
			    {
					month++;
				    if(num4<=day2[i]) break;
				    num4-=day2[i];
			    }
				day+=num4+1;
				if(!f)
				printf("%d %d %d BC\n",day,month,year);
				else
				printf("%d %d %d\n",day,month,year);
			}
			else
			{
				for(i=1;i<=12;i++)
			    {
					month++;
				    if(num4<=day1[i]) break;
				    num4-=day1[i];
			    }
				day+=num4+1;
				if(!f)
				printf("%d %d %d BC\n",day,month,year);
				else
				printf("%d %d %d\n",day,month,year);
			}
			}
			else
			{
				int year=1582,month=9,day=15;
				r-=mid;
				int tot=r;
			    while(true)
				{
					if(year==1582&&tot<=77) break;
					if(year==1582&&tot>77) {year++;continue;}
					if(tot<=365&&(year%4!=0||year%100==0)) break;
					else if(tot<=366&&year%4==0&&(year%100!=0||year%400==0)) break;
					if(year%4==0&&(year%100!=0||year%400==0)) tot-=366;
					else  if(year%4!=0||year%100==0) tot-=365;
					year++;
				}
				if(year%4==0&&(year%100!=0||year%400==0)) 
				{
				while(i<=12)
			    {
					month++;
					if(month>12) month-=12;
					if(tot<=day2[month]) break;
				    tot-=day2[month];
				    i++;
			    }
				day+=tot;
				if(day>day2[month]) {day-=day2[month];month++;if(month>12) month-=12;}
				printf("%d %d %d\n",day,month,year);
				}
				else  if(year%4!=0||year%100==0) 
				{
					while(i<=12)
			    {
					month++;
					if(month>12) month-=12;
					if(tot<=day1[month]) break;
				    tot-=day1[month];
				    i++;
			    }
				day+=tot;
				if(day>day1[month]) {day-=day1[month];month++;if(month>12) month-=12;}
				printf("%d %d %d\n",day,month,year);
				}
			}
	}
	return 0;
}