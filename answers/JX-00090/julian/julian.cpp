#include<cstdio>
using namespace std;
inline int read()
{
  int res;
  char c;
  while((c=getchar())<'0'||c>'9');
  res=c^48;
  while((c=getchar())>='0'&&c<='9')
  res=(res<<3)+(res<<1)+(c^48);
  return res;
}
int data[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main()
{
  freopen("julian.in","r",stdin);
  freopen("julian.out","w",stdout);
  int t=read(),n,year,month,cnt;
  while(t)
  {
    t--;
    n=read();
    cnt=1;
    year=0;
    month=0;
    data[2]=28;


    if(n<=1721423)//BC儒略历
    {
      while(n>=1461)
      {
	n-=1461;
	year+=4;
      }
      while(n>=365)
      {
	if(year%4==0)
        {
	  if(n==365) break;
	  n-=366;
	}
	else n-=365;
	year++;
      }
      if(year%4==0) data[2]=29;
      while(n>=data[cnt])
      {
	n-=data[cnt];
	month++;
	cnt++;
      }
      printf("%d %d %d BC",n+1,month+1,4713-year);
    }


    if(n>1721423&&n<=2299160)//儒略历
    {
      n-=1721423;
      year=1;
      while(n>=1461)
	{
	  n-=1461;
	  year+=4;
	}
      while(n>=365)
	{
	  if(year%4==0)
	    {
	      if(n==365) break;
	      n-=366;
	    }
	  else n-=365;
	  year++;
	}
      if(year%4==0) data[2]=29;
      while(n>=data[cnt])
	{
	  n-=data[cnt];
	  month++;
	  cnt++;

	}
      printf("%d %d %d",n,month+1,year);
    }


    if(n>2299160)//格里高利历
    {
      n-=2299161;
      year=1582;
      n+=288;
      while(n>=1461)
      {
	n-=1461;
	year+=4;
      }
      while(n>=365)
	{
	  if((year%4==0&&year%100!=0)||(year%400==0))
	    {
	      if(n==365) break;
	      n-=366;
	    }
	  else n-=365;
	  year++;
	}
      if((year%4==0&&year%100!=0)||(year%400==0)) data[2]=29;
      while(n>=data[cnt])
	{
	  n-=data[cnt];
	  month++;
	  cnt++;
	}
      printf("%d %d %d",n,month+1,year);
    }


  }


  return 0;
}
