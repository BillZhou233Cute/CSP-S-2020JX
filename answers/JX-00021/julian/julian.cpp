#include <iostream>
#include <cstdio>
using namespace std;
int mod=1461;
int Q,r,i,j,a,b;
int glgp[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int glgr[13]={0 ,31,29,31,30,31,30,31,31,30,31,30,31};
int abs(int x)
{
	if(x<0) x=-x;
		return x;
	}
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
    scanf("%d",&Q);
    for(i=1;i<=Q;i++) 
	  {
	scanf("%d",&r);
  int shiji=r+1;
  if(shiji<=1721424)
    {
      a=shiji%mod;
		b=shiji/mod;
		int js=0;
          for(j=0;;j++)
	       {
			     if(shiji<=366) break;
                 if((j+1)%4==1&&(shiji-366)>0){shiji-=366;js=j;continue;}
                 if((j+1)%4!=0&&(shiji-365)>0){shiji-=365;js=j;continue;}
            }
          if((js+1)%4==1)
		{
	      for(j=1;j<=12;j++)
	     {
	         if(shiji-glgr[j]>0) shiji-=glgr[j];
	          else{ 
				  if(js==0){printf("%d %d %d BC\n",shiji,j,4713-js);break;}
				  else {printf("%d %d %d BC\n",shiji,j,4713-js-1);break;}
			  }
			}
		 }
		else 
			{
				for(j=1;j<=12;j++)
	        {
	         if(shiji-glgp[j]>0) shiji-=glgp[j];
	          else{ 
				  if(js==0){printf("%d %d %d BC\n",shiji,j,4713-js);break;}
				  else {printf("%d %d %d BC\n",shiji,j,4713-js-1);break;}
			  }
			} 
		}
    }
   if(shiji>1721424&&shiji<=2299527)
     {
       shiji-=1721424;
       a=shiji%mod;
		 b=shiji/mod;
       if(a>1095)
		{
			 a-=1095;
			 for(j=1;j<=12;j++)
			{
				 if(a-glgr[j]>0) a-=glgr[j];
		         else {printf("%d %d %d\n",a,j,4*b+4);break;}
			}
		}
       else if(a<=1095)
       {
             int num1=a%365,num2=a/365;
             for(j=1;j<=12;j++)
	         {
	             if(num1-glgp[j]>0) num1-=glgp[j];
                  else {printf("%d %d %d\n",num1,j,4*b+num2+1);break;}
			 }          
         }
      }
   else  if(shiji>2299527)
      {
	      shiji-=2299527;
          if(shiji<=78)
		{
	      if(shiji<=17) {printf("%d 10 1582\n",shiji+14);break;}
	      else 
			{
			 shiji-=17;
			 for(j=11;j<=12;j++)
	         {
		         if(shiji-glgp[j]>0) shiji-=glgp[j];
                 else {printf("%d %d 1582\n",shiji,j);break;}
              }
			}
		}
	}
	else if(shiji>78&&shiji<=809)
	{
          shiji-=78;
          a=shiji%mod;
          if(a>365)
	      {
              a-=365;
	          for(j=1;j<=12;j++)
			  {
				  if(a-glgr[j]>0) a-=glgr[j];
	              else {printf("%d %d 1584\n",a,j);break;}
				}  
           }
          else if(a<=365)
	      {
	         for(j=1;j<=12;j++){if(a-glgp[j]>0) a-=glgp[j];
		     else {printf("%d %d 1583\n",a,j);break;}}
		   }
	}
	else if(shiji>809)
	{
          shiji-=809;
          int js=0;
          for(j=0;;j++)
	       {
			     if(shiji<=365) break;
                 if(abs(j-16)%4!=0&&(shiji-365)>0){shiji-=365;js=j;continue;}
                 if(abs(j-16)%4==0&&abs(j-16)%400!=0&&(shiji-365)>0) {shiji-=365;js=j;continue;}
                 if((abs(j-16)+1)%4==0&&abs(j-16)+1%400==0&&(shiji-366)>0){shiji-=366;js=j;continue;}
            }
          if(abs(js-16)%4==3&&abs((js-16)+1)%400==0)
		{
	      for(j=1;j<=12;j++)
	     {
	         if(shiji-glgr[j]>0) shiji-=glgr[j];
	          else {printf("%d %d %d\n",shiji,j,1584+js+1);break;}
		 } 
		}
	  else for(j=1;j<=12;j++)
	   {
	         if(shiji-glgp[j]>0)shiji-=glgp[j];
             else{printf("%d %d %d\n",shiji,j,1584+js+1);break;}      
          }
        }
      } 
  return 0;
}
