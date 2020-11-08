#include<bits/stdc++.h>
using namespace std;
int n,i,m,x,y,z,f,fg;
int day[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	while(~scanf("%d",&n))
	{
		m=n%365;i=1;y=4713;f=6295;fg=0;
		x=n/365/4/365;
		if(n/365>y)
		{
			fg=1;y=-(y-n/365);if(y>1582)n-=10,z=y-1582;
			x=z/100+z/400;y-=n/365/4/365;
		}
		else 
		{
			y-=n/365;y-=x;
		}
		if(n<=30)++m;m+=n/365/4;m%=365;
		while(m>day[i])m-=day[i],++i;
		printf("%d %d %d %s",m,i,y,fg?"\n":"BC\n");
	}
	return 0;
}