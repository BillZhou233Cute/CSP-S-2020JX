#include<bits/stdc++.h>
using namespace std;
#define R register
#define ll long long
inline int read()
{
	int x=0;bool f=0;char s=getchar();
	while(s>'9'||s<'0') {if(s=='-') f=1;s=getchar();}
	while(s>='0'&&s<='9') {x=(x<<1)+(x<<3)+s-'0';s=getchar();}
	return f?-x:x;
} 
const int N=4e5+10,M=998244353;
int n,a[N],m;
struct st
{
	int t,l,r,v;
	vector<int>q;
}c[N];
int cha[N],cheng;
void dfs(int x)
{
	if(c[x].t==1) cha[c[x].l]=(cha[c[x].l]+c[x].v)%M,cha[c[x].r+1]=(cha[c[x].r+1]-c[x].v)%M;
	if(c[x].t==2) cheng=cheng*c[x].v%M;
	if(c[x].t==3) 
	{
		for(R int i=0;i<c[x].q.size();i++)
			dfs(c[x].q[i]);
	}
}
int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	n=read();
	for(R int i=1;i<=n;i++) a[i]=read(),cha[i]=a[i]-a[i-1];
	m=read();
	for(R int i=1;i<=m;i++)
	{
		c[i].t=read();
		if(c[i].t==1)
			c[i].l=read(),c[i].r=read(),c[i].v=read();
		if(c[i].t==2) c[i].v=read();
		if(c[i].t==3)
		{
			int z;
			while(z>1)
			{
				int x=read();
				c[i].q.push_back(x);
			}
		}
	}
	int q=read();
	while(q--)
	{
		int x=read();
		dfs(x);
	}
	ll sum=0;
	for(R int i=1;i<=n;i++)
		a[i]=sum+cha[i],printf("%d ",a[i]*cheng%M);
	return 0;
}