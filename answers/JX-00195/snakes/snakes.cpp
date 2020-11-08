#include<bits/stdc++.h>
using namespace std;
long long t,n,a[1000001],b[1000001],k,x,y,max1,max2,min1,min2;
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
void snakes(int m)
{
	if(max1-min1<min2) printf("%d ",m);
	else b[i]
}
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	t=read(),n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read(),b[i]=a[i];
		if(a[i]>max1) max1=a[i],max2=max1;
		if(a[i]<max1&&a[i]>max2) max2=a[i];
		if(a[i]<min1) min1=a[i],min2=min1;
		if(a[i]>min1&&a[i]<min2) min2=a[i];
		snakes(n);
	}
	
	return 0;
}
