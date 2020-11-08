#include<bits/stdc++.h>
using namespace std;
int mons[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int monsadd[13] = {0,31,59,90,120,151,181,212,243,273,304,334,365};
int getyear(int year)
{
	if(year==0)return 0;
	if(year < 0) year = -year-1;
	if(year > 1582) return (year%4==0)?
		(  (year%100==0)?((year%400==0?366:365)):366  ):
		365;
	else if(year==1582)return 355;
	else return year%4==0?366:365;
}
bool isyear29(int year)
{
	if(year==0)return 0;
	if(year < 0) year = -year-1;
	if(year > 1582) return (year%4==0)?
		(  (year%100==0)?((year%400==0?1:0)):1  ):
		0;
	else if(year==1582)return 0;
	else return year%4==0?1:0;
}
int getmonth(long long day,bool mode)
{
	if(day<=31)return 1;
	day-=mode;
	for(int i=2;i<=12;i++)
	{
		if(day<=monsadd[i])return i;
	}
}
int bc_400 = 146100;
int ad_400 = 146097;
int bd = 2298850;
int cd = 2299159;
void process(long long t)
{
	if(t>cd)
	{
		t -= bd + 15 + 9;
		int detla400 = t / ad_400;
		int last400 = t % ad_400;
		
		t -= detla400 * ad_400;
		t -= 2 * 365;
		int cnt_29 = t / 365 / 4 - t / 365 / 100 + t / 365 / 400;
		t += 2 * 365;

		int pass_year = (t-cnt_29) / 365;
		int current_year = pass_year + detla400*400 + 1582;

		int last_day = t - pass_year * 365-cnt_29;
		int pass_month = getmonth(last_day,isyear29(current_year));
		int pass_day = last_day- monsadd[pass_month-1] + (isyear29(current_year) && pass_month==1);
		printf("%d %d %d",pass_day,pass_month,abs(current_year));
		printf("\n");
	}
	else
	{
			int detla400 = t / bc_400;
			int last400 = t % bc_400;
			
			t -= detla400 * bc_400;
			int cnt_29 = t / 365 / 4;
			int pass_year = (t-cnt_29) / 365;
			int current_year = pass_year + detla400*400 - 4713;
			if(current_year>=0)current_year++;
			int last_day = t - pass_year * 365-cnt_29;
			int pass_month = getmonth(last_day,isyear29(current_year));
			int pass_day = last_day - monsadd[pass_month-1];
			printf("%d %d %d",pass_day,pass_month,abs(current_year));
			if(current_year<0)printf(" BC");
			printf("\n");
	}
}
int main()
{
	freopen("julian.in","r",stdin);
	int q;
	long long time;
	freopen("julian.out","w",stdout);
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		scanf("%lld",&time);
		process(time);
	}
	
	//printf("->%d",bd);
	//cin>>bd;
	return 0;
}