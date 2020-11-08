#include<bits/stdc++.h>
using namespace std;
int a[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int b[12]={31,29,31,30,31,30,31,31,30,31,30,31};
int y,m,n,q;
void date1()
{
	for(int i=0;i<=11;i++)
		if(n>a[i]) n=n-a[i];
		else
		{
			m=i+1;
			break;
		}
	if(y<=4712) cout<<n<<' '<<m<<' '<<4713-y<<' '<<"BC"<<endl;
	else cout<<n<<' '<<m<<' '<<y-4712<<endl;
}
void date2()
{
	for(int i=0;i<=11;i++)
		if(n>b[i]) n=n-b[i];
		else
		{
			m=i+1;
			break;
		}
	if(y<=4712) cout<<n<<' '<<m<<' '<<4713-y<<' '<<"BC"<<endl;
	else cout<<n<<' '<<m<<' '<<y-4712<<endl;
}
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	cin>>q;
	while(q--) 
	{
		cin>>n;
		n=n+1;
		y=0,m=0;
		if(n<=366) date2();
		else if(n<=2299161&&n>366)
		{
			n=n-366;
			y=n/1461*4+1;
			n=n%1461;
			y=y+n/365;
			n=n%365;
			if(y%4==0) date2();
			else date1();
		}
		else
		{
			n=n-2298874;
			y=6294;
			y+=n/1461*4;
			n=n%1461;
			for(int i=6300;i<=y;i+=100)
				if(i%400!=0)
			 		n+=1;
			y=y+n/1461*4;
			n=n%1461;
			y=y+n/365;
			n=n%365;
			if(y%4==0) date2();
			else date1();
		}
	}
	return 0;
}