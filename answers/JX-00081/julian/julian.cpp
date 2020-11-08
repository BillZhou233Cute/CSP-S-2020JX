#include<bits/stdc++.h>
using namespace std;
freopen("julian.in","r",stdin);
freopen("julian.out","out",stdout);

int q,r,yea ,month,day;
long long tot[3000002];
int start=4713;
bool ts;
int mt[13]={0,31,59,90,120,151,181,212,243,273,304,334,365};
int main()
{
  tot[0]=365;
  for(int i=1;i<=6295;i++)
    {
      int now=start-i-1;
      // if(now%400==0) ts=1;
      if(now%4==0) ts=1;        
      tot[i]=tot[i-1]+365;
      if(ts) tot[i]++;
    }
  for(int i=6296;i<=3000000;i++)
    {
      int now=start-i-1;
      if(now%400==0) ts=1;
      if(now%4==0&&now%100!=0) ts=1;
      tot[i]=tot[i-1]+365;
      if(ts) tot[i]++;
    }
  cin>>q;
  for(int z=1;z<=q;z++)
    {
      cin>>r;
      for(int i=0;i<=3000002;i++)
	{
	  if(r< tot[i]) 
	    {
	      yea =start-i;
	      r-=tot[i-1];
	      break;
	    }
	}
      bool op=0;
      if(yea <=0)
	{
	  yea *=-1;
	  yea ++;op=1;
	}
      if(yea %400==0||(yea %4==0&&yea %100!=0)) r--;
      for(int i=1;i<=12;i++)
	{
	  if(yea ==1582&&i==10&&r>=5) r+=10;
	  if(r<mt[i])
	    {
	      month=i;
	      r-=mt[i-1];
	      break;
	    }
	}
      day=r;
      cout<<day<<" "<<month<<" "<<yea ;
      if(!op) cout<<" "<<"BC";
      cout<<endl;
    }

  return 0;
}
