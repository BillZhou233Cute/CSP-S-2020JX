#include<bits/stdc++.h>
using namespace std;
int n;
int a[100005],t[100005],p[100005],v[100005],k[100005],c[100005],g[1000005],f[100005];
int ch(int k)
{
	for(int i=1;i<=n;i++)
		a[i]=a[i]*k;
}
int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	int m,q,o;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>t[i];
		f[i]=t[i];
		if(t[i]==1)
			cin>>p[i]>>v[i];
		if(t[i]==2)
			cin>>k[i];
		if(t[i]==3)
		{
			cin>>c[i];
			for(int j=1;j<=c[i];j++)
				cin>>g[j];
		}	
	}	
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		cin>>o;
		if(f[o]==1)
			a[p[o]]+=v[o];
		if(f[o]==2)
			ch(k[o]);
		if(f[o]==3)
		{
			for(int j=1;j<=c[f[o]];j++)
			{
				if(f[g[j]]==1)
					a[p[g[j]]]+=v[g[j]];
				else
					ch(k[g[j]]);
			}	
		}
	}
	for(int i=1;i<=n;i++)
		cout<<a[i]<<" ";
}
