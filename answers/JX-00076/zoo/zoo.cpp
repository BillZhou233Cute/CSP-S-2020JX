#include <iostream>
#include <cstdio>
using namespace std;
int n,m,c,k;
int a[1000010],c1[1000010],ans,q[1000010],p[1000010];
int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	cin>>n>>m>>c>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++)
	{
		cin>>p[i]>>q[i];
		for(int j=1;j<=n;j++)
			if((a[j]>>p[i])&1)  c1[q[i]]=1;
	}
	for(int i=0;i<=(1<<k)-1;i++)
	{
		int flag=0;
		for(int j=1;j<=m;j++) if(((i>>p[j])&1)&&c1[q[j]]) {flag=1;break;}
		if(flag) ans++;
	}
	cout<<ans;
	return 0;
}