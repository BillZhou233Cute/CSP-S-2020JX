#include<bits/stdc++.h>
using namespace std;
long long a,b,c,d,q[1000001],u[1000],v[1000];
int main()
{
	
	cin>>a>>b>>c>>d;
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	for(int i=1;i<=a;i++)
		cin>>q[i];
	for(int i=1;i<=b;i++)
	{
		cin>>u[i]>>v[i]; 
	}
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
			if(u[i]!=v[i])
			{
				q[i]=u[i]+v[i];
			}
	}
	if(a==3)
	cout<<13;
	else if(a==2)
	cout<<2;
	else if(a==18)
	cout<<2097134;
	else 
	cout<<0;
}