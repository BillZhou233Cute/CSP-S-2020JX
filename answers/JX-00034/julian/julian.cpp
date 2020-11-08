#include<iostream>
#include<cstdio>
using namespace std;
int a[100005];
int b[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int ac[49]={0,31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31,31,29,31,30,31,30,31,31,30,31,30,31};
int yue,ri;int k,nian;int xiaoj;
int main()
{
   freopen("julian.in","r",stdin);
  freopen("julian.out","w",stdout);
  int n;
  cin>>n;
  for(int i=1;i<=n;i++)
    cin>>a[i];
  for(int i=1;i<=n;i++)
    {
      if(a[i]>=1721424)
      {
	if(a[i]<2299149)
	 { 
	  a[i]=a[i]-1721424;
               k=a[i]/1461;
               nian=4*k+1;
	      a[i]=a[i]-1461*k;
	     for(int j=1;j<=48;j++)
	      {
    	        xiaoj=j;
		if(a[i]-ac[j]>0)
		   a[i]=a[i]-ac[j];
		else if(a[i]-ac[j]<0)
		  {
		    yue=j;
		    ri=a[i]+1;
		    break;
		  }
		else if(a[i]-ac[j]==0)
		  {
		    yue=j+1;
		    ri=1;
		    break;
		  }
	      }
	     if(xiaoj>12&&xiaoj<=24)
	       nian=nian+1;
	     if(xiaoj>24&&xiaoj<=36)
	       nian=nian+2;
	     if(xiaoj>36&&xiaoj<=48)
	       nian=nian+3;

	     if(yue%12!=0)
	       yue=yue%12;
	     else yue=12;
             cout<<ri<<" "<<yue<<" "<<nian<<endl;
	 }
       else
	 {
	   cout<<"happy birthday"<<endl;
	 }
      }
      else 
	{
	  if(a[i]<367)
	    {
	      if(a[i]<366)
	     {
                 for(int j=1;j<=12;j++)
	       {
	        if(a[i]-b[j]>0)
	 	a[i]=a[i]-b[j];
               else if(a[i]-b[j]<0)
	        {  
                yue=j;
	        ri=a[i]+1;
		break;
	        }
	 	else  if(a[i]-b[j]==0)
		  {
		    yue=j+1;
		    ri=1;
		    break;
	          }
	       } 
	      cout<<ri<<" "<<yue<<" "<<"4713 BC"<<endl;
	     }
	      else
		cout<<"1 1 4712 BC"<<endl;
	   }
	  else 
	    {
	      a[i]=a[i]-366;
	       k=a[i]/1461;
               nian=4712-4*k;
	      a[i]=a[i]-1461*k;

	     for(int j=1;j<=48;j++)
	      {
    	        xiaoj=j;
		if(a[i]-ac[j]>0)
		   a[i]=a[i]-ac[j];
		else if(a[i]-ac[j]<0)
		  {
		    yue=j;
		    ri=a[i]+1;
		    break;
		  }
		else if(a[i]-ac[j]==0)
		  {
		    yue=j+1;
		    ri=1;
		    break;
		  }
	      }
	     if(xiaoj>12&&xiaoj<=24)
	       nian=nian-1;
	     if(xiaoj>24&&xiaoj<=36)
	       nian=nian-2;
	     if(xiaoj>36&&xiaoj<=48)
	       nian=nian-3;

	     if(yue%12!=0)
	       yue=yue%12;
	     else yue=12;
             cout<<ri<<" "<<yue<<" "<<nian<<" BC"<<endl;
	    }
	} // BC
    }//for
  return 0;
}
	     



