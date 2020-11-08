#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll year400=365*400+100-3;
const ll year400special=365*400+100;
int q;
int year=0,month,date;
int ansyear=-4713,ansmonth,ansdate;
int month_normal[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int month_run[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
bool is_runnian(int y)
{
	if (y<0)
	{
		y=-y+3;
		if (y%4==0)
			return true;
		return false;
	}
	if (y<1582)
		if (y%4==0)
			return true;
	if (y>1582)
		if ((y%400==0) || (y%4==0 && y%100!=0))
			return true;
	return false;
}
int get_year_length(int y)
{
	if (y==1582)
		return 355;
	if (is_runnian(y))
		return 366;
	return 365;
}
bool larger_year(int y,long long rest)
{
	return rest>=get_year_length(y);
}
int get_month(int y,int rest)
{
	int ans=1;
	if (!is_runnian(y))
	{
		while (rest-month_normal[ans]>=0)
		{
			rest-=month_normal[ans];
			ans++;
		}
		return ans;
	}
	while (rest-month_run[ans]>=0)
	{
		rest-=month_run[ans];
		ans++;
	}
	return ans;
}
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	scanf("%d",&q);
	while (q--)
	{
		ll r;
		ansyear=-4713;
		scanf("%lld",&r);
		while (r>=year400special && ansyear+400<1582)
		{
			r-=year400special;
			ansyear+=400;
		}
		while (ansyear<=1582 && larger_year(ansyear,r))
		{
			r-=get_year_length(ansyear);
			ansyear++;
		}
		year=r/year400*400;
		r%=year400;
		ansyear+=year;
		if (ansyear>0)
			ansyear++;
		while (larger_year(ansyear,r))
		{
			r-=get_year_length(ansyear);
			ansyear++;
		}
		if (ansyear==1582)
			r+=10;
		ansmonth=get_month(ansyear,r);
		for (int i=1;i<ansmonth;i++)
		{
			if (is_runnian(ansyear))
				r-=month_run[i];
			else
				r-=month_normal[i];
		}
		ansdate=r+1;
		if (ansyear<0)
			printf("%d %d %d BC\n",ansdate,ansmonth,-ansyear);
		else
			printf("%d %d %d\n",ansdate,ansmonth,ansyear);
	}
	return 0;
}
