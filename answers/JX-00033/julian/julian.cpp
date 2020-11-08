#include<queue>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int days[13]={29,31,28,31,30,31,30,31,31,30,31,30,31};
int n,S,year=-4713,month=1,day=1;
bool runnian(int x){
	if(x<0){x=abs(x)-1;if(x%4==0) return true;}
	else{
		if(x%400==0) return true;
		else
			if(x%4==0){
				if(x<=1582) return true;
				if(x%100==0) return false;
				else return true;
			}
	}
	return false;
} 
void getout(){
	printf("%d %d ",day,month);
	if(year<0){year*=-1;printf("%d BC\n",year);}
	else printf("%d\n",year);
	return;
}
void Year(){
	if(year==-1){year=1;return;}
	else year+=1;
	return;
}
void Month(){
	if(month==12){month=1;Year();return;}
	else month+=1;
	return;
}
int er(){
	if(year==1582&&month==10) return 21;
	if(month==2) {
	    if(runnian(year)) return days[0];
		else return days[2];
	}
	return days[month];
}
int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	S=read();
	while(S--){
		day=1;month=1;year=-4713;
		n=read();
		day+=n;
		while(1){
			int D=er();
			if(day<=D){
				if(year==1582&&month==10&&day>5) day+=11;
				break;
			}
			day-=D;
			Month();
		}
		getout();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}