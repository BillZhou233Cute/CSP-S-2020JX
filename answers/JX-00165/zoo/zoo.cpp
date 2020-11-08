#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
#define int unsigned long long

const int N=1e6+5;

inline int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
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

int n,m,c,k;
int a[N];
int vis[65];
bool flag[65];

signed main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	int t=1;
	for(int i=1;i<=63;i++) t*=2;
	t=(t-1)*2+1;
	//cout<<t+1<<endl;
	n=read(); m=read(); c=read(); k=read();
	for(int i=1;i<=n;i++) 
	{
		a[i]=read();
		for(int j=0;j<=k-1;j++)	
		{
			if((a[i]>>j)&1) vis[j]=true;
		}
	}
	int p,q;
	for(int i=1;i<=m;i++)
	{
		p=read(); q=read();
		flag[p]=true;
	}
	int cnt=0;
	for(int i=0;i<=k-1;i++)
		if(!flag[i]||(flag[i]&&vis[i])) cnt++;
	if(cnt==64)
	{
		if(!n) cout<<"18446744073709551616"<<endl;
		else cout<<t-n+1<<endl;
	}
	else
	{
		int ans=1;
		for(int i=1;i<=cnt;i++) ans*=2;
		cout<<ans-n<<endl;
	}
	return 0;
}
