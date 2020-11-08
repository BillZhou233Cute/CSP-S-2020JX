#include<cstdio>
using namespace std;
int Q,i,j;
long long n;    
int day[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};  //每月的天数
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	scanf("%d",&Q);
	for(i=1;i<=Q;i++)
	{
		int yuenum=1,year=-4713;
		long long daynum=1;
		scanf("%lld",&n);
		daynum+=n;
		while(daynum>day[yuenum])
		{
			if(year<=1582)      //1582年之前的润平情况;
			{
				if((year>0&&year%4==0)||(year<0&&(0-(year+1))%4==0))
					day[2]=29;
				else
					day[2]=28;
			}
			else    //1582年之后的情况;
			{
				if(year%4==0&&year%100!=0)
					day[2]=29;
				else if(year%400==0)
					day[2]=29;
				else
					day[2]=28;
			}
			
			daynum-=day[yuenum];
			yuenum++;
			if(yuenum>12)   //月数的情况;
			{
				if(year==-1)    //年数的情况;
					year++;
				year++;
				yuenum=1;
			}
		}
		if(year>1582||(year==1582&&yuenum>=10&&daynum>4))    //特殊情况;
				daynum+=10;
		if(daynum>day[yuenum])
		{
			daynum-=day[yuenum];
			yuenum++;
			if(yuenum>12)
				year++;
		}
		
		if(year<0)
			printf("%lld %d %d BC\n",daynum,yuenum,-year);
		else
			printf("%lld %d %d \n",daynum,yuenum,year);
	}
	return 0;
}