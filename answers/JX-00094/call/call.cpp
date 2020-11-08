#include <iostream>
#include <cstdio>
#define MOD 998244353
using namespace std;
const int N=1e4+10;
int n,a[N],m,q;
struct node{
	int ty;
	int p,c,v;
	int g[N];
}t[N];
int mul=1;

inline int read()
{
	int f=1,x=0;char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	 x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*f;
}

int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		t[i].ty=read();
		if(t[i].ty==1) t[i].p=read(),t[i].v=read();
		else if(t[i].ty==2) t[i].v=read();
		else if(t[i].ty==3)
		{
			t[i].c=read();
			for(int j=1;j<=t[i].c;j++) t[j].g[j]=read(); 
		}
	}
	q=read();
	int k;
	while(q--)
	{
		k=read();
		if(t[k].ty==1) a[t[k].p]+=t[k].v;
		if(t[k].ty==2) mul*=t[k].v%MOD;
		if(t[k].ty==3) 
		{
			for(int i=1;i<=t[k].c;i++)
			{
				int h=t[k].g[i];
				if(t[h].ty==1) a[t[h].p]+=t[h].v;
				if(t[h].ty==2) mul*=t[h].v%MOD;
			}
		}
	}
	for(int i=1;i<=n;i++) printf("%d ",a[i]*mul%MOD);
	return 0;
}
