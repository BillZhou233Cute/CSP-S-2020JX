#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cmath>
using namespace std;
long long day[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
long long a=4713,b=0,c=0,n,m,f=1;
int some(int m)
{
	int m1=m;
	int d=364;
	while(m1-d>0)
	{
		m1=m1-365; 
		d=365;a--;
		if((a-1)%4==0)
		d++;
	}
	while(m1-day[b]>0)
	{
		int ff=0;
		if((a-1)%4==0)ff=1;
		if(b==2)m1=m1-day[b]-f;
		else m1=m1-day[b];
		b++;
	}
	while(m1>0)
	{
		m1--;
		c++;
	}
	return 1;}	
int some1(int m)
{
	int m1=m;
	int d=365;
	while(m1-d>0)
	{
		
		m1=m1-d; 
		d=365;a++;
		if(a%4==0)
		d++;
	}
	while(m1-day[b]>0)
	{
		int ff=0;
		if(a%4==0)
		ff=1;
		if(b==2)m1=m1-day[b]-f;
		else m1=m1-day[b];
		b++;
	}
	while(m1>0)
	{
		m1--;
		c++;
	}
	return 1;}
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.ans","w",stdout);
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++)
	{
		a=4713;b=1;c=1;
		scanf("%lld",&m);
		if(m<=1721423)
		{
		some(m);
		cout<<c<<" "<<b<<" "<<a<<" "<<"BC"<<endl;
	}
	else 
	{
		m=m-1721423;
		a=1;
	some1(m);
		cout<<c<<" "<<b<<" "<<a<<" "<<endl;
	}
}
	fclose(stdin);
	fclose(stdout);
	return 0;
}