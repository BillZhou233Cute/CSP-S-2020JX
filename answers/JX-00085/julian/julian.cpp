#include<bits/stdc++.h>
using namespace std;
inline long long read(){
  long long x=0,f=1;
  char ch=getchar();
  while(ch<'0'||ch>'9')
  {
    if(ch=='-') f=-1;
    ch=getchar();
  }
  while(ch>='0'&&ch<='9')
  {
    x=x*10+ch-'0';
    ch=getchar();
  }
  return x*f;
}
int main(){
  freopen("julian.in","r",stdin);
  freopen("julian.out","w",stdout);
  long long n,x;
  n=read();
  for(int i=1;i<=n;i++)
  {
    x=read();
    long long year=-4713,m=1,d=1;
    for(int i=x;i>0;i--)
    {
      d++;
      if((m==1||m==3||m==5||m==7||m==8||m==10||m==12)&&d>31){m++;d=1;}
      if((m==4||m==6||m==9||m==11)&&d>30){m++;d=1;}
      if(m==2){
        if((year<0&&abs(year)%4==1)||(year>0&&year<1582&&year%4==0)||(year>1582&&year%4==0&&year%100!=0)||(year>1582&&year%100==0&&year%400==0)){
          if(d>29){m++;d=1;}
	}
        else if(d>28){m++;d=1;}
      }
      if(m>12){year++;m=1;}
      if(year==1582&&m==10&&d>4)d+=10;
      if(year==0)year=1;
    }
    if(year<0) cout<<d<<" "<<m<<" "<<abs(year)<<" BC";
    else cout<<d<<" "<<m<<" "<<year;
  }
  return 0;
}
