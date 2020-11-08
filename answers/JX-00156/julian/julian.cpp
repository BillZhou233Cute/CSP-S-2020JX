#include<bits/stdc++.h>
using namespace std;
int n;
int oy=-4713,om=1,od=1;
long long add;

void f(int add){
	int y=oy,m=om,d=od;
	int ch1=add/146097;
	add=add%146097;
	int yt=y;
	y+=ch1*400;
	if(y>=0) y+=1;
	while(add>=36524){
		yt=y;
		if(y<0) yt++;
		if((400-yt%400)<100||yt%400==0){
			if(add>=36525){
				y+=100;
				add-=36525;
			}
		}else{
			y+=100;
			add-=36524;
		}
		if(y>=0&&yt<=0) y+=1;
	}
	while(add>=1460){
		yt=y;
		if(y<0) yt++;
		if((400-yt%400)<4||yt%400==0){
			if(add>=1461){
				y+=4;
				add-=1461;
			}
		}else if((100-yt%100)<4||yt%100==0){
			y+=4;
			add-=1460;
		}else{
			if(add>=1461){
				y+=4;
				add-=1461;
			}
		}
		if(y>=0&&yt<=0) y+=1;
	}
	while(add>=365){
		yt=y;
		if(y<0) yt++;
		if(yt%400==0){
			y+=1;
			add-=366;
		}else if(yt%100==0){
			y+=1;
			add-=365;
		}else if(yt%4==0){
			y+=1;
			add-=366;
		}else{
			y+=1;
			add-=365;
		}
		if(y>=0&&yt<=0) y+=1;
	}
	while(add>=28){
		yt=y;
		if(m==1||m==3||m==5||m==7||m==8||m==10||m==12){ if(add>=31){
			add-=31;
			m++;
			if(m>12){
				y++;
				m=1;
			}
			if(y>=0&&yt<0) y+=1;
			yt=y;
		}else break;
	}
		if(m==4||m==6||m==9||m==11) {if(add>=30){
			add-=30;
			m++;
		}else break;
	}
		if(y<0) yt++;
		if(m==2&&add>=28){
			if(yt%4!=0){
				m++;
				add-=28;
			}else if(yt%400==0){
				if(add>=29){
					m++;
					add-=29;
				}else break;
			}else if(yt%100==0){
				m++;
				add-=28;
			}else{
				if(add>=29){
					m++;
					add-=29;
				}else break;
			}
		}
		if(m==2&&add<29&&(yt%400==0||yt%100!=0)&&yt%4==0){
			d+=add;
			add=0;
		}
	}
	d+=add;
	cout<<d<<" "<<m<<" ";
	if(y<0){
		y=0-y;
		cout<<y<<" BC"<<endl;
	}
	cout<<"y"<<endl;
}

int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>add;
		f(add);
	}
}