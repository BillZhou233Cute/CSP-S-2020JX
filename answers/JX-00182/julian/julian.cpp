#include<bits/stdc++.h>
using namespace std;
int n;
int r[10001];
int main()
{
freopen("julian.in","r",stdin);
freopen("julian.out","w",stdout);
	int a,b,c;
cin>>n;
for(int i=1;i<=n;i++)
{
  cin>>r[i];
  if(r[i]<=1721423)
  {
   a=4713-r[i]/365;
   b=(r[i]%365-(4713-a)/4)/31+1;
   c=(r[i]-(4713-a)*365-(4713-a)/4)%31;
cout<<c<<" "<<b<<" "<<a<<" "<<"BC"<<endl;
}
if(r[i]>1721423)
{	a=(r[i]-1721423)/365;
	b=((r[i]-1721423)%365-a%4)/31;
	c=((r[i]-1721423)%365-a%4)%31;
	if(r[i]>=2299514)
	{	c=c+10;
		if(c>31)
		{	c=c-10;
		b++;}
	cout<<c<<" "<<b<<" "<<a<<endl;
		}
	else
	cout<<c<<" "<<b<<" "<<a<<endl;
	}
}
return 0;
}
