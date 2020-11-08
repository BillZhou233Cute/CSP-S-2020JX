#include<cstdio>
#include<cstring>
#include<cctype>
#define int long long
int q;
inline int isrun(int year){
	if(year<0){
		year=-year;
		if((year-1)%4==0) return true;
		return false;
	}
	if(year>1582) return (year%4==0&&year%100!=0)||year%400==0;
	return year%4==0;
}
int days[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
inline void addday(int &year,int &month,int &day){
	day++;int quan=0;
	if(month==2&&isrun(year)) quan=1;
	if(day>days[month]+quan) day=1,month++;
	if(month>12) year++,month=1;
}
signed main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	scanf("%lld",&q);
	while(q--){
		int year=-4713,month=1,day=1,n;
		scanf("%lld",&n);n--;
		while(n>0){
			addday(year,month,day);
			n--;
			if(year==0){
				year=1;day=1;month=1;break;
			}
		}
		n++;
		while(n>0){
			addday(year,month,day);
			if(year==1582&&month==10&&day==5) day=15;
			n--;
		}
		if(year<0)
			printf("%lld %lld %lld BC\n",day,month,-year);
		else
			printf("%lld %lld %lld\n",day,month,year);
	}
	return 0;
}
