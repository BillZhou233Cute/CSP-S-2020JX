#include<iostream>
#include<cstdio>
using namespace std;
long long q,p=1,day,month=1,m[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
long long year=-4713;
int main()
{
freopen("julian.in","r",stdin);
freopen("julian.out","w",stdout);
  cin>>q;
  for(int i=1;i<=q;i++)  
	  {
      scanf("%lld",&day);
      if(day>=229914)
      {p=0;year=1582;month=10;day-=229914;day+=11;}
      if(p==1)
	{
	  year+=day/365;day-=(day/365)*365;if(year+4713!=0)
	 day-=(year+4717)/4;
	 while(day<=0)
	 {
if((year+4713)%4==0)
	 {day+=366;year--;}
 else
 {day+=365;year--;}}
	 for(int i=1;i<=12;i++)
{
if(i==2&&(year+4713)%4==0) m[i]+=1;
if(day>m[i])
{day-=m[i];month++;}else break;
if(i==2&&(year+4713)%4==0)m[i]-=1;
   };
   if(year>-1)year++;
   if(year<0) cout<<day<<' '<<month<<' '<<-year<<" BC"<<endl;
   else cout<<day<<' '<<year<<endl;}
  if(p==0)
    {year+=day/365;day-=(day/365)*365;
      day=day+year/100-15-(year/4+year/400)+398;
      while(day<=0)
	{if(year%400==0||((year%4==0)&&(year%100!=0)))
	    {year--;day+=365;}
	  else {year--;day+=365;}}
      for(int i=10;i<=12;i++)
	{
	  if((year%400==0||(year%100!=0&&year%4==0))&&i==2)
	     m[i]+=1;
	     if(day>m[i])
	       {day-=m[i];month++;if(month==13)month-=12,year++;}
	     else break;
		if((year%400==0||(year%100!=0&&year%4==0))&&i==2)m[i]-=1;
	}
	  cout<<day<<' '<<month<<' '<<year<<endl;
	}
	  
	  }return 0;
}
