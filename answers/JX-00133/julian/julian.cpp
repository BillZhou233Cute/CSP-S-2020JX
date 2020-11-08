#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
using namespace std;

int a[100010];
int mp[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int mr[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};

bool check(int y,int m,int d){
	return y>1582||(y==1582&&(m>10||(m=10&&d>4)));
}

inline int read(){
	char ch;
	int x=0;
	ch=getchar();
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x;
}

void find(long long n){
	bool fl=1;
	long long y=-4713,m=1,d=1;
	int c=4;
	while(n){
		if(y<=1582){//julian calendar
			if(c==4){//366 days
				if(n>=366){
					n-=366;//delect
					y++;//year
					c++;
				}
				else if(n>=mr[m]){
					n-=mr[m];//delect
					m++;//month
				}
				else {
					d+=n;//date
					n=0;//break(n-=n)
				}
				
			}
			else{//365 days
				if(n>=365){
					n-=365;//delect
					y++;//year
					c++;
				}
				else if(n>=mp[m]){
					n-=mp[m];//delect
					m++;//month
				}
				else {
					d+=n;//date
					n=0;//break(n-=n)
				}
			}
			if(c==5)c=1;//366 becomes 365
			if(y==0)y++;//impossible
		}
//---------------------------------------------------		
		else if(y>=1582){//normal calendar
			if((c==4&&(y%100))||!(y%400)){
				//c==4:366days
				//y%100 not YY00 years
				//!(y%400):can be 400s
				if(n>=366){//366days
					n-=366;
					y++;
					c++;
				}
				else if(n>=mr[m]){
					n-=mr[m];
					m++;
				}
				else {
					d+=n;
					n=0;
				}
				
			}
			else{
				if(n>=365){
					n-=365;
					y++;
					c++;
				}
				else if(n>=mp[m]){
					n-=mp[m];
					m++;
				}
				else {
					d+=n;
					n=0;
				}
			}
			if(c==5)c=1;
		}
		if(check(y,m,d)&&fl){
			n+=10;
			fl=false;
		}//dates which are delected
	}
	
	
	if(y<0){
		cout<<d<<" "<<m<<" "<<abs(y)<<" "<<"BC"<<endl;
	}
	else{
		cout<<d<<" "<<m<<" "<<y<<endl;
	}
	
	
}
//---------main function---------//
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	
	int Q;
	Q=read();
	for(int i=0;i<Q;i++){
		a[i]=read();
	}
	
	for(int i=0;i<Q;i++){
		find(a[i]);
	}
	return 0;	
}