#include<bits/stdc++.h>
using namespace std;
struct Nide
{
	int t,p,v,c;
	vector<int> g;
}hs[100005];
int n,m,q,f,x;
int a[100005];
void zyx(int f)
{
	if(hs[f].t==1)
	a[hs[f].p]+=hs[f].v;
	if(hs[f].t==2)
	for(int i=1;i<=n;i++)
	{
		a[i]*=hs[f].v;
		a[i]=a[i]%998244353;
	}
	if(hs[f].t==3)
	for(int i=0;i<hs[f].c;i++)
	zyx(hs[f].g[i]);
}
int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>hs[i].t;
		if(hs[i].t==1)
		cin>>hs[i].p>>hs[i].v;
		if(hs[i].t==2)
		cin>>hs[i].v;
		if(hs[i].t==3)
		{
			cin>>hs[i].c;
			for(int j=1;j<=hs[i].c;j++)
			{
				cin>>x;
				hs[i].g.push_back(x);
			}
		}
	}
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		cin>>f;
		zyx(f);
	}
	for(int i=1;i<=n;i++)
		cout<<a[i]<<" ";
	return 0;
}