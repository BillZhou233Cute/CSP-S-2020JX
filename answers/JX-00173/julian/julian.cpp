#include<bits/stdc++.h>
using namespace std;
int n,x;
int y,m,d,p;
int pd(int k){
	if(k==1||k==3||k==5||k==7||k==8||k==10||k==12) return 1;
	else return 0;
}
int pd1(int k){
	if((k-1)%4==0) return 1;
	else return 0;
}
int pd2(int k){
	if(k%4==0) return 1;
	else return 0;
}
int pd3(int k){
	if(k%400==0||(k%4==0&&k%100!=0)) return 1;
	else return 0;
}
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	cin>>n;
	while(n--){
		p=-1;
		y=4713;
		m=1;
		d=1;
		cin>>x;
		while(x--){
			if(y==1&&m==12&&d==31&&p==-1){
				p=1;
				m=1;
				d=1;
				continue;
			}
			d++;
			if(p==-1){
				if(d>29&&pd1(y)==1&&m==2){
					d=1;m++;continue;
				}
				else if(d>28&&m==2&&pd1(y)==0){
					d=1;m++;continue;
					
				}
				else if(pd(m)==1&&d>31){
					d=1;m++;
				}
				else if(d>30&&pd(m)==0){
					d=1;m++;
				}
				if(m>12){y--;m=1;}
			}
			else{
				if(d==5&&m==10&&y==1582){
					d=15;
					continue;
				}
				if(y<=1582){
					if(d>29&&pd2(y)==1&&m==2){
						d=1;m=3;
						continue;
					}
					else if(d>28&&m==2&&pd2(y)==0){
						d=1;m=3;continue;
					}
					else if(pd(m)==1&&d>31){
						d=1;m++;
					}
					else if(d>30&&pd(m)==0){
						d=1;m++;
					}
					if(m>12){y++;m=1;}
					continue;
				}
				if(d>29&&pd3(y)==1&&m==2){
					d=1;m=3;continue;
				}
				else if(d>28&&m==2&&pd3(y)==0){
					d=1;m=3;continue;
				}
				if(pd(m)==1&&d>31){
					d=1;m++;
				}
				else if(d>30&&pd(m)==0){
					d=1;m++;
				}
				if(m>12){y++;m=1;}
			}
		}
		cout<<d<<" "<<m<<" "<<y;
		if(p==-1){cout<<" "<<"BC";}
		cout<<endl;
	}
}

