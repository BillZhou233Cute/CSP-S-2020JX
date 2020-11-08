//Duo Ce Bu Qing Ling, Bao Ling Liang Hang Lei! 
#include <iostream>
#include <cstdio>
using namespace std;
long long a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z;
long long mo[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
long long pdts(long long,long long);
void print(long long,long long,long long);
int main()
{
  freopen("julian.in","r",stdin);
  freopen("julian.out","w",stdout);
  //  cout<<pdts(-4713,2)<<endl<<pdts(-4712,2)<<endl<<pdts(-4711,2)<<endl;
  cin>>q;
  while(q--)
    {
      cin>>r;
      for(y=-4713;;y++)
	{
	  if(y==0) continue;
	  if(r>36600000)
	    {
	      for(k=y;k<y+100000;k++)
		r-=((pdts(k,2)==29)?366:365);
	      y+=99999;
	      continue;
	    }
	  if(r>3660000)
	    {
	      for(k=y;k<y+10000;k++)
		r-=((pdts(k,2)==29)?366:365);
	      y+=9999;
	      continue;
	    }
	  if(r>366000)
	    {
	      for(k=y;k<y+1000;k++)
		r-=((pdts(k,2)==29)?366:365);
	      y+=999;
	      continue;
	    }
	  if(r>36600)
	    {
	      for(k=y;k<y+100;k++)
		r-=((pdts(k,2)==29)?366:365);
	      y+=99;
	      continue;
	    }
	  if(r>3660)
	    {
	      for(k=y;k<y+10;k++)
		r-=((pdts(k,2)==29)?366:365);
	      y+=9;
	      continue;
	    }
	  if(r>((pdts(y,2)==29)?366:365))
	    {
	      r-=((pdts(y,2)==29)?366:365);
	      continue;
	    }
	  for(m=1;m<=12;m++)
	    {
	      if((y==1582)&&(m==10))
		{

		  if(r>=21)
		    {
		      r-=21;
		    }
		  else
		    {
		      if(r<=3)
			{
			  print(y,m,r+1);
			}
		      else
			{
			  print(y,m,r+11);
			}
		      o=1;
		      break;
		    }
		}
	      else
		{
		  if(r>=pdts(y,m))
		    {
		      r-=pdts(y,m);
		    }
		  else
		    {
		      print(y,m,r+1);
		      o=1;
		      break;
		    }
		}
	    }
	  if(o)
	    {
	      o=0;
	      break;
	    }
	}
    }
  return 0;
}
long long pdts(long long year,long long month)
{
  return ((month!=2)?mo[month]:(((year>0)?((((year%4==0)&&(year%100!=0))||(year%400==0))?true:false):(((((-year+3)%4==0)&&((-year+3)%100!=0))||((-year+3)%400==0))?true:false))?29:28));
}
void print(long long y,long long m,long long d)
{
  cout<<d<<' '<<m<<' '<<((y>0)?y:-y)<<((y>0)?"":" BC")<<endl;
  return;
}
