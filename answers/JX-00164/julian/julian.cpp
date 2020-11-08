#include<iostream>
#include<cstdio>
using namespace std;
long long dat,t,y,d,m,day[20]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&dat);
		if (dat<1721424)
		      {
				  long long n=dat/1461;
				  n*=4;
				  dat%=1461;
				  d=m=1;
				  y=0;
				  while(dat--){
				  if(d<day[m]||(m==2&&d==28&&y%4==0))d++;
			
					else if(m<12){
					m++;
					d=1;
					}
			
					else{
					m=1;
					d=1;
					y++;
					}
				  }
				  printf("%lld %lld %lld BC\n",d,m,4713-n-y);
			  }
			 else if (dat==1721424)printf("1 1 1\n");
		 else if(dat<=2299160)
		      {
				  dat-=1721424;
				 long long n=dat/1461;
				  n*=4;
				  dat%=1461;
				  d=m=1;
				  y=0;
				  while(dat--)
				  {
					  if(d<day[m]||(m==2&&d==28&&y%4==3))d++;
					
					else if(m<12){
						m++;
						d=1;
					}
					
					else {
						m=1;
						d=1;
						y++;
					}
				  }
				  printf("%lld %lld %lld \n",d,m,n+y+1);
			  }
		 else 
		      {
				  dat+=10;
				  dat-=2298884;//1582 1 1
				  long long n=dat/146097;
				  long long sy=1582;
				  n*=400;
				  sy+=n;
				  m=d=1;
				  y=0;
				  dat%=146097;
				  while(dat--)
				  {
					  if(d<day[m])d++;
						
					else if((sy%400==0||(sy%100!=0&&sy%4==0))&&d==28)d++;
						
					else if(m<12)
					{
						d=1;
						m++;
					}
					
					else
					{
						y++;
						sy++;
						m=d=1;
					}
				}
				  printf("%lld %lld %lld \n",d,m,sy);
			  }
		      
	}
	return 0;
}