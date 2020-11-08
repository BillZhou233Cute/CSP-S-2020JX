#include<bits/stdc++.h>
#define modn 998244353
using namespace std;
int n,a[100005],m,T[100005],Q,f[100005],p[100005],v[100005],c[100005],head[100005],tot;
struct G
{
	int num;
	int next;
}g[1000005];
void mark(int nu);
void fun1(int numa,int nump)
{
	a[numa]+=a[nump];
	a[numa]%=modn;
}
void fun2(int numm)
{
	int i;
	for(i=1;i<=n;i++)
	{
		a[i]*=numm;
		a[i]%=modn;
	}
}
void fun3(int numma)
{
	int i;
	int too=head[numma];
	while(too!=-1)
	{
		mark(g[too].num);
		too=g[too].next;
	}
}
void mark(int nu)
{
	if(T[nu]==1) fun1(p[nu],v[nu]);
	else if(T[nu]==2) fun2(v[nu]);
	else if(T[nu]==3) fun3(nu);
}
int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	scanf("%d",&a[i]);
	scanf("%d",&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d",&T[i]);
		if(T[i]==1)
			scanf("%d%d",&p[i],&v[i]);
		else if(T[i]==2)
			scanf("%d",&v[i]);
		else if(T[i]==3)
		{
			scanf("%d",&c[i]);
			for(j=1;j<=c[i];j++)
			{
				int w;
				tot++;
				scanf("%d",&w);
				if(j==1)
				{
					head[i]=tot;
					g[tot].num=w;
				}
				else
				{
					g[tot].num=w;
					g[tot-1].next=tot;
				}
				if(j==c[i]) g[tot].next=-1;
			}
		}
	}
	scanf("%d",&Q);
	for(i=1;i<=Q;i++)
	scanf("%d",&f[i]);
	for(i=1;i<=Q;i++)
	mark(f[i]);
	for(i=1;i<=n;i++)
	printf("%d ",a[i]);
	printf("\n");
	return 0;
}