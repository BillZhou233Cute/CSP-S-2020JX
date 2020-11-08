#include<bits/stdc++.h>
using namespace std;
#define reg register
typedef long long ll;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)
static char buf[100000],*p1=buf,*p2=buf;
inline int read(void){
	reg bool f=false;
	reg char ch=getchar();
	reg int res=0;
	while(!isdigit(ch))f|=(ch=='-'),ch=getchar();
	while(isdigit(ch))res=10*res+(ch^'0'),ch=getchar();
	return f?-res:res;
}

const int days[]={0,31,28,31,30,31,30,31,31,30,31,30,31};

int q;

inline void solve(reg ll r){
	int year,month,day;
	if(r>=2451911){
		r-=2451911;
		year=2001,month=1,day=1;
		reg ll cnt400=r/146097;
		year+=cnt400*400;
		r-=cnt400*146097;
		while(r--){
			reg bool f=((year%100==0)?(year%400==0):(year%4==0));
			if(r>=365+f)
				r-=365+f-1,++year;
			else{
				++day;
				reg bool f=(month==2)&&((year%100==0)?(year%400==0):(year%4==0));
				if(day>days[month]+f)
					day=1,++month;
				if(month>12)
					month=1,++year;
			}
		}
	}
	else if(r>=2299161){
		year=1582,month=10,day=15;
		r-=2299161;
		year+=(r/146097)*400,r%=146097;
		while(r--){
			reg bool f=(month==2)&&((year%100==0)?(year%400==0):(year%4==0));
			++day;
			if(day>days[month]+f)
				day=1,++month;
			if(month>12)
				month=1,++year;
		}
	}
	else if(r>=1721424){

		r-=1721424;
		year=1,month=1,day=1;

		reg ll cntR=r/1461;

		year+=cntR*4,r-=cntR*1461;
		while(r--){
			reg bool f=(month==2)&&(year%4==0);
			++day;
			if(day>days[month]+f)
				day=1,++month;
			if(month>12)
				month=1,++year;
		}
	}
	else{
		year=-4713,month=1,day=1;
		reg ll cntR=r/1461;
		year+=cntR*4,r-=cntR*1461;
		while(r--){
			reg bool f=((-year)%4==1)&&(month==2);
			++day;
			if(day>days[month]+f)
				day=1,++month;
			if(month>12)
				month=1,++year;
		}
	}
	if(year<0)
		printf("%d %d %d BC\n",day,month,-year);
	else
		printf("%d %d %d\n",day,month,year);
	return;
}

int main(void){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);

	q=read();
	while(q--){
		ll r=read();
		solve(r);
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
