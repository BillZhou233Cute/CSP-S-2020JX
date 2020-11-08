#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

inline int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}

int n;
inline int prework1()
{
	int ans=0;
	for(int i=1;i<=4713;i++)
	{
		if((i-1)%4==0) ans+=366;
		else ans+=365;
	}
	return ans;
}
inline int prework2()
{
	int ans=0;
	for(int i=1;i<=1581;i++)
	{
		if(i%4==0) ans+=366;
		else ans+=365;
	}
	return ans;
}

int re[13][2]={0,0,31,31,29,28,31,31,30,30,31,31,30,30,31,31,31,31,30,30,31,31,30,30,31,31};
int k3;

inline void Work1(int k)
{
	int Year=4713,Month=1,Day=1;
	int t=366+365+365+365;
	int cnt=k/t;
	Year-=4*cnt;
	int val=k%t;
	if(val>=366) 
	{
		Year--;
		val-=366;
	}
	for(int i=1;i<=2;i++)
	{
		if(val>=365) 
		{
			Year--;
			val-=365;
		}
	}
	int flag=1;
	if((Year-1)%4==0) flag=0;
	for(int i=1;i<=12;i++)
	{
		if(val>=re[i][flag])
		{
			Month++;
			val-=re[i][flag];
		}
		else
		{
			Day+=val;
			break;
		}
	}
	printf("%d %d %d BC\n",Day,Month,Year);
}

inline void Work2(int k)
{
	int Year=1,Month=1,Day=1;
	int t=365+365+365+366;
	int cnt=k/t;
	Year+=4*cnt;
	int val=k%t;
	for(int i=1;i<=3;i++)
	{
		if(val>=365) 
		{
			Year++;
			val-=365;
		}
	}
	if(val>=366) 
	{
		Year++;
		val-=366;
	}
	int flag=1;
	if(Year%4==0) flag=0;
	for(int i=1;i<=12;i++)
	{
		if(val>=re[i][flag])
		{
			Month++;
			val-=re[i][flag];
		}
		else
		{
			Day+=val;
			break;
		}
	}
	printf("%d %d %d\n",Day,Month,Year);
}

inline void Work3(int k)
{
	int Year=1582,Month=1,Day=1;
	int val=k;
	int flag=1;
	for(int i=1;i<=12;i++)
	{
		if(i!=10)
		{
			if(val>=re[i][flag])
			{
				Month++;
				val-=re[i][flag];
			}
			else
			{
				Day+=val;
				break;
			}
		}
		else
		{
			if(val>=21)
			{
				Month++;
				val-=21;
			}
			else
			{
				for(int j=2;j<=31;j++)
				{
					if(j>=5||j<=14) continue;
					if(!val) break;
					val--; Day=j;
				}	
			}
		}
	}
	printf("%d %d %d\n",Day,Month,Year);
}

int now;
inline void Work4(int k)
{
	int Year=1583,Month=1,Day=1;
	int t=k3;
	int cnt=k/t;
	Year+=400*cnt;
	int val=k%t;
	for(int i=Year;i;i++)
	{
		if((i%100==0&&i%400==0)||(i%100!=0&&i%4==0)) now=366;
		else now=365;
		if(val>=now)
		{
			Year++;
			val-=now;
		}
		else break;
	}
	int flag=1;
	if((Year%100==0&&Year%400==0)||(Year%100!=0&&Year%4==0)) flag=0;
	for(int i=1;i<=12;i++)
	{
		if(val>=re[i][flag])
		{
			Month++;
			val-=re[i][flag];
		}
		else
		{
			Day+=val;
			break;
		}
	}
	printf("%d %d %d\n",Day,Month,Year);
}

inline int prework()
{
	int ans=0;
	for(int i=1583;i<=1982;i++)
	{
		if((i%100==0&&i%400==0)||(i%100!=0&&i%4==0)) ans+=366;
		else ans+=365;
	}
	return ans;
}

int main()
{	
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	int k1=prework1(),k2=prework2();
	//cout<<k1<<" "<<k2<<endl;
	k3=prework();
	int T=read();
	while(T--)
	{
		n=read();
		if(n<k1) Work1(n);
		else if(n<k1+k2) Work2(n-k1);
		else if(n<k1+k2+355) Work3(n-k1-k2);
		else Work4(n-k1-k2-355);
	}
	return 0;
}
