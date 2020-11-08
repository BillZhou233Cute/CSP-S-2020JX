#include<bits/stdc++.h>
using namespace std;
int q;long long xx,y;int year,month,day;
int mon[14]={0,31,28,31,30,31,30,31,31,30,31,30,31};
void print1()
{printf("%d %d %d BC\n",day,month,year);}
void print2()
{printf("%d %d %d\n",day,month,year);}
void make(long long x)
{
	bool pd=0;
	
	int year1=x/1461*4;//int run=x/1461;if(x%1461>60) run++;
	x%=1461;
	int year2=x/365;
	x%=365;
	int years=year1+year2;
	//cout<<years<<endl;
	if(years<4713)
	{
	year=4713-years;
		if(y%1461<365) pd=1;
			if(x==60&&pd==1) 
			{month=2;day=29;print1();return;}	
		
	else 
	{if(x>60) x--;
		for(int i=1;i<=12;i++)
	if(x>mon[i]){x-=mon[i];}
	else {month=i;day=x;print1();return;}
	}	
	
	}
	else if(years>=4713)
	{
		//years++;
		if(years+1-4713<1582)
		{
		//	int run;
			x=y;//cout<<x<<endl;
			int yearr1=x/146097;if(x%146097<365) pd=1;
			x%=146097;
			int yearr2=x/1461;if(x%1461<365&&x%36524>365) pd=1;
			x%=1461;
			int yearr3=x/365;
			x%=365;
			year=yearr1*400+yearr2*4+yearr3+1-4713;
			if(x==60&&pd==1) 
			{month=2;day=29;print2();return;}
		else
		{if(x>60) x--;
			for(int i=1;i<=12;i++)
	if(x>mon[i]){x-=mon[i];}
	else {month=i;day=x;print2();return;}
		}	
		
		
		}
		
	
	else 
	{
		x=y+10;//cout<<x<<endl;
		int yearr1=x/146097;if(x%146097<365) pd=1;
			x%=146097;
			int yearr2=x/1461;if(x%1461<365&&x%36524>365) pd=1;
			x%=1461;
			int yearr3=x/365;
			x%=365;
			year=yearr1*400+yearr2*4+yearr3+1-4713;
			if(x==60&&pd==1) 
			{month=2;day=29;print2();return;}
		else
		{if(x>60) x--;
			for(int i=1;i<=12;i++)
	if(x>mon[i]){x-=mon[i];}
	else {month=i;day=x;print2();return;}
		}	
	}
}
}
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	cin>>q;
	
	for(int i=1;i<=q;i++)
	{
		scanf("%lld",&xx);
		y=xx;
		
		make(xx+1);
	}
	//cout<<1111;
}