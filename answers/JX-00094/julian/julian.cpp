#include <iostream>
#include <cstdio>
using namespace std;
long long q,r,d,m,y;
int gy=-1;

int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		d=1,m=1,y=4713,gy=-1;
		cin>>r;
		int k=r/1461;
		y-=4*k;
		r-=1461*k;
		k=r/365;
		y-=k;
		r-=365*k;
		int e=r;
		if(e>=31) m++,e-=31;
		if((-y-1)%4==0) if(e>=29) m++,e-=29;
		else if(e>=28) m++,e-=28;
		if(e>=31) m++,e-=31;
		if(e>=30) m++,e-=30;
		if(e>=31) m++,e-=31;
		if(e>=30) m++,e-=30;
		if(e>=31) m++,e-=31;
		if(e>=31) m++,e-=31;
		if(e>=30) m++,e-=30;
		if(e>=31) m++,e-=31;
		if(e>=30) m++,e-=30;
		if(e>=31) m++,e-=31;
		d+=e;
		if(m>12) y-=m/12,m%=12;
		if(y<=0) y=-y+1,gy=1;
		int l=0;
		if(y>1582) l=y/100-15,l+=(y/400-3);
		if(y>=1582&&m>=10)
		{
			if(d>4&&d<15) d=4;
			else d-=10;
		}
		cout<<d<<" "<<m<<" "<<y<<" ";
		if(gy==-1) cout<<"BC"<<endl;
		else cout<<endl;
	}
	return 0;
}
