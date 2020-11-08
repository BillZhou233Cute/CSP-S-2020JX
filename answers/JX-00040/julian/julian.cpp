#include<bits/stdc++.h>
using namespace std;
int q,r,day,month,year;
int p[13]={0,0,0,31,30,31,30,31,31,30,31,30,31};
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	cin>>q;
	for(int k=1;k<=q;k++)
	{
		cin>>r;
		if(r<1721058)
		{
			month=1;
			year=4713-r/1461*4-r%1461/365;
			day=r%1461%365;
			if(day>31)
			{
				day-=31;
				month++;
			}
			if(year%4==0)
			{
				if(day>29)
				{
					day-=29;
					month++;
				}
			}
			else if(day>28)
			{
				day-=28;
				month++;
			}
			for(int i=3;i<=12;i++)
			if(day>p[i])
			{
				day-=p[i];
				month++;
			}
			if(year==4713&&month==1)
			day++;
			cout<<day<<" "<<month<<" "<<year<<" "<<"BC"<<endl;
		}
		else
		{
			month=1;
			r=r-1721058;
			year=r/1461*4+r%1461/365;
			if(r>577737)
			{
				day=r%1461%365+10;
				if(day>31)
				{
					day-=31;
					month++;
				}
				if(year%400==0||(year%4==0&&year%100!=0))
				{
					if(day>29)
					{
						day-=29;
						month++;
					}
				}
				else 
				{
					if(day>28)
					{
						day-=28;
						month++;
					}
				}
			}
			else
			{
				day=r%1461%365;
				if(day>31)
			{
				day-=31;
				month++;
			}
			if(year%4==0)
			{
				if(day>29)
				{
					day-=29;
					month++;
				}
			}
			else if(day>28)
			{
				day-=28;
				month++;
			}
			}
			for(int i=3;i<=12;i++)
			if(day>p[i])
			{
				day-=p[i];
				month++;
			}
			cout<<day<<" "<<month<<" "<<year<<endl;
		}
	}
	return 0;
}