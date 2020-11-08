#include <bits/stdc++.h>
using namespace std;
const int N=1e5+3,K=2305814,M=146097;
long long n,x;
int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
bool ruin(int year)
{
	if(year<0) year+=1;
    if(year<1582)
	{
		if(year%4==0) return 1;
		return 0;
	}
	if(year%400==0) return 1;
    if(year%4==0&&year%100!=0) return 1;
	return 0;
}
int yearday(int year)
{
	if(year==1582) return 355;
	if(ruin(year)) return 366;
	return 365;
}
int monthday(int year,int month)
{
	if(year==1582&&month==10) return 21;
	if(ruin(year)&&month==2) return 29;
	return a[month];
}
void find(long long day)
{
	int y=-4713,m=1,d=1,bc=1;
	while(day>yearday(y))
	{
		day-=yearday(y);
		y++;
		if(y==0) y++;
	}
	while(day>monthday(y,m))
	{
		day-=monthday(y,m);
		m++;
	}
	d+=day;
        if(y==1582&&m==10&&d>4&&d<15) d+=10;
	if(y>0) bc=0;
	if(bc==1) y=-y;
	cout<<d<<' '<<m<<' '<<y;
	if(bc) cout<<" BC";
	cout<<endl;
}
void better(int x)
{
	int y=1601,m=1,d=1;
	x-=2305814;
	y+=(x/146097)*400;
	x=x%146097;
	while(x>yearday(y))
	{
		x-=yearday(y);
		y++;
		if(y==0) y++;
	}
	while(x>monthday(y,m))
	{
		x-=monthday(y,m);
		m++;
	}
	d+=x;
	cout<<d<<' '<<m<<' '<<y<<endl;
}
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		if(x<K) find(x);
		else better(x);
	}
	return 0;
}
