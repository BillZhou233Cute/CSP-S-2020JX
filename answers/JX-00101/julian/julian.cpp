#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
#define re register
#define il inline
#define F(i,a,b) for(re int i=a,i##_end=b;i<=i##_end;++i)
#define UF(i,a,b) for(re int i=a,i##_end=b;i>=i##_end;--i)
template<typename T> il T rd(T&x)
{
	x=0;T f=1;char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=-1;
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	return x*=f;
}
#define openf(a) freopen(#a".in","r",stdin);freopen(#a".out","w",stdout)
typedef long long ll;
typedef unsigned long long ull;

const int Mon[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
bool runyear(ll y)
{
	if(y<0) return y%4==-1;
	else if(y<=1582) return y%4==0;
	else return (y%400==0)||((y%4==0)&&!(y%100==0));
}
int getmonth(ll&day,ll year)
{
	int month=1;while(day>=Mon[month]+(month==2)*(runyear(year))) day-=Mon[month]+(month==2)*(runyear(year)),++month;++day;
	return month;
}
void output(ll r)
{
	//from 4713BC,Jan 1st
	//format:day month year [BC]
	//1582.10.5~1582.10.14 not exist
	ll ye4=r/1461,day=r%1461;//lunar
	ll year=4*ye4-4713;
	if(day>=366) ++year,day-=366;
	if(day>=365) ++year,day-=365;
	if(day>=365) ++year,day-=365;
	if(year>=0) ++year;
	int month=getmonth(day,year);
	if(year<1582||(year==1582&&month<10)||(year==1582&&month==10&&day<5))
	{printf("%lld %d %lld%s\n",day,month,year>0?year:-year,year>0?"":" BC");return;}
	ll r0=r-(4712ll+1580)/4*1461ll+10;//from 1580.1.1
	year=(r0/(400*365+97))*400+1580;day=r0%(400*365+97);
	while(day>=365+runyear(year)) day-=365+runyear(year),++year;
	month=getmonth(day,year);
	printf("%lld %d %lld\n",day,month,year);
}
int main()
{
	openf(julian);
	int T;rd(T);while(T--) {ll r;rd(r);output(r);}
	return 0;
}
	
