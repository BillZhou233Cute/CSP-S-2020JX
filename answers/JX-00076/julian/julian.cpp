#include <iostream>
#include <cstdio>
using namespace std;
struct node{
	int y,d,n;
}ans[100010];
int tail=1;
int back_day(int month,int year)
{
	if(month==1||month==3||month==5||month==7||month==8||month==10||month==12) return 31;
	else if(month==4||month==6||month==9||month==11) return 30;
	else if((year>1582&&year%4==0&&year%100!=0)||(year%400==0&&year>0)) return 29;
	else if(year<=1582&&year%4==0&&year>0) return 29;
	else if(year<0&&((-year)%4==1)) return 29;
	else return 28;
}

int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	int t=0,s=0;
	cin>>s;
	while(s--)
	{
		cin>>t;
		int year=-4713,month=1,day=1;
		for(int i=1;i<=t;i++)
		{
			if(year==1582&&month==10&&(day>=5&&day<=14)) i--;
			day++;
			if(day>back_day(month,year)) month++,day=1;
			if(month>12) year++,month=1,day=1;
			if(year==0) year=1,month=1;
		}
		ans[tail].y=year,ans[tail].n=month,ans[tail].d=day;
		tail++;
	}
	for(int i=1;i<=tail-1;i++)
	{
		cout<<ans[i].d<<" "<<ans[i].n;
		if(ans[i].y<0) cout<<" "<<(-ans[i].y)<<" "<<"BC"<<endl;
		else cout<<" "<<ans[i].y<<endl;
	}
	return 0;
}