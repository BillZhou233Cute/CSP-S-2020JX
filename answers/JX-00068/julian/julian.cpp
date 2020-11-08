#include<bits/stdc++.h>
using namespace std;
long long q;
long long  m,d;
long long y;
long long t;
void dp(long long x){
  if(x>=2298834)x+=10;
  if(x>=1721386){
    y=1;m=1;d=1;
    x-=1721386;
  }
  while(x>=146097){
    y+=400;
    x-=146097;
  }
  while(x>=365){
    if(y>0){
      if(x>365&&y%4==0&&(y%100!=0||y%400==0)){
	y++;
	x-=366;
      }
      else{
	y++;
	x-=365;
      }
      if(x==365&&y%400==0||y%100!=0&&y%4==0)
	break;
    }
    else{
      if(x>365&&(y%4==1&&y%100!=1)||y%400==1){
	y++;
	x-=366;
      }
      else {
	y++;
	x-=365;
      }
    }
  }
  while(x>=28){
    if(m!=2&&x<30)break;
    if(m==2){
      if(x>28&&(y>0&&(y%400==0||(y%4==0&&y%100!=0)))||(y<0&&(y%400==1||(y%4==1&&y%100!=1)))){
	x-=29;
	m++;
      }}
    if(m==2){
      if((y>0&&(y%4!=0||y%100!=0))||(y<0&&(y%4!=1||y%100!=1))){
	x-=28;
	m++;
      }
      if(x==28&&(y>0&&(y%400==0||(y%4==0&&y%100!=0)))||(y<0&&(y%400==1||(y%4==1&&y%100!=1))))
	break;
    }
    if((m==1||m==3||m==5||m==7||m==8||m==10||m==12)&&x>30){
      x-=31;
      m++;
    }
    if((m==4||m==6||m==9||m==11)&&x>=30){
      x-=30;
      m++;
    }
  }
  d+=x;
  if(y>0)cout<<d<<' '<<m<<' '<<y<<' '<<endl;
  if(y<0)cout<<d<<' '<<m<<' '<<abs(y)<<" BC"<<endl;
}
int main(){
  freopen("julian.in","r",stdin);
  freopen("julian.out","w",stdout);
  cin>>q;
  for(int i=1;i<=q;i++){
    y=-4713,m=1,d=1;
    cin>>t;
    if(t>30)t--;
    dp(t);
}
  return 0;
}
