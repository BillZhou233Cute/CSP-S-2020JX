#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1,mod=998244353;
int n,m,q;
long long f[N];
struct node{
	int p,v,c,op;
	vector<int> g; 
}a[N];
inline int read()
{
	int x=0,y=0,z=getchar();
	while(!isdigit(z)&&(y=z=='-',1))z=getchar();
	while(isdigit(z))x=(x<<3)+(x<<1)+(z^48),z=getchar();
	return y?-x:x;
}
void search(int x)
{
	int i;
	switch(a[x].op)
		{
			case 1:
				f[a[x].p]+=a[x].v;
				f[a[x].p]%=mod;
				break;
			case 2:
				for(i=1;i<=n;i++)
				{
					f[i]*=a[x].v;
					f[i]%=mod;
				}
				break;
			case 3:
				for(i=0;i<a[x].c;i++)search(a[x].g[i]);
				break;
		}
}
int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	int i,j;
	n=read();
	for(i=1;i<=n;i++)f[i]=read();
	m=read();
	for(i=1;i<=m;i++)
	{
		a[i].op=read();
		switch(a[i].op)
		{
			case 1:
				a[i].p=read(),a[i].v=read();
				break;
			case 2:
				a[i].v=read();
				break;
			case 3:
				a[i].c=read();
				for(j=1;j<=a[i].c;j++)a[i].g.push_back(read());
				break;
		}
	}
	q=read();
	for(i=1;i<=q;i++)search(read());
	for(i=1;i<=n;i++)printf("%lld ",f[i]);
	return 0;
}