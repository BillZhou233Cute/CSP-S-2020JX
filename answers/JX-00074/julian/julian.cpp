#include<bits/stdc++.h>
using namespace std;
#define print cout<<day<<" "<<mont<<" "<<year<<" "<<r<<endl
const int mod=1461,mod1=1721058,p100=36524,p400=146097,p1582=577448,p1004=276;
int Q,r,mon[15]={0,31,28,31,30,31,30,31,31,30,31,30,31},m[2][15];

inline int read()
{
	register int x=0,f=1;
	register char ch=getchar();
	while(!isdigit(ch)) f^=(ch=='-'),ch=getchar();
	while(isdigit(ch)) x=x*10+(ch^48),ch=getchar();
	return f ? x:-x;
}

void init()
{
	for(int i=1;i<=12;++i) if(i!=2) m[0][i]=m[1][i]=mon[i];
	m[0][2]=28,m[1][2]=29;
}

void work0(int& Da,int& Mo,int f,int R)
{
	for(int i=1;i<=12;++i)
	{
		if(R<m[f][i]) break;
		if(R>=m[f][i]) R-=m[f][i],Mo++;
	}
	if(R) Da+=R;
}

void work1(int da,int mo,int ye,int res)
{
	if(res<366)
	{
		work0(da,mo,1,res);
		printf("%d %d %d BC\n",da,mo,ye);return;
	}
	res-=366;ye--;
	if(res>=365) res-=365,ye--;
	if(res>=365) res-=365,ye--;
	work0(da,mo,0,res);
	printf("%d %d %d BC\n",da,mo,ye);return;
}

inline bool check(int x)
{
	if(x%100!=0)
	{
		if(x%4==0) return 1;
		else return 0;
	}
	if(x%400==0) return 1;
	return 0;
}

void work4(int da,int mo,int ye,int res)
{
	for(int i=1;i<=4;++i)
	{
		if( (!check(ye)&&res>=365) || (check(ye)&&res>=366) )
		{
			if(!check(ye)) res-=365,ye++;
			else res-=366,ye++;
		} 
	}
	if(check(ye)) work0(da,mo,1,res);
	else work0(da,mo,0,res);
	printf("%d %d %d\n",da,mo,ye);return;
}

int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	init();
	Q=read();
	while(Q--)
	{
		r=read();
		int day=1,mont=1,year=4713,tmp;
		if(r<mod)
		{	
			work1(day,mont,year,r);continue;
		}
		if(r<mod1+366)
		{
			tmp=r/mod;year-=tmp*4,r-=tmp*mod;
			work1(day,mont,year,r);continue;
		}
		r=r-mod1-366;
		year=1;
		if(r<p400)
		{
			tmp=r/mod;year+=4*tmp,r-=tmp*mod;
			work4(day,mont,year,r);continue;
		}
		if(r<=p1582+p1004)
		{
			tmp=r/p400;year+=400*tmp,r-=tmp*p400;
			tmp=r/p100;year+=100*tmp,r-=tmp*p100;
			tmp=r/mod;year+=4*tmp,r-=tmp*mod;r-=6;
			work4(day,mont,year,r);continue;
		}
		r=r-p1582-p1004;
		if(r<79)
		{
			r-=1;day=15,mont=10,year=1582;
			if(r>=31) mont++,r-=31;
			if(r>=30) mont++,r-=31;
			day+=r;
			printf("%d %d %d\n",day,mont,year);continue;
		}
		r-=79,year=1583,day=1,mont=1;
		if(r<6209)//6209
		{
			tmp=r/mod;year+=4*tmp,r-=tmp*mod;
			work4(day,mont,year,r);continue;
		}
		r-=6209,year=1600;
		tmp=r/p400;year+=400*tmp,r-=tmp*p400;
		tmp=r/p100;year+=100*tmp,r-=tmp*p100;
		tmp=r/mod;year+=4*tmp,r-=tmp*mod;
		work4(day,mont,year,r);
	}
	
	return 0;
}
