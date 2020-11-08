#include<bits/stdc++.h>
#define IL inline
#define LL long long
using namespace std;
int y,m,d;LL x;
int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int d4=1461,d400=146097;
IL LL in(){
	char c;int f=1;
	while((c=getchar())<'0'||c>'9')
		if(c=='-') f=-1;
	LL x=c-'0';
	while((c=getchar())>='0'&&c<='9')
		x=x*10+c-'0';
	return x*f;
	}
IL int query1(int y,int m){
	if(m^2) return a[m];
	if(y%4==1) return a[m]+1;
	else return a[m];
	} 
void work1(){
	y=4713,m=1,d=1;
	LL cnt=x/d4;x%=d4;
	y-=4*cnt;int dm;
	while((dm=query1(y,m))<=x){
		x-=dm;
		if(m==12) m=1,--y;
		else ++m;
		}
	d+=x;
	printf("%d %d %d BC\n",d,m,y);
	}
IL int query2(int y,int m){
	if(m^2) return a[m];
	if(y%4==0) return a[m]+1;
	return a[m];
	}
void work2(){
	x-=1721424;
	y=1,m=1,d=1;
	LL cnt=x/d4;x%=d4;
	y+=4*cnt;int dm;
	while((dm=query2(y,m))<=x){
		x-=a[m];
		if(m==12) m=1,++y;
		else ++m;
		}
	d+=x;
	printf("%d %d %d\n",d,m,y);
	}
IL int query3(int y,int m){
	if(m^2) return a[m];
	if((y%100^0&&y%4==0)||(y%400==0)) return a[m]+1;
	else return a[m];
	}
void work3(){
	x-=2298884-10;
	y=1582,m=1,d=1;
	LL cnt=x/d400;x%=d400;
	y+=400*cnt;int dm;
	while((dm=query3(y,m))<=x){
		x-=dm;
		if(m^12)  ++m;
		else m=1,++y;
		}
	d+=x;
	printf("%d %d %d\n",d,m,y);
	}
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	int t=in();
	while(t--){
		x=in();
		if(x<=1721423) work1();
		else if(x<=2299160) work2();
		else work3();
		}
	return 0;
	}