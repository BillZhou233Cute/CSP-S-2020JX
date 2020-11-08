#include<bits/stdc++.h>
using namespace std;
long long q,r;
inline long long read()
{
	long long x=0;
	char c=getchar();
	bool flag=0;
	while(c>'9'||c<'0')
	{
		if(c=='-') flag=1;
		c=getchar();
	}
	while(c<='9'&&c>='0')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	if(flag) x=-x;
	return x;
}
void julian(long long r)
{
	if(r==1721424) {cout<<1<<' '<<1<<' '<<1<<'\n';return;}
	long long year=-4713,month=1,date=1;
	if(r>1721424) 
	{
		r-=1721424,year=1;
		if(r>577736) 
		{
			r-=577736,year=1582,date=15,month=10;
			if(r>79) 
			{
				r-=79,date=1,month=1,year=1583;
				while(1)
				{
					if(r>365&&((year%400!=0&&year%100==0)||year%4!=0)) r-=365,year++;
					if(r>366&&((year%4==0&&year%100!=0)||year%400==0)) r-=366,year++;
					if(r<365&&((year%400!=0&&year%100==0)||year%4!=0)) 
					{
						while(r>0)
						{
							if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
							if(r>31) r-=31,month++; else date+=r,r=0;
							if(month==4||month==6||month==9||month==11)
							if(r>30) r-=30,month++; else date+=r,r=0;
							if(month==2) if(r>28) r-=28,month++; else date+=r,r=0;
						}
						break;
					}
					if(r<366&&((year%4==0&&year%100!=0)||year%400==0))
					{
						while(r>0)
						{
							if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
							if(r>31) r-=31,month++; else date+=r,r=0;
							if(month==4||month==6||month==9||month==11)
							if(r>30) r-=30,month++; else date+=r,r=0;
							if(month==2) if(r>29) r-=29,month++; else date+=r,r=0;
						}
						break;
					}
				}
			}
			else 
			{
				if(r>18)
				{
					r-=18,date=1,month=11;
					while(r>0)
					{
						if(month==12) date+=r,r=0;
						if(month==11)
						if(r>30) r-=30,month++; else date+=r,r=0;
					}
				}
			}
		}
		else while(1)
		{
			if(r>365&&year%4!=0) r-=365,year++;
			if(r>366&&year%4==0) r-=366,year++;
			if(r<365&&year%4!=0) 
			{
				while(r>0)
				{
					if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
					if(r>31) r-=31,month++; else date+=r,r=0;
					if(month==4||month==6||month==9||month==11)
					if(r>30) r-=30,month++; else date+=r,r=0;
					if(month==2) if(r>28) r-=28,month++; else date+=r,r=0;
				}
				break;
			}
			if(r<366&&year%4==0)
			{
				while(r>0)
				{
					if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
					if(r>31) r-=31,month++; else date+=r,r=0;
					if(month==4||month==6||month==9||month==11)
					if(r>30) r-=30,month++; else date+=r,r=0;
					if(month==2) if(r>29) r-=29,month++; else date+=r,r=0;
				}
				break;
			}
		}
	}else while(1)
	{
		if(r>365&&(-year)%4!=1) r-=365,year++;
		if(r>366&&(-year)%4==1) r-=366,year++;
		if(r<365&&(-year)%4!=1) 
		{
			while(r>0)
			{
				if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
				if(r>31) r-=31,month++; else date+=r,r=0;
				if(month==4||month==6||month==9||month==11)
				if(r>30) r-=30,month++; else date+=r,r=0;
				if(month==2) if(r>28) r-=28,month++; else date+=r,r=0;
			}
			break;
		}
		if(r<366&&(-year)%4==1)
		{
			while(r>0)
			{
				if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
				if(r>31) r-=31,month++; else date+=r,r=0;
				if(month==4||month==6||month==9||month==11)
				if(r>30) r-=30,month++; else date+=r,r=0;
				if(month==2) if(r>29) r-=29,month++; else date+=r,r=0;
			}
			break;
		}
	}
	printf("%lld %lld %lld ",date,month,abs(year));
	if(year<0) putchar('B'),putchar('C');putchar('\n');
}
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	q=read();
	while(q--)
	{
		r=read();
		julian(r);
	}
	return 0;
}
