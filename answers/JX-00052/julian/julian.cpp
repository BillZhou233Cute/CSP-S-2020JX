#include<bits/stdc++.h>
using namespace std;
#define N 1007
#define M 1000007
#define LL long long
int Const=2299160; //r_i-=Const+1;
namespace Julian{
    int type[N]={0,1,-1,1,0,1,0,1,1,0,1,0,1};
    int base=-4716,year,month,day;

    void reset(){
	year=-4712,month=1,day=1;
    }
    int run(int x){
	return x/4;
    }
    int pingnian(int l,int r){
	l-=base,r-=base;
	int rn=run(r)-run(l-1);
	return (r-l+1)-rn;
    }
    inline void chkday(int x){
	if(day>x)day=1,month++;
    }
    void travel(int times)
    {
	while(times){
	    day++; times--;
	    if(month==2){
		if(year%4==0)chkday(29);
		else chkday(28);
	    }
	    else{
		if(type[month]==1)chkday(31);
		else chkday(30);
	    }
	    if(month==13)year++,month=1;
	}
    }
    void solve(LL times){
	reset();
	while(times>=366){
	    int dlt=times/366; times%=366;
	    int ping=pingnian(year,year+dlt-1);
	    year+=dlt,times+=ping;
	}
	travel(times);
	if(year>0)printf("%d %d %d\n",day,month,year);
	else printf("%d %d %d BC\n",day,month,-(year-1));
    }
}
namespace Gregorian
{
    int type[N]={0,1,-1,1,0,1,0,1,1,0,1,0,1};
    int base=1580,year,month,day;
    void reset(){
	year=1582,month=10,day=15;
    }
    int run(int x){
	return x/4-x/100+x/400;
    }
    int pingnian(int l,int r){
	//l-=base,r-=base;
	int rn=run(r)-run(l-1);
	return (r-l+1)-rn;
    }
    inline void chkday(int x){
	if(day>x)day=1,month++;
    }
    void travel(int times)
    {
	while(times){
	    day++; times--;
	    if(month==2){
		if(year%400==0||(year%4==0&&year%100!=0))chkday(29);
		else chkday(28);
	    }
	    else{
		if(type[month]==1)chkday(31);
		else chkday(30);
	    }
	    if(month==13)year++,month=1;
	}
    }
    void solve(LL times){
	reset();
	while(times>=366){
	    int dlt=times/366; times%=366;
	    int ping=pingnian(year+1,year+dlt);
	    year+=dlt,times+=ping;
	}
	travel(times);
	printf("%d %d %d\n",day,month,year);
    }
}

int main()
{
    freopen("julian.in","r",stdin);
    freopen("julian.out","w",stdout);
    LL r;
    int m;
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
	scanf("%lld",&r);
	if(r<=Const){
	    Julian::solve(r);
	}else{
	    Gregorian::solve(r-(Const+1));
	}
    }
    return 0;
}
    
	
	
