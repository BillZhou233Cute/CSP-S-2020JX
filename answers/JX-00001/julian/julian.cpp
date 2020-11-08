#include<bits/stdc++.h>
using namespace std;
int q,day,month,year;
long long r;
const int mod1=1461,mod2=1721423,mod3=2299160,mod4=2299969;
int a[14]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int b[14]={0,31,29,31,30,31,30,31,31,30,31,30,31};

int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	
	scanf("%d",&q);
	
	while(q--)
	{
		scanf("%lld",&r);
		r++;
		
		if(r<=mod2)
		{
			year=r/mod1;
			year*=4;
			r%=mod1;
			
			if(r==366)
			{
				year=4713-year;
				printf("31 12 %d BC\n",year);
			}
			
			else if(r>366)
			{
				r-=366;
				year++;
				year+=r/365;
				r%=365;
				month=1;
				year=4713-year;
				
				while(r>a[month])
				{
					r-=a[month];
					month++;
				}
				
				day=r;
				
				printf("%d %d %d BC\n",day,month,year);
			}
			
			else
			{
				month=1;
				year=4713-year;
				
				while(r>b[month])
				{
					r-=b[month];
					month++;
				}
				
				day=r;
				
				printf("%d %d %d BC\n",day,month,year);
			}
		}
		
		else if(r>mod2 && r<=mod4)
		{
			if(r>mod3)
			{
				r+=10;
			}
			r-=mod2;
			year=r/mod1;
			year*=4;
			r%=mod1;
			
			if(r>1095)
			{
				r-=1095;
				month=1;
				
				while(r>b[month])
				{
					r-=b[month];
					month++;
				}
				
				day=r;
				
				printf("%d %d %d\n",day,month,year);
			}
			
			else
			{
				year+=r/365+1;
				r%=365;
				
				if(r==0)
				{
					year--;
					printf("31 12 %d\n",year);
				}
				
				else
				{
					month=1;
					
					while(r>a[month])
					{
						r-=a[month];
						month++;
					}
				
					day=r-1;
					
					printf("%d %d %d\n",day,month,year);
				}
			}
		}
		
		else
		{
			r-=mod4;
			
			year=r/mod1;
			year*=4;
			long long aa=year/100;
			long long bb=year/400;
			r+=aa-bb;
			year+=1585;
			r%=mod1;
			
			if((r>1095 && (year+3)%100)!=0 || (r>1095 && !(year+3)%400))
			{
				year+=3;
				r-=1095;
				month=1;
				
				while(r>b[month])
				{
					r-=b[month];
					month++;
				}
				
				day=r;
				
				printf("%d %d %d\n",day,month,year);
			}
			
			else
			{
				year+=r/365;
				r%=365;
				
				if(r==0)
				{
					printf("31 12 %d\n",year);
				}
				
				else
				{
					month=1;
					
					while(r>a[month])
					{
						r-=a[month];
						month++;
					}
				
					day=r-1;
					
					printf("%d %d %d\n",day,month,year);
				}
			}
		}
	}	
		
	return 0;
}