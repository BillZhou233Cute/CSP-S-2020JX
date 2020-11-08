#include<bits/stdc++.h>
using namespace std;
bool d[100005];
int pf(int a,int b)
{
	while(b>0)
	{
		a=a*a;
		b--;
	}	
}
int rj(int n)
{
	int t=0,e=0,s=n;
	while(n>0)
	{
		n=n/2;
		e++;
	}	
	while(s>0)
	{
		t=t*pow((e-1),10)+s%2;
		s=s/2;
		e--;
	}	
	return t;
}
int main()
{
	//freopen("zoo.in","r",stdin);
	//freopen("zoo.out","w",stdout);
	int a[100005],p[100005],q[100005];
	int tot=1;
	long long n,m,c,k,b;
	cin>>n>>m>>c>>k;
	for(int i=1;i<=n;i++)
	{	
		cin>>a[i];
		a[i]=rj(a[i]);
	}	
	for(int i=1;i<=m;i++)
		cin>>p[i]>>a[i];
	k=pow(2,k);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(a[i]/pf(10,(p[j]-1))%10==1)
				d[j]=1;	
		}
	int v=0;
	for(int j=1;j<=m;j++)
		if(d[j]!=0)
			v=1;
	if(v==0)
	{
		cout<<k-n;
			return 0;
		}
	for(long long i=1;i<=sqrt(k);i++)
	{
		if(a[i]!=i)
			for(int j=1;j<=m;j++)
				if(i/(10^(p[j]-1))%10==0&&d[j]==0)
				{
					tot++;
				}
	}
	for(long long i=sqrt(k);i<k;i++)
	{
		if(a[i]!=i)
			for(int j=1;j<=m;j++)
				if(i/(10^(p[j]-1))%10==0&&d[j]==0)
				{
					tot++;
				}
	}
	cout<<tot;
}