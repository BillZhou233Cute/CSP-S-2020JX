#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
long long a[100010],f[100010],mod=998244353,q,n,m;
int  fa[10000][1000],tail[100010],p[100010];
/*int find(int x)
{
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
	fa[find(x)]=fa[find(y)];
}*/
void slove(int qi)
{
	if(f[qi]==1) a[p[qi]] += fa[qi][p[qi]];
	else if(f[qi]==2)
	{
		for(int j=1;j<=n;j++) a[j]=(a[j]%mod*fa[qi][1])%mod;
	}
	else
	{
			for(int j=0;j<tail[qi];j++)
				slove(fa[qi][j]);
	}
	return;
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
		cin>>f[i];
		int cj=0;
		if(f[i]==1)
		{
			int pj,v;
			cin>>pj>>v;
			fa[i][pj]=v;
			p[i]=pj;
		}
		else if(f[i]==3){
			cin>>cj;
			for(int j=1;j<=cj;j++)
			{
				int gj=0;
				cin>>gj;
				fa[i][tail[i]]=gj;
				tail[i]++;
			}
		}
		else {
			int vj;
			cin>>vj;
			fa[i][1]=vj;
		}
	}
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		int qi;
		cin>>qi;
		slove(qi);
	}
	for(int i=1;i<=n;i++) cout<<a[i]<<" ";
	return 0;
}