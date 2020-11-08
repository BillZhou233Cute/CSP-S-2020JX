#include<bits/stdc++.h>
using namespace std;
int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int b[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int run=366,pingg=365;
long long int n,r[10001],y[10001],ni[10001],gy[10001];
int nian=4713,yue=1,ri=1,gyq=1;
void suan1(int x,int s)		
{ 
	int i;
	n=x-a[x+1]+s;
	for(i=x+1;n>a[i];i++)
	{
	n=n-a[i];
	}
	yue=i-1;
	ri=ri+n;
}
void suan2(int x,int s)		
{
	int i;
	n=x-b[x+1]+s;
	for(i=x+1;n>b[i];i++)
	{
	n=n-b[i];
	}
	yue=i-1;
	ri=ri+n;
}
int main()
{
	int i,k,h=1,mm;
	cin>>mm;
	while(mm>0)
	{
	cin>>n;
if(n>pingg*3)
{
	nian=4716;yue=1;ri=1;
	n=n-pingg*3;
}
k=n/(pingg*3+run);
for(i=1;i<=k&&nian<=1580;i++)
{
nian=nian-4*k;
yue=1;ri=1;
n=n-(pingg*3+run)*i;
}
if(n>=365)
{
	nian=nian-1;
	yue=1;ri=1;
	n=n-365;
}
if(n<=276)
{
suan1(yue,ri); n=n-276;
}
else
{
yue=10; ri=15; n=n-277;
}
if(n>pingg*2+77)
{
nian=1585;yue=1;ri=1;
n=n-pingg*2-77;
}
k=n/(pingg*3+run);
for(i=1;i<=k&&nian<=1;i++)
{
nian=nian-4*k;
yue=1;ri=1;
n=n-(pingg*3+run)*i;
}
if(n>run&&nian==1)
{
gyq=0;n=n-run;
}
else if(n<run&&nian==1)
{
suan2(yue,ri);
n=0;
}
else
{
while(n>pingg)
{
nian=nian-1;yue=1;ri=1;
n=n-pingg;
}
suan2(yue,ri);n=0;
}

if(n>pingg*3)
{
nian=4;yue=1;ri=1;
n=n-pingg*3;
}
for(;n>pingg*3+run;)
{
	if(nian%4==0&&nian%100!=0)
	{
		nian=nian+4;
		n=n-pingg*3-run;
		yue=1;ri=1;
	}	
	else if(nian%400==0)
	{
		nian=nian+4;
		n=n-pingg*3-run;
		yue=1;ri=1;	
	}
}
if(n<366)
{
suan2(yue,ri);
n=0;
}
if(n>366)
{
nian=nian+1;
n=n-366;
}
for(;n>365;n=n-365)
nian++;
suan1(yue,ri);
n=0;
r[h]=ri;y[h]=yue;ni[h]=nian;
gy[h]=gyq;
h++;mm--;
}
for(i=1;i<=h-1;i++)
{if(gy[i]==1)
	cout<<r[i]<<y[i]<<ni[i]<<"BC";
	else
		cout<<r[i]<<y[i]<<ni[i];
	}
}