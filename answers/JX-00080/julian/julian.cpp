#include <bits/stdc++.h>
#define il inline
#define Max 100005
#define ll long long
#define int ll
using namespace std;
il int read()
{
	char c=getchar();
	int x=0,f=1;
	while(c>'9'||c<'0')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
//		c=getchar();
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
int T,n,relay;
il int month(int &x,int flg)
{
	if(x<=31) return 1;
	x-=31;
	if(x<=28+flg) return 2;
	x-=28+flg;
	if(x<=31) return 3;
	x-=31;
	if(x<=30) return 4;
	x-=30;
	if(x<=31) return 5;
	    x-=31;
	if(x<=30) return 6;
	    x-=30;
	if(x<=31) return 7;
	    x-=31;
	if(x<=31) return 8;
	    x-=31;
	if(x<=30) return 9;
	    x-=30;
	if(x<=31) return 10;
	    x-=31;
	if(x<=30) return 11;
	    x-=30;
	return 12;
}
il int year2(int x)
{
	int a=x/146097,b=x%146097;
	a=a*400;//cout<<a<<" qwq\n";
	if(b>7670) b-=1;
	int c=b/36524,d=b%36524;
	a=a+100*c;//cout<<a<<" qwq2\n";
	int e=d/1461,f=d%1461;
	if(f>366&&b!=7670) f=f/366;
	else f=0;
	a=a+4*e+f;//cout<<a<<" qwq3\n";
	relay=d%1461-f*365-(f>0);
//	cout<<e<<' '<<f<<' '<<relay<<" iqwq\n";
	return a;
}
il int year(int x)
{
	int a=x/1461,b=x%1461;
	if(b>366) b=(b-1)/365;
	else b=0;
	a=a*4-4712+b;
	relay=x%1461-b*365-(b>0);
	return a;
}
il void solve(int x)
{
	if(x<=2299162)
	{
		int y=year(x);
		int mn=month(relay,y%4==0);
		if(y<=0) y-=1;
		printf("%lld %lld %lld",relay,mn,y<0?-y:y);
		if(y<0) puts(" BC");
		else puts("");
		return;
	}
	if(x<=2299239)
	{
		relay=x-2298884+10;
		int mn=month(relay,0);
		printf("%lld %lld %lld\n",relay,mn,1582ll);
		return ;
	}
	x-=2298153-10-1;
	int y=year2(x)+1580;
	int mn=month(relay,y%400==0||(y%4==0&&y%100!=0));
	printf("%lld %lld %lld\n",relay,mn,y);
}
signed main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	T=read();
	while(T--)
	{
		n=read()+1;
		solve(n);
	}
}
