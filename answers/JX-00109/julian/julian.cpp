#include<bits/stdc++.h>
using namespace std;
int  run[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int  RUN[13]={0,31,60,91,121,152,182,213,244,274,305,335,366};
int  PIN[13]={0,31,59,90,120,151,181,212,243,273,304,334,365};
int  pin[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int r[300001],a,b,c,d,e,i;
int h,z,x;
int vpxjgywc()
{
a=r[i]%1461;
b=r[i]-a;
a=b/1461;
b=a*4;
r[i]=r[i]%1461;
if(r[i]>366)
{
b++;
r[i]-=366;
}if(r[i]>365)
{b++;
r[i]-=365;
}if(r[i]>365)
{b++;
r[i]-=365;
}if(r[i]>365)
{b++;
r[i]-=365;
}return 4713-b;
}
int gywcvpxc()
{
if((x-1)%4==0)
for(int j=1;j<=12;j++)
{
	if(r[i]<=RUN[j]&&r[i]>RUN[j-1])
	return j;
}
else
for(int j=1;j<=12;j++)
{	if(r[i]<=PIN[j]&&r[i]>PIN[j-1])
	return j;
}
}
int vpxpigyw()
{
	if((x-1)%4==0)
	return r[i]-RUN[z-1];
	return r[i]-PIN[z-1];
}
int main()
{
freopen("julian.in","r",stdin);
freopen("julian.out","w",stdout);
int Q;
cin>>Q;
for(i=1;i<=Q;i++)
{
cin>>r[i];
r[i]++;
x=vpxjgywc();
z=gywcvpxc();
h=vpxpigyw();
cout<<h<<" "<<z<<" " <<x<<" "<<"BC"<<endl;
}
return 0;
}