#include<iostream>
#include<cstdio>
#define LL long long
#define re register
#define IL inline
#define debug cout<<"DEBUG line = "<<__line__<<" ";
using namespace std;

IL bool isnum(char ch)
{
	return ch>='0'&&ch<='9';
}
IL LL read()
{
	re LL x=0,fu=1;
	char ch=getchar();
	while(!isnum(ch)) ch=getchar();
	while(isnum(ch)) x=(x<<3)+(x<<1)+(ch-'0'),ch=getchar();
	return x*fu;
}

LL q,r,y,m,d;
bool BC;
IL LL abs(LL x)
{
	if(x<0) return -x;
	return x;
}
int year[2010];
IL LL judge_year(LL x)
{
	if(x>1582)
	{
		if(x%400==0) return 366;
		if(x%100==0) return 365;
		if(x%4==0) return 366;
		return 365;
	}
	if(abs(x)%4==0) return 366;
	return 365;
}
LL month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
/*******
*array size
*freopen
*delete debug
*test again
*********/
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	cin>>q;
	for(re int i=2000;i<=4005;i++) year[i-2000]=judge_year(i);
	while(q--)
	{
		r=read();
		if(r>=2299239)//1583-1-1
		{
			r-=2299239;
			y=1583;
			for(;;y+=100000000ll)
			{
				if(r>=36524250000ll) r-=36524250000ll;
				else break;
			}
			for(;;y+=10000000ll)
			{
				if(r>=3652425000ll) r-=3652425000ll;
				else break;
			}
			for(;;y+=1000000ll)
			{
				if(r>=365242500ll) r-=365242500ll;
				else break;
			}
			for(;;y+=100000)
			{
				if(r>=36524250ll) r-=36524250ll;
				else break;
			}
			for(;;y+=10000)
			{
				if(r>=3652425) r-=3652425;
				else break;
			}
			for(;;y+=2000)
			{
				if(r>=730485) r-=730485;
				else break;
			}
			for(;;y++)
			{
				if(r>=year[y%2000]) r-=judge_year(y);
				else break;
			}
			//cout<<"special calc sy="<<sy<<" last="<<rr<<endl;
			
		}
		else
		{
			if(r>2299160) r+=10;
			for(y=-4712;;y+=100)
			{
				if(r>=36525) r-=36525;
				else break;
			}
			for(;;y++)
			{
				if(r>=judge_year(y)) r-=judge_year(y);
				else break;
			}
		}
		
		if(y<=0) BC=1;
		else BC=0;
		if(abs(y)%4==0) month[2]=29;
		else month[2]=28;
		
		//cout<<"now year="<<y<<" last="<<r<<endl;
		

		
		for(m=1;m<=12;m++)
		{
			if(r>=month[m]) r-=month[m];
			else break;
		}
		//cout<<"month="<<m<<" last="<<r<<endl;
		
		//BC!
		printf("%lld %lld ",r+1,m);
		if(BC) y=abs(y)+1;
		printf("%lld",y);
		if(BC) putchar(' '),putchar('B'),putchar('C');
		puts("");
	}
	return 0;
}
/*******
*array size
*freopen
*delete debug
*test again
*********/