#include<bits/stdc++.h>
using namespace std;
int Q,year=4713,month=1,day=1,fla=1,s[15]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int r[100005];
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	int i,j;
	scanf("%d",&Q);
	for(i=1;i<=Q;i++)
	{
		s[2]=28;
		year=4713;
		month=1;
		day=1;
		scanf("%d",&r[i]);
		while(r[i]>=366)
		{
			if(year<-1581)
			{
				int real=1-year;
				if((real%4==0&&real%100!=0)||real%400==0) fla=1;
				else fla=2;
			}
			if(fla==1)
			{
				year--;
				r[i]-=366;
				fla++;
			}
			else
			{
				year--;
				r[i]-=365;
				fla++;
			}
			if(fla==5&&year>=-1581) fla=1;
		}
		if(fla!=1&&r[i]>365)
		{
			year--;
			r[i]-=365;
		}
		if(fla==1) s[2]++;
		for(j=1;j<=12;j++)
		{
			if(r[i]>s[j])
			{
				r[i]-=s[j];
				month++;
			}
			else break;
		}
		day=r[i];
		day++;
		if(day>s[month])
		{
			day=1;
			month++;
		}
		if(month==13)
		{
			month=1;
			year--;
		}
		if(year<0)
		{
			year=1-year;
			if(year>1582) day+=10;
			else if(year==1582)
			{
				if(month>10) day+=9;
				else if(month==10&&day>4) day+=9;
			}
			if(day>s[month])
			{
				day=1;
				month++;
			}
			if(month==13)
			{
				month=1;
				year++;
			}
			printf("%d %d %d\n",day,month,year);
		}
		else printf("%d %d %d BC\n",day,month,year);
	}
	return 0;
}