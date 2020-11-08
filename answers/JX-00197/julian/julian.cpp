#include<iostream>
#include<cstdio>
#define int long long
using namespace std;
int Q,r;

inline int findmonth (int &x,int ty) {
	int res=1;
	if (x-31>=0) res++,x-=31;
	else return res;
	if (ty==0&&x-28>=0)	res++,x-=28;
	else if (ty==0)	return res;
	if (ty==1&&x-29>=0)	res++,x-=29;
	else if (ty==1)	return res;
	if (x-31>=0)	res++,x-=31;
	else return res;
	if (x-30>=0)	res++,x-=30;
	else return res;
	if (x-31>=0)	res++,x-=31;
	else return res;
	if (x-30>=0)	res++,x-=30;
	else return res;
	if (x-31>=0)	res++,x-=31;
	else return res;
	if (x-31>=0)	res++,x-=31;
	else return res;
	if (x-30>=0)	res++,x-=30;
	else return res;
	if (x-31>=0)	res++,x-=31;
	else return res;
	if (x-30>=0)	res++,x-=30;
	return res;
}

inline void calbc () {
	int x=r/1461;
	int rest=r-x*1461;
	int year=4713-x*4;
	int cnt=0;
	if (rest-366>=0)	rest-=366,year--;
	while (rest-365>=0&&cnt<=2) rest-=365,cnt++,year--;
	int ty= (year-1)%4==0 ? 1 : 0;
//	cout<<rest<<endl;
	int month=findmonth(rest,ty);
//	if (rest==0)	rest++;
	printf("%lld %lld %lld BC\n",rest,month,year);
}

inline void cal () {
//	cout<<"!"<<endl;
 	int x=r/1461;
	int rest=r-x*1461;
	int year=x*4+1;
	int cnt=0;
	while (rest-365>=0&&cnt<=3) rest-=365,cnt++,year++;
	int ty= year%4==0 ? 1 : 0;
	int month=findmonth(rest,ty);
	printf("%lld %lld %lld \n",rest,month,year);
}

signed main () {
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	scanf("%lld",&Q);
	while (Q--) {
		scanf("%lld",&r);r++;
		if (r<=1721424) {//计算公元前
			calbc();//cout<<"1"<<endl;
			continue;
		}
		r-=1721424;//公元后
		if (r>577737) r+=10;//消失日期之后加回去
		else {//在消失日期之前
			cal();//cout<<Q<<endl;
			continue;
		}
		r-=577460;
		int z=r/146097;//以400年的时间为单位
//		cout<<" "<<r<<endl;
		int rest=r-z*146097;
//		cout<<Q<<endl;
		int x=rest/36524;//以100年的时间为单位
		rest-=x*36524;
		int y=rest/1461;//4年时间为单位
		rest-=y*1461;
		int year=z*400+x*100+y*4+1582,cnt=((year%400==0)||(year%4==0&&year%100!=0)) ? 366 : 365;
//		cout<<year<<endl;
		while (rest-cnt>=0)	{
			rest-=cnt,year++;//cout<<year<<"!"<<cnt<<endl;
			cnt=((year%400==0)||(year%4==0&&year%100!=0)) ? 366 : 365;
		}
//		cout<<rest<<endl;
		int ty= ((year%400==0)||(year%4==0&&year%100!=0)) ? 1 : 0;
		int month=findmonth(rest,ty);
		if (rest==0)	rest=1;
		printf("%lld %lld %lld\n",rest,month,year);
	}
	return 0;
}
