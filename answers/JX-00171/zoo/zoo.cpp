#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
using namespace std;
const int maxn=1000010,maxm=1000010;
int n,m,c,k;
long long ans;
int p[maxm],q[maxm],t[maxm];
long long  a[maxn];
bool list[70];
string op(long long a)
{
	string s="";
	while(a)
	{
		if(a%2==0)s="0"+s;
		else {s="1"+s;}
		a/=2;
	}
	while(s.size()<64)s="0"+s;
	return s;
}
bool vis[maxn];
int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	cin>>n>>m>>c>>k;
	for(int i=1;i<=n;i++)
	{scanf("%d",&a[i]);vis[a[i]]=true;}
	for(int i=1;i<=m;i++)
		scanf("%d%d",&p[i],&q[i]);
	for(int i=1;i<=n;i++)
	{
		string now=op(a[i]);
		for(int j=1;j<=m;j++)
			if(now[63-p[j]]=='1')list[q[j]]=true;
	}
	for(int i=1;i<=(1<<k);i++)
	{
		if(vis[i])continue;
			string now=op(i);
			bool f=true;
		for(int j=1;j<=m;j++)
		{
			if(now[p[j]]=='1'&&!list[q[j]]){f=false;break;}
		}
		if(f)ans++;
	}
	cout<<ans;
	return 0;
}