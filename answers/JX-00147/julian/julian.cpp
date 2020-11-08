#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
ll read(){ll x;scanf("%lld",&x);return x;}
ll d[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	int t=read();
	while(t--)
	{
		ll days=read();
		int years=4713;
		bool bc=true;days+=1;
		while(years>0&&days>(years%4==1?366:365)) if(years%4==1) days-=366,years--; else days-=365,years--;
		if(years>0)
		{
			int month=1;
			while(days>d[month]+((years%4)==1&&(month==2))) days-=((years%4==1)&&(month==2))+d[month],month++;
			printf("%lld %d %d BC\n",days,month,years);
			continue;
		}
		if(days>366) bc=false,years=1;
		while(days>(((years>=1585&&(((years%4==0&&years%100!=0))||(years%400==0)))||(years<1585&&years%4==0))?366:365)) days-=(((years>=1585&&(((years%4==0&&years%100!=0))||(years%400==0)))||(years<1585&&years%4==0))?366:365),years++;
		int month=1;
		while(days>d[month]+((years<1585&&years%4==0&&month==2)||((years>=1585)&&((years%4==0&&years%100!=0&&month==2)||(years%400==0&&month==2))))) days-=((years<1585&&years%4==0&&month==2)||((years>=1585)&&((years%4==0&&years%100!=0&&month==2)||(years%400==0&&month==2))))+d[month],month++;
		printf("%lld %d %d\n",days,month,years);
	}
	return 0;
}
