#include<bits/stdc++.h>
using namespace std;
int sum1[]={31,28,31,30,31,30,31,31,30,31,30,31};
int sum2[]={31,29,31,30,31,30,31,31,30,31,30,31};
int sum3[]={31,28,31,30,31,30,31,31,30,21,30,31};
int T;
long long n;
int main()
{
  freopen("julian.in","r",stdin);
  freopen("julian.out","w",stdout);
  scanf("%d",&T);
  while(T--)
    {
      scanf("%lld",&n);
      n++;
      int res=0;
      while(1)
	{
	  if(res==6295||(res%4==3&&n<366)||(res%4!=3&&n<365))
	    break;
	  if((res<4713&&res%4==0)||(res>4713&&res%4==1))
	    n-=366;
	  else
	    n-=365;
	  res++;
	  if(res==4713) res++;
        }
      int y;
      if(res<6295)
	{
	  y=res-4713;
	  if((y>0&&y%4==0)||(y<0&&(y+1)%4==0))
	    {
	      for(int i=0;i<=11;i++)
		{
		  if(n<sum2[i]||i==11)
		    {
		      if(y<0)
			{
			  printf("%lld %d %d BC\n",n,i+1,-y);
			  break;
			}
		      else
			{
			  printf("%lld %d %d\n",n,i+1,y);
			  break;
			}
		    }
		  n-=sum2[i];
		}
	    }
	  else
	    {
	      for(int i=0;i<=11;i++)
		{
		  if(n<sum1[i]||i==11)
		    {
		      if(y<0)
			{
			  printf("%lld %d %d BC\n",n,i+1,-y);
			  break;
			}
		      else
			{
			  printf("%lld %d %d\n",n,i+1,y);
			  break;
			}
		    }
		  n-=sum1[i];
		}
	    }
	}  
      else
	{
	  if(n<355)
	    {
	      for(int i=0;i<=11;i++)
		{
		  if(n<sum3[i]||i==11)
		    {
		      if(i==9&&n>4) n+=10;
		      printf("%lld %d %d\n",n,i+1,1582);
		      break;
		    }
		  n-=sum3[i];
		}
	    }
	  else
	    {
	      n-=355;
	      res=0;
	      while(1)
		{
		  if((((res%4==2&&res%100!=18)||res%400==18)&&n<366)||(((res%4!=2)||(res%100==18))&&n<365))
		    break;
		  if((res%4==2&&res%100!=18)||res%400==18)
		    n-=366;
		  else
		    n-=365;
		  res++;
		}
	      y=1583+res;
	      if((y%4==0&&y%100!=0)||y%400==0)
		{
		  for(int i=0;i<=11;i++)
		    {
		      if(n<sum2[i]||i==11)
			{
			  printf("%lld %d %d\n",n,i+1,y);
			  break;
			}
		      n-=sum2[i];
		    }
		}
	      else
		{
		  for(int i=0;i<=11;i++)
		    {
		      if(n<sum1[i]||i==11)
			{
			      printf("%lld %d %d\n",n,i+1,y);
			      break;
			}
		      n-=sum1[i];
		    }
		}
	    }
	}
    }
  return 0;
}
