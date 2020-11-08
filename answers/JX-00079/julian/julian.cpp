#include<cstdio>
#define ri register long long 
#define ll long long
using namespace std;
ll n,day,month,year;
inline ll read(){
	ri x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
inline void solve1(){//run nian
	if(n<=30) day=n,month=0;
	if(n>=31&&n<=59) day=n-31,month=1;
	if(n>=60&&n<=90) day=n-60,month=2;
	if(n>=91&&n<=120) day=n-91,month=3;
	if(n>=121&&n<=151) day=n-121,month=4;
	if(n>=152&&n<=181) day=n-152,month=5;
	if(n>=182&&n<=212) day=n-182,month=6;
	if(n>=213&&n<=243) day=n-213,month=7;
	if(n>=244&&n<=273) day=n-244,month=8;
	if(n>=274&&n<=304) day=n-274,month=9;
	if(n>=305&&n<=334) day=n-305,month=10;
	if(n>=335&&n<=365) day=n-335,month=11;
}
inline void solve2(){//pin nian
	if(n<=30) day=n,month=0;
	if(n>=31&&n<=58) day=n-31,month=1;
	if(n>=59&&n<=89) day=n-59,month=2;
	if(n>=90&&n<=119) day=n-90,month=3;
	if(n>=120&&n<=150) day=n-120,month=4;
	if(n>=151&&n<=180) day=n-151,month=5;
	if(n>=181&&n<=211) day=n-181,month=6;
	if(n>=212&&n<=242) day=n-212,month=7;
	if(n>=243&&n<=272) day=n-243,month=8;
	if(n>=273&&n<=303) day=n-273,month=9;
	if(n>=304&&n<=333) day=n-304,month=10;
	if(n>=334&&n<=364) day=n-334,month=11;
}
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	ri Q=read();
	while(Q--)
	{
		n=read(),day=0,month=0,year=0;//过了几天/月/年
		if(n<1721424)
		{
			ri k=n/1461;
			year=4*k;
			n-=k*1461;
			if(n<=365) solve1();
			else
			{
				n-=366;
				year++;
				k=n/365;
				year+=k;
				n-=k*365;
				solve2();
			}
			printf("%lld %lld %lld BC\n",day+1,month+1,4713-year);
		}
		else{
		if(n<=2299160)
		{
			n-=1721424;
			ri k=n/1461;
			year=4*k;
			n-=k*1461;
			if(n<=1095)
			{
				k=n/365;
				year+=k;
				n-=k*365;
				solve2();
			}
			else
			{
				n-=1095;
				year+=3;
				solve1();
			}
		}
		else
		{
			n+=10;
			n-=1721424;
			ri k=n/1461;
			year=4*k;
			n-=k*1461;
			if(n<=1095)
			{
				k=n/365;
				year+=k;
				n-=k*365;
				solve2();
			}
			else
			{
				n-=1095;
				year+=3;
				solve1();
			}
		}
		day++,month++,year++;
		day-=year/100-15;
		while(day<=0)
		{
			if(month-1==1||month-1==3||month-1==5||month-1==7||month-1==8||month-1==10||month-1==12) month--,day+=31;
			if(month-1==4||month-1==6||month-1==9||month-1==8||month-1==11) month--,day+=30;
			if(month-1==2){
				if(year%4||!(year%100)) month--,day+=28;
				else month--,day+=29;}
			if(month<=0)  year--,month+=12;
		}
		printf("%lld %lld %lld\n",day,month,year);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}	
	