#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#define ri register int
using namespace std;
int q;
int m_pin[14]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int m_run[14]={0,31,29,31,30,31,30,31,31,30,31,30,31};
void run(long long r)
{
	r+=1;
	int t=1;
	while(r-m_run[t]>0)
	{
		r-=m_run[t];
		++t;
	}
	printf("%lld %d ",r,t);
}
void pin(long long r)
{
	r+=1;
	int t=1;
	while(r-m_pin[t]>0)
	{
		r-=m_pin[t];
		++t;
	}
	printf("%lld %d ",r,t);
}
void s1(long long r)
{
	int y=4*(r/1461);
	r=r%1461;
	int year;
	if(r<365)
	{
		year=0;
		run(r);
	}else{
		if(r>=365&&r<1461)
		{
			r=r-366;
			year=1+(r/365);
			r%=365;
			pin(r);
		}
	}
	printf("%d BC\n",4713-(y+year));
}
void s2(long long r)
{
	r-=1721424;
	//int y1=400*(r/146097);
	//r%=146097;
	int year;
	//int y2=100*(r/36524);
	//r%=36524;
	int y3=4*(r/1461);
	r%=1461;
	if(r<1095)
	{
		year=r/365;
		r%=365;
		pin(r);
	}
	else{
		year=3;
		r%=365;
		run(r);
	}
	printf("%d \n",year+y3+1);
}
void s3(long long r)
{
	r-=1721424;
	r-=2;
	int y1=400*(r/146097);
	r%=146097;
	int year;
	int y2=100*(r/36524);
	r%=36524;
	int y3=4*(r/1461);
	r%=1461;
	if(r<1095)
	{
		year=r/365;
		r%=365;
		pin(r);
	}
	else{
		year=3;
		r%=365;
		run(r);
	}
	printf("%d \n",year+y1+y2+y3+1);
}
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	scanf("%d",&q);
	for(ri i=1;i<=q;++i)
	{
		long long r;
		scanf("%lld",&r);
		if(r<1721424)s1(r);
		else 
		{
			if(r<2299190)s2(r);
				else s3(r);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}