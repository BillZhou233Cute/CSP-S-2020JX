#include<bits/stdc++.h>
using namespace std;
int mod=998244353;
int n,m,Q,tot,cnt,k,x,j,q;
int a[100010],ask[100010],p[100000010];
void hs(int l)
{
	if(l==1)
	{
		cin>>k>>x;
		a[k]+=x%mod;
	}
	else if(l==2)
	{
		cin>>x;
		for(int i=1;i<=n;i++) a[i]=a[i]*x%mod;
	}
	else
	{
		cin>>q;
		for(int i=1;i<=q;i++)
		{
			cin>>j;
			hs(ask[j]);
		}
	}
	p[++cnt]=l;
}
int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	cin>>m;
	while(m--)
	{
		cin>>ask[++tot];
		hs(ask[tot]);
	}
	cin>>Q;
	for(int i=1;i<=Q;i++) 
	{
		cin>>k;
		hs(p[k]);
	}
	for(int i=1;i<=n;i++) cout<<a[i]<<" ";
	return 0;
}