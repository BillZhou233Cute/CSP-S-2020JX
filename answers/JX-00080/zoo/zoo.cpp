#include <bits/stdc++.h>
#define il inline
#define Max 1000005
#define ll long long
#define int ll
using namespace std;
il int read()
{
	char c=getchar();
	int x=0,f=1;
	while(c>'9'||c<'0')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,m,c,k,a[Max],p[Max],q[Max],t[Max],h[Max],d[Max],ans;
il void calc(int x)
{
	for(int i=0;i<k;i++) if((1<<i)&x) t[i]=1;
}
signed main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	n=read(),m=read(),c=read(),k=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=m;i++) p[i]=read(),q[i]=read(),d[p[i]]=1;
	for(int i=1;i<=n;i++) calc(a[i]);
	for(int i=0;i<k;i++)
	{
	//	cout<<d[i]<<' '<<t[i]<<endl;
		if(d[i]==0||t[i]) ans++;
	}
//	cout<<ans<<endl;
	printf("%lld\n",(1ll<<ans)-n);
	return 0;
}
