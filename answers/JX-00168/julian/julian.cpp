#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxx=100005;
int n,a[maxx];
inline long long  read()
{
	long long x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
int now=0,year=4731,yue=0;
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	cin>>n;
	for( int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<31)	printf("%d 1 4731 BC\n",a[i]+1);
		if(a[i]>=31&&a[i]<59)	printf("%d 2 4731 BC\n",a[i]-31+1);
		if(a[i]>=59&&a[i]<90) printf("%d 3 4731 BC\n",a[i]-59+1);
		if(a[i]>=90&&a[i]<120) printf("%d 4 4731 BC\n",a[i]-91+1);
		if(a[i]>=119&&a[i]<150) printf("%d 5 4731 BC\n",a[i]-119+1);
		if(a[i]>=150&&a[i]<180)	printf("%d 6 4731 BC\n",a[i]-150+1);
		if(a[i]>=180&&a[i]<211) printf("%d 7 4731 BC\n",a[i]-180+1);
		if(a[i]>=211&&a[i]<242) printf("%d 8 4731 BC\n",a[i]-211+1);
		if(a[i]>=242&&a[i]<272) printf("%d 9 4731 BC\n",a[i]-242+1);
		if(a[i]>=272&&a[i]<303) printf("%d 10 4731 BC\n",a[i]-272+1);
		if(a[i]>=303&&a[i]<333) printf("%d 11 4731 BC\n",a[i]-303+1);
		if(a[i]>=333&&a[i]<364) printf("%d 12 4731 BC\n",a[i]-333+1);
		if(a[i]==365) printf("%d 1 4730 BC\n",a[i]-364+1);
	}
	return 0;
}
