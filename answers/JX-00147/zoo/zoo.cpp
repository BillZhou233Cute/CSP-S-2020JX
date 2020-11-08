#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<set>
#define ll long long
using namespace std;
ll read(){ll x;scanf("%lld",&x);return x;}
vector<int> g[70];
bool a[70];
set<int> s;
int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	int n=read(),m=read(),c=read(),k=read(),cnt=0;
	memset(a,false,sizeof(a));
	for(int i=1;i<=n;i++)
	{
		int x=read();
		for(int j=0;j<k;j++) if((x>>j)&1) a[j]=true;
	}
	for(int i=1;i<=m;i++)
	{
		int p=read(),q=read();
		g[p].push_back(q);
		if(a[i]) s.insert(q);
	}
	for(int t=1;t<=max(k*k,1500);t++)
	for(int i=0;i<k;i++)
	{
		bool ok=true;
		for(int j=0;j<g[i].size();j++)
		if(a[i]||s.find(g[i][j])==s.end())
		{
			ok=false;
			break;
		}
		if(ok)
		{
			a[i]=true;
			for(int j=0;j<g[i].size();j++) s.insert(g[i][j]);
		}
	}
	for(int i=0;i<k;i++) cnt+=a[i];
	unsigned ll ans=1;
	if(cnt==64)
	{
		for(int i=1;i<=cnt-1;i++) ans*=2;
		ans-=n;
		ans*=2;
		ans+=n;
	}
	else
	{
		for(int i=1;i<=cnt;i++) ans*=2;
		ans-=n;
	}
	cout<<ans<<endl;
	return 0;
}
