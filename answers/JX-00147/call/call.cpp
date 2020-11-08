#include<bits/stdc++.h>
#define ll long long
#define mod 998244353
using namespace std;
int g[2010][110],c[2010],t[2010],p[2010],v[2010];
ll a[2010];
int n,m;
void doo(int x)
{
//	cout<<x<<endl;
	if(t[x]==1) a[p[x]]=(a[p[x]]+v[x])%mod;
	if(t[x]==2) for(int i=1;i<=n;i++) a[i]=(a[i]*v[x])%mod;
	if(t[x]==3) for(int i=1;i<=c[x];i++) doo(g[x][i]);
}
int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>t[i];
		if(t[i]==1) cin>>p[i]>>v[i];
		if(t[i]==2) cin>>v[i];
		if(t[i]==3)
		{
			cin>>c[i];
			for(int j=1;j<=c[i];j++) cin>>g[i][j];
		}
	}
	int q;
	cin>>q;
	for(int i=1;i<=q;i++) {int x;cin>>x;doo(x);}
	for(int i=1;i<=n;i++) printf("%lld ",a[i]);
	printf("\n");
	return 0;
}
