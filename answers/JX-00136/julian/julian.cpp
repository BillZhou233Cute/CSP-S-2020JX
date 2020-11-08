#include<cstdio>

int n;
long long a;
int year=4713,month=1,day=1;
int flag=1;
int m[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
bool BC=true;

void mo()
{
	while(a>=m[month])
		{
			if(BC && (year-1)%4==0 )
			{
				///**/printf("R\n");
				m[2]=29;
			}
			else if(((!BC) && year<1582) && year%4==0)
				m[2]=29;
			else if( (!BC && year>1582)&&((year%4==0 && year%100!=0) || (year%400==0)))
			{
				///**/printf("R\n");
				m[2]=29;
			}
			else 
			{
				m[2]=28;
			}
			if((!BC) && year==1582 && month==10 && (a>=5)&&(flag)){
				a+=10;
				flag=0;
				return;
			}
			a-=m[month];
			month++;
			if(month>12)
			{
				month-=12;
				if(BC) year--;
				else year++;
			}
			if(year<=0)
			{
				BC=false;
				year++;
			}
		}
	return;
}

void ye()
{
	while(a>=366)
		{
			int x=365;
			if(BC && (year-1)%4==0 )
			{
				//printf("R\n");
				x=366;
			}
			else if(((!BC) && year<1582) && year%4==0)
				x=366;
			else if( (!BC && year>1582)&&((year%4==0 && year%100!=0) || (year%400==0)))
			{
				//printf("R\n");
				x=366;
			}
			else 
			{
				x=365;
			}
			if(BC)year--;
			else year++;
			a-=x;
			if(year<=0)
			{
				BC=false;
				year++;
			}
			if((!BC) && year==1581 )
				mo();
		}
	return;
}


int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	
	long long s=1721058;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a);
		year=4713;
		month=1;
		day=1;
		flag=1;
		BC=true;
		/*if(a>=1721424)
		{
			a-=1721424;
			year=1;
			BC=false;
		}
		if(a>=38245310)
		{
			a-=38245310;
			year+=100000;
		}
		if(a>=36525971060)
		{
			a-=36525971060;
			year+=100000000;
		}*/
		ye();
		mo();
		mo();
		day+=a;
		printf("%d %d %d %s\n",day,month,year,BC?"BC":" ");
	}
	return 0;
}
