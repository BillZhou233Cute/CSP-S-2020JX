#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

#define ll long long

int n=0,m=0,c=0,k=0,x=0,ans=0;
int a[1000000],p[1000000],q[1000000];
bool siliao[1000000];
int siliao2[1000000];
ll ks=0;

bool findbool(ll num,int length)
{
	int z=num;
	for(int i=0;i<length;i++)
	{
		z/=2;
	}
	return z%=2;
}
int findbool2(ll num,int length)
{
	int z=num;
	int u=0;
	for(int i=0;i<length;i++)
	{
		z/=2;
		u++;
	}
	return u;
}

int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	cin>>n>>m>>c>>k;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<m;i++)
	{
		cin>>p[i]>>q[i];
	}
	ks=pow(2,k);
	for(int i=0;i<n;i++)
	{
		if(findbool(a[i],p[i])==true)
		{
			x++;
			siliao[i]==true;
		}
		else
		{
			siliao[i]==false;
		}
		siliao2[i]=findbool2(a[i],p[i]);
	}
	for(int i=0;i<x;i++)
	{
		ans+=ks/siliao2[i];
	}
	ans-=n;
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
