#include<cstdio>
#include<iostream>
using namespace std;
#define M 
#define il inline
#define ri register int
il int read()
{
  int k=0;bool f=true;char ch=getchar();
  while(ch<'0'||ch>'9')
  {
    if(ch=='-')f=false;
    ch=getchar();
  }
  while(ch>='0'&&ch<='9')
    k=(k<<1)+(k<<3)+(ch^48),ch=getchar();
  return f?k:-k;
}
bool op;
int q,r,t,ans1,ans2,ans3;
int m[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int main()
{
  freopen("julian.in","r",stdin);
  freopen("julian.out","w",stdout);
  q=read();
  while(q--)
  {
    r=read(),op=false;
    if(r>=1721423)
    {
      ans2=0,r-=1721423;
      t=r/365;
      if((!(t%4)&&(t%100))||!(t%400))op=true;
      ans3=t;
      t*=365;
      t+=t/4-t/100+t/400;
      r-=t;
      if(r<0)r+=365+op,--ans3;
      if(!r)
      {
	printf("31 12 %d\n",ans3-1);
	continue;
      }
      do
      {
	r-=m[++ans2];
	if(ans2==2&&((!(ans3%4)&&(ans3%100))||!(ans3%400)))
	   ++r;
      }while(r>0);
      ans1=r+m[ans2];
      if(ans2!=1)--ans2;
      else ans2=12;
      printf("%d %d %d\n",ans1,ans2-1,ans3);
    }
    else
    {
      ans2=13;
      t=r/365;
      if(!(t%4))op=true;
      ans3=4713-t;
      t*=365,t+=t/4;
      r-=t;
      if(r<0)r+=365+op,++ans3;
      if(!r)
      {
	printf("1 1 %d\n",ans3+1);
	continue;
      }
      do
      {
	r-=m[--ans2];
	if(ans2==2&&!(ans3%4))
	   ++r;
      }while(r>0);
      ans1=m[ans2]-(r+m[ans2]);
      if(ans2!=12)++ans2;
      else ans2=1;
      printf("%d %d %d BC\n",ans1,ans2,ans3);
    }
  }
  return 0;
}
