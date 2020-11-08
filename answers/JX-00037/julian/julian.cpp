#include <iostream>
#include <stdio.h>
using namespace  std;
int y=-4713,m=1,d=1,n,a[1000001];
bool run(int y){
	if(y<0&&(-y)%4==1||y>0&&y<=1582&&y%4==0)return true;
	else if(y>1582){
		if(y%4==0&&y%100!=0||y%400==0)return true;
		else return false;
	}
	else return false;
	
	}
int month(int m,int y ){
	bool c=run(y);
	if(c==1&&m==2)return 29;
	else if(m==2)return 28;
	else if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)return 31;
	else return 30;
}
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	bool fdy=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int j=0;j<n;j++){
		for(int i=0;i<a[j];i++){
			int mdays;
			mdays=month(m,y);
			d++;
			if(y==1582&&m==10&&d==5)d=15;
			if(d>mdays){
				m++;
				d=1;
			}
			if(m>12){
				m=1;
				y++;
			}
			if(y==0)y++;
		}
		if(y<0){
			y=-y;
			fdy=1;
			}
		cout<<d<<" "<<m<<" "<<y;
		if(fdy)cout<<" "<<"BC";
		cout<<endl;	
		y=-4713;
		m=1;
		d=1;
		fdy=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*








*/