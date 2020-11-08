#include<iostream>
#include<cstdio>
using namespace std;
int n,m,nn,yy,rr,a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31},
day[3]={0,1721423,2299238};
int pn(int m)
{
	while(m>=a[yy]) m-=a[yy],yy++;
	cout<<m+1<<' '<<yy<<' '<<nn<<" BC\n";
}
int rn(int m)
{
	while(m>=a[yy]) m-=a[yy],yy++;
	cout<<m+1<<' '<<yy<<' '<<nn<<"\n";
}
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	cin>>n;
	while(n)
	{
		nn=4713,yy=1,rr=1,n--;
		cin>>m;
		if(m==day[1])
		{
			cout<<31<<' '<<12<<' '<<1<<" BC\n";
			continue;
		}
		if(m==day[2])
		{
			cout<<31<<' '<<12<<' '<<1582<<"\n";
			continue;
		}
		if(m<day[1])
		{
			bool s=1;
			nn-=(m/1461)*4;
			m%=1461;
			if(m>365)
			{
				m-=366;
				nn--;
				s=0;
			}
			nn-=m/365;
			m%=365;
			if(s) a[2]++;
			pn(m);
			if(s) a[2]--;
		}
		else if(m<day[2])
		{
			bool s=0;
			m-=day[1]+1;
			nn=1;
			nn+=(m/1461)*4;
			m%=1461;
			if(m>=1095)
			{
				nn+=3;
				m-=1095;
				s=1;
			}
			else
			{
				nn+=m/365;
				m%=365;
			}
			if(nn==1583&&m>=277) m+=10;
			if(s) a[2]++;
			rn(m);
			if(s) a[2]--;
		}
		else
		{
			bool s=0;
			m-=day[2];
			nn=1583;
			nn+=(m/146097)*400;
			m%=146097;
			nn+=(m/36524)*100;
			m%=36524;
			nn+=(m/1461)*4;
			m%=1461;
			if(m>=365&&m<365*2)
			{
				nn+=1;
				m-=365;
				s=1;
			}
			else
			{
				nn+=m/365;
				m%=365;
			}
			if(s) a[2]++;
			rn(m);
			if(s) a[2]--;
		}
	}
	return 0;
}
