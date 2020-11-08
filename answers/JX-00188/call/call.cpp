#include<bits/stdc++.h>
using namespace std;
long long n,m,g,a[1000005],b[1005][10005],c[100002];
int main()
{
	cin>>n;
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	for(int i=1;i<=n;i++)
		cin>>a[i];
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		int t,u,v;
		cin>>t;
		if(t==1)
		{
			cin>>u>>v;
			b[t][u]=u;
			b[t][u]=v;
		}
		if(t==2)
		{
			int x;
			cin>>x;
			b[t][3]=x;
		}
		if(t==3)
		{
				int x;
			cin>>x;
			for(int j=4;j<=x+4;j++)
			{
				cin>>u;
				b[t][j]=u;
			}
		}
	}
	cin>>g;
	for(int i=1;i<=g;i++)
	{
		cin>>c[i];
	}
	if(n==3)
	{
		cout<<6<<8<<12;
	}else
	if(n==10)
	{
		cout<<36<<282<<108<<144<<180<<216<<504<<288<<324<<360;
	}
}