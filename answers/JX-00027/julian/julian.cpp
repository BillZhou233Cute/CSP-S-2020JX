#include <iostream>
#include <cstdio>
using namespace std;
int q;
int yue[14]={0,30,29,31,30,31,30,31,31,30,31,30,31};
int nian(int k)
{
  if(k%4==1) return 366;
  else return 365;
}
int nian1(int u)
{
  if(u%400==0||u%4==0&&u%100!=0) return 366;
  else return 365;
}
int main()
{
   freopen("julian.in","r",stdin);
   freopen("julian.out","w",stdout);
  cin>>q;
  for(int i=1;i<=q;i++)
    {
int x=4713,y=1,z=1,r;
 bool f=0,ans=1;
      cin>>r;
      if(r>1721426)
	{
	  x=1;
	  r-=1721426;
      if(r<=30) 
	{
	cout<<z+r<<" "<<y<<" "<<x<<" "<<endl;  
	continue;
	}
	  if(r>=366)
	    {
	      while(r>nian1(x))
		{
		  f=1;
		  r-=nian1(x);
		  x++;
		  ans++;
		}
	    }
	      if(r>30&&r<365)
		{
		  while(r>=yue[y])
		    {
		      r-=yue[y];
		      y++;
		      if(y>12)
			{
			  y-=12;
			  x++;
			}
		      if(ans>1) yue[1]=31;
		    }
		}
      if(f) cout<<z+r<<" "<<y<<" "<<x<<" "<<endl;
      else cout<<r<<" "<<y<<" "<<x<<" "<<endl;
      continue;
	}
      if(r<30) 
	{
	cout<<z+r<<" "<<y<<" "<<x<<" "<<"BC"<<endl;  
	continue;
	}
      if(r<=1721426&&r>=365)
	{
	  while(r>nian(x))
	    {
	      f=1;
	      r-=nian(x);
	      x--;
	    }
	}
      if(r<=365&&r>=30)
	{
	  while(r>=yue[y])
	    {
	      r-=yue[y];
	      y++;
	      if(y>12) 
		{
		  y-=12;
		  x--;
		}
	    }
	}
      if(f)  cout<<z+r<<" "<<y<<" "<<x<<" "<<"BC"<<endl;
      else cout<<r<<" "<<y<<" "<<x<<" "<<"BC"<<endl;
    }
  return 0;
}
